/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/21 14:49:45 by akuijer       #+#    #+#                 */
/*   Updated: 2024/09/06 15:17:52 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	ft_error(char *msg, mlx_t *mlx, int32_t val)
{
	ft_putstr_fd(RED_TEXT, STDERR_FILENO);
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(RESET, 2);
	if (mlx)
		mlx_terminate(mlx);
	exit(val);
}

void	ft_hook(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	get_user_input(cub3d->mlx, &(cub3d->map));
	render(*cub3d, cub3d->map, cub3d->img);
	display_fps(cub3d->mlx, "");
}

void	init(t_cub3d *cub3d, char *file_name)
{
	char	*err_msg;

	cub3d->mlx = mlx_init(SCR_WIDTH, SCR_HEIGHT, "cub3d", false);
	if (!cub3d->mlx)
	{
		ft_error("mlx_init failed\n", NULL, 1);
	}
	cub3d->img = mlx_new_image(cub3d->mlx, SCR_WIDTH, SCR_HEIGHT);
	if (!cub3d->img)
	{
		ft_error("mlx_new_image failed\n", cub3d->mlx, 1);
	}
	err_msg = parse_all(cub3d, open(file_name, O_RDONLY));
	if (err_msg)
	{
		ft_error(err_msg, cub3d->mlx, 1);
	}
	mlx_image_to_window(cub3d->mlx, cub3d->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc != 2 || ft_strlen(argv[1]) < 5
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 5))
	{
		ft_error("invalid input\n", NULL, 1);
	}
	init(&cub3d, argv[1]);
	mlx_loop_hook(cub3d.mlx, ft_hook, &cub3d);
	mlx_loop(cub3d.mlx);
	mlx_terminate(cub3d.mlx);
	free_2d(cub3d.map.grid);
	return (0);
}

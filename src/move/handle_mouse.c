/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_mouse.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 13:35:55 by akuijer       #+#    #+#                 */
/*   Updated: 2024/09/06 13:36:10 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	get_mouse_input(mlx_t *mlx, t_map *map)
{
	t_ivector2		pos;
	t_ivector2		window_pos;
	static bool		enable_mouse;
	static float	last_lock;

	if (last_lock + 0.25 < mlx_get_time() && mlx_is_key_down(mlx, MLX_KEY_TAB))
	{
		enable_mouse = !enable_mouse;
		last_lock = mlx_get_time();
		mlx_set_mouse_pos(mlx, SCR_WIDTH / 2, SCR_HEIGHT / 2);
		mlx_set_cursor_mode(mlx, MLX_MOUSE_NORMAL + enable_mouse);
	}
	if (!enable_mouse)
		return ;
	pos = (t_ivector2){0, 0};
	window_pos = (t_ivector2){0, 0};
	mlx_get_mouse_pos(mlx, &pos.x, &pos.y);
	mlx_set_mouse_pos(mlx, SCR_WIDTH / 2, SCR_HEIGHT / 2);
	mlx_get_window_pos(mlx, &window_pos.x, &window_pos.y);
	map->player_dir = shift_vector(map->player_dir, \
		((float)(pos.x) - (SCR_WIDTH / 2)) * SENSITIVITY);
}

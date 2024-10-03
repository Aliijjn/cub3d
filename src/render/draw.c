/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/30 13:18:44 by akuijer       #+#    #+#                 */
/*   Updated: 2024/09/06 15:08:05 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	display_fps(mlx_t *mlx, char *empty_str)
{
	static uint32_t		frames;
	static uint64_t		prev_time;
	static mlx_image_t	*image;
	uint64_t			time;

	frames++;
	time = mlx_get_time();
	if (prev_time == 0)
		prev_time = time;
	if (roundf(time) != roundf(prev_time))
	{
		empty_str = ft_itoa(frames);
		if (empty_str != NULL)
		{
			mlx_delete_image(mlx, image);
			image = mlx_put_string(mlx, empty_str, SCR_WIDTH - 45, 20);
			free(empty_str);
		}
		frames = 0;
	}
	prev_time = time;
}

uint32_t	get_pixel_from_texture(mlx_image_t *img, t_vector2 pos)
{
	uint8_t	*ptr;
	t_rgb	colour;

	ptr = &img->pixels[(((int)(pos.x * img->width) + \
		(int)(pos.y * img->height) * img->width) * 4)];
	colour.val[RED] = *(ptr);
	colour.val[GREEN] = *(ptr + 1);
	colour.val[BLUE] = *(ptr + 2);
	colour.val[ALPHA] = *(ptr + 3);
	return (colour.colour);
}

mlx_image_t	*get_wall_texture(t_cub3d cub3d, char direction)
{
	if (direction == 'N')
		return (cub3d.image.no);
	if (direction == 'E')
		return (cub3d.image.ea);
	if (direction == 'S')
		return (cub3d.image.so);
	return (cub3d.image.we);
}

void	draw_row(t_cub3d cub3d, mlx_image_t *img, t_ray_result ray, int x)
{
	int			i;
	int			tex_y;
	float		height;
	mlx_image_t	*wall_texture;

	i = 0;
	height = SCR_HEIGHT / ray.distance;
	if (height < 0)
		return ;
	while (i < (SCR_HEIGHT - height) / 2)
		mlx_put_pixel(img, x, i++, cub3d.image.c.colour);
	tex_y = 0;
	if (height > SCR_HEIGHT)
		tex_y = (height - SCR_HEIGHT) / 2;
	wall_texture = get_wall_texture(cub3d, ray.side);
	while (i < (SCR_HEIGHT + height) / 2 && i < SCR_HEIGHT)
	{
		mlx_put_pixel(img, x, i, get_pixel_from_texture(wall_texture, \
			(t_vector2){ray.index, (float)tex_y / height}));
		i++;
		tex_y++;
	}
	while (i < SCR_HEIGHT)
		mlx_put_pixel(img, x, i++, cub3d.image.f.colour);
}

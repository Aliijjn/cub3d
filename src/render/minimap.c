/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/02 15:09:52 by lbartels      #+#    #+#                 */
/*   Updated: 2024/09/06 14:48:45 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	draw_circle(mlx_image_t *img, t_ivector2 centre, \
					int32_t size, uint32_t colour)
{
	t_ivector2		i;
	t_ivector2		pos;

	pos = (t_ivector2){centre.x - size / 2, centre.y - size / 2};
	i.y = 0;
	while (i.y < size)
	{
		i.x = 0;
		while (i.x < size)
		{
			if (dot_product((t_vector2){i.x - (size / 2 - 0.5f), \
				i.y - (size / 2 - 0.5f)}, size / 2))
				mlx_put_pixel(img, pos.x + i.x, pos.y + i.y, colour);
			i.x++;
		}
		i.y++;
	}
}

void	draw_square(mlx_image_t *img, t_ivector2 pos, uint32_t colour)
{
	t_ivector2	i;

	i.y = 0;
	while (i.y < MM_BLOCK_SIZE - 1)
	{
		i.x = 0;
		while (i.x < MM_BLOCK_SIZE - 1)
		{
			if (dot_product((t_vector2){MM_MID - (pos.x + i.x), MM_MID \
				- (pos.y + i.y)}, (MM_DIAMETER - 1) * MM_BLOCK_SIZE))
				mlx_put_pixel(img, pos.x + i.x, pos.y + i.y, colour);
			i.x++;
		}
		i.y++;
	}
}

void	draw_player(mlx_image_t *img, t_vector2 player)
{
	t_ivector2	i;

	i.y = 0;
	while (i.y < MM_BLOCK_SIZE / 2)
	{
		i.x = 0;
		while (i.x < MM_BLOCK_SIZE / 2)
		{
			mlx_put_pixel(img, \
				(uint32_t)((player.x - 0.25f) * MM_BLOCK_SIZE + i.x), \
				(uint32_t)(((player.y - 0.25f) * MM_BLOCK_SIZE) + i.y), \
				0x00FF00FF);
			i.x++;
		}
		i.y++;
	}
}

void	draw_grid(t_cub3d cub3d, t_map map, t_ivector2 i, t_vector2 pos)
{
	uint32_t	colour;

	colour = 0xFFFFFFFF;
	if (pos.x < 0 || pos.y < 0 || pos.x >= map.size.x || pos.y >= map.size.y \
		|| map.grid[(int)pos.y][(int)pos.x] == ' ')
	{
		colour = 0x999999FF;
	}
	else if (map.grid[(int)pos.y][(int)pos.x] == '1')
	{
		colour = 0x000000FF;
	}
	draw_square(cub3d.img, (t_ivector2){
		(((float)i.x + 0.5f) - (map.player.x - (int)map.player.x)) \
		* MM_BLOCK_SIZE, \
		(((float)i.y + 0.5f) - (map.player.y - (int)map.player.y)) \
		* MM_BLOCK_SIZE}, colour);
}

void	draw_minimap(t_cub3d cub3d, t_map map)
{
	t_ivector2	i;
	t_vector2	pos;

	draw_circle(cub3d.img, (t_ivector2){176, 176}, MM_PX_DIA + 16, 0x888888FF);
	i = (t_ivector2){0, 0};
	pos.y = map.player.y - MM_DIAMETER;
	while (pos.y < map.player.y + MM_DIAMETER)
	{
		i.x = 0;
		pos.x = map.player.x - MM_DIAMETER;
		while (pos.x < map.player.x + MM_DIAMETER)
		{
			draw_grid(cub3d, map, i, pos);
			pos.x++;
			i.x++;
		}
		pos.y++;
		i.y++;
	}
	draw_circle(cub3d.img, (t_ivector2){176, 176}, MM_PLAYER, 0xAA00DDFF);
	draw_circle(cub3d.img, (t_ivector2){
		MM_MID + cub3d.map.player_dir.x * MM_BLOCK_SIZE / 3.3, \
		MM_MID + cub3d.map.player_dir.y * MM_BLOCK_SIZE / 3.3}, \
		MM_PLAYER / 2, 0xAA00DDFF);
}

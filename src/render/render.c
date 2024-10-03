/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/26 11:45:00 by akuijer       #+#    #+#                 */
/*   Updated: 2024/09/06 13:29:45 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	cast_ray_init(t_vector2 start, t_vector2 ray, t_ray_cast *r)
{
	r->map_pos.x = (int)start.x;
	r->map_pos.y = (int)start.y;
	r->delta_dist.x = fabs(1 / ray.x) + (1 << 30) * ((int)(ray.x == 0));
	r->delta_dist.y = fabs(1 / ray.y) + (1 << 30) * ((int)(ray.y == 0));
	if (ray.x < 0)
	{
		r->step_dist.x = -1;
		r->side_dist.x = (start.x - r->map_pos.x) * r->delta_dist.x;
	}
	else
	{
		r->step_dist.x = 1;
		r->side_dist.x = (r->map_pos.x + 1 - start.x) * r->delta_dist.x;
	}
	if (ray.y < 0)
	{
		r->step_dist.y = -1;
		r->side_dist.y = (start.y - r->map_pos.y) * r->delta_dist.y;
	}
	else
	{
		r->step_dist.y = 1;
		r->side_dist.y = (r->map_pos.y + 1 - start.y) * r->delta_dist.y;
	}
}

static t_ray_result	ray_cast(t_vector2 start, t_vector2 ray, \
					t_map map, t_ray_cast r)
{
	while (1)
	{
		if (r.side_dist.x < r.side_dist.y)
		{
			r.side_dist.x += r.delta_dist.x;
			r.map_pos.x += r.step_dist.x;
			r.side = (r.step_dist.x >= 0) * 'W' + (r.step_dist.x < 0) * 'E';
		}
		else
		{
			r.side_dist.y += r.delta_dist.y;
			r.map_pos.y += r.step_dist.y;
			r.side = (r.step_dist.y >= 0) * 'N' + (r.step_dist.y < 0) * 'S';
		}
		if (map.grid[r.map_pos.y][r.map_pos.x] == '1')
			break ;
	}
	if (r.side == 'E' || r.side == 'W')
		return ((t_ray_result){r.side_dist.x - r.delta_dist.x, r.side, \
			(start.y + (r.side_dist.x - r.delta_dist.x) * ray.y) - \
			(int)(start.y + (r.side_dist.x - r.delta_dist.x) * ray.y)});
	return ((t_ray_result){r.side_dist.y - r.delta_dist.y, r.side, \
		(start.x + (r.side_dist.y - r.delta_dist.y) * ray.x) - \
		(int)(start.x + (r.side_dist.y - r.delta_dist.y) * ray.x)});
}

t_ray_result	cast_ray(t_vector2 start, t_vector2 ray, t_map map)
{
	t_ray_cast	r;

	cast_ray_init(start, ray, &r);
	return (ray_cast(start, ray, map, r));
}

t_vector2	init_ray(t_vector2 ray, int ray_count)
{
	t_vector2	ray_perpend;
	t_vector2	ray_window_width;
	t_vector2	result;

	ray_perpend = (t_vector2){ray.x + ray.y, ray.y - ray.x};
	ray_window_width = (t_vector2){-ray.y * 2, ray.x * 2};
	result.x = (ray_perpend.x + ray_window_width.x * ray_count / SCR_WIDTH);
	result.y = (ray_perpend.y + ray_window_width.y * ray_count / SCR_WIDTH);
	return (result);
}

void	render(t_cub3d cub3d, t_map map, mlx_image_t *img)
{
	int				x;
	t_ray_result	result_ray;

	x = 0;
	while (x < SCR_WIDTH)
	{
		result_ray = cast_ray(map.player, init_ray(map.player_dir, x), map);
		draw_row(cub3d, img, result_ray, x);
		x++;
	}
	if (SCR_WIDTH > 600 && SCR_HEIGHT > 600)
		draw_minimap(cub3d, cub3d.map);
}

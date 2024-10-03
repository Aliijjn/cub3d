/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 16:11:07 by akuijer       #+#    #+#                 */
/*   Updated: 2024/09/06 13:35:42 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

bool	can_move(t_map *map, t_vector2 pos)
{
	return (map->grid[(int)(pos.y)][(int)(pos.x)] != '1');
}

// catches a bug when a player is able to phase trough blocks in this shape:
//01
//10
bool	catch_1001(t_map *map, t_vector2 new, t_vector2 old)
{
	return (((int)new.x != (int)old.x && (int)new.y != (int)old.y) \
		&& !can_move(map, (t_vector2){new.x, old.y}) \
		&& !can_move(map, (t_vector2){old.x, new.y}));
}

t_vector2	get_collision_check_var(t_map *map, t_vector2 dir)
{
	t_vector2	result;

	result = copy_vec2(map->player);
	if (dir.x > 0)
		result.x += COLLISION_CHECK;
	else
		result.x -= COLLISION_CHECK;
	if (dir.y > 0)
		result.y += COLLISION_CHECK;
	else
		result.y -= COLLISION_CHECK;
	return (result);
}

void	check_move(mlx_t *mlx, t_map *map, t_vector2 dir)
{
	float		move_speed;
	t_vector2	new_pos;
	t_vector2	coll_check;

	dir = normalize_vector(dir);
	move_speed = MOVE_SPEED * (1 + mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT));
	new_pos = (t_vector2){map->player.x + dir.x * move_speed, \
		map->player.y + dir.y * move_speed};
	coll_check = get_collision_check_var(map, dir);
	if (catch_1001(map, coll_check, map->player))
		return ;
	if (can_move(map, coll_check) && can_move(map, new_pos))
	{
		map->player.x = new_pos.x;
		map->player.y = new_pos.y;
	}
	else if (can_move(map, (t_vector2){coll_check.x, map->player.y}))
	{
		map->player.x = new_pos.x;
	}
	else if (can_move(map, (t_vector2){map->player.x, coll_check.y}))
	{
		map->player.y = new_pos.y;
	}
}

void	get_user_input(mlx_t *mlx, t_map *map)
{
	t_vector2	move;
	t_vector2	dir;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	move = (t_vector2){0, 0};
	dir = (t_vector2){map->player_dir.x, map->player_dir.y};
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		move = (t_vector2){move.x + dir.y, move.y - dir.x};
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		move = (t_vector2){move.x - dir.y, move.y + dir.x};
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		move = (t_vector2){move.x + dir.x, move.y + dir.y};
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		move = (t_vector2){move.x - dir.x, move.y - dir.y};
	if (move.x && move.y)
		move = (t_vector2){move.x / sqrtf(2), move.y / sqrtf(2)};
	if (move.x || move.y)
		check_move(mlx, map, move);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		map->player_dir = shift_vector(map->player_dir, -ROTATE_SPEED);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		map->player_dir = shift_vector(map->player_dir, ROTATE_SPEED);
	get_mouse_input(mlx, map);
}

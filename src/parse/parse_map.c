/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/21 14:49:17 by lbartels      #+#    #+#                 */
/*   Updated: 2024/09/06 17:12:45 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

bool	get_player(char c, t_map *map, t_ivector2 i)
{
	if (map->player.x != -1)
		return (false);
	if (c == 'N')
		map->player_dir = (t_vector2){0, -1};
	else if (c == 'E')
		map->player_dir = (t_vector2){1, 0};
	else if (c == 'S')
		map->player_dir = (t_vector2){0, 1};
	else if (c == 'W')
		map->player_dir = (t_vector2){-1, 0};
	map->player = (t_vector2){i.x + 0.5f, i.y + 0.5f};
	map->grid[i.y][i.x] = '0';
	return (true);
}

char	*check_map(t_map *map)
{
	t_ivector2	i;

	i.y = 0;
	while (map->grid[i.y])
	{
		i.x = 0;
		while (map->grid[i.y][i.x])
		{
			if ((map->grid[i.y][i.x] == 'N' || map->grid[i.y][i.x] == 'E'
					|| map->grid[i.y][i.x] == 'S' || map->grid[i.y][i.x] == 'W')
					&& !get_player(map->grid[i.y][i.x], map, i))
				return ("multiple players\n");
			if (map->grid[i.y][i.x] == '0' && check_if_wall(map->grid, i))
				return ("map not fully surrounded by walls\n");
			else if (map->grid[i.y][i.x] != '0' && map->grid[i.y][i.x] != '1'
						&& map->grid[i.y][i.x] != ' ')
				return ("unexpexted token in map\n");
			i.x++;
		}
		i.y++;
	}
	if (map->player.x == -1)
		return ("no player position in map\n");
	return (NULL);
}

bool	check_multiple_nl_in_map(char *str)
{
	int32_t	i;

	i = 0;
	while (str[i])
	{
		if (i && str[i - 1] == '\n')
		{
			skip_spaces(&str);
			if (str[i] == '1' || str[i] == '0')
				break ;
		}
		i++;
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			while (str[i] == '\n')
				i++;
			if (str[i])
				return (false);
		}
		i++;
	}
	return (true);
}

void	count_mapsize(char **full_file, int32_t index, t_ivector2 *size)
{
	int32_t	x;
	int32_t	y;
	int32_t	temp;

	y = 0;
	x = 0;
	while (full_file[y + index])
	{
		temp = ft_strlen(full_file[y + index]);
		if (temp > x)
			x = temp;
		y++;
	}
	*size = (t_ivector2){x, y};
}

char	*parse_map(char **full_file, int32_t index, t_map *map)
{
	t_ivector2	i;

	i.y = 0;
	count_mapsize(full_file, index, &map->size);
	map->grid = ft_calloc(map->size.y + 1, sizeof(char *));
	if (!map->grid)
		return ("malloc error\n");
	while (full_file[index + i.y])
	{
		i.x = 0;
		map->grid[i.y] = ft_calloc(map->size.x + 1, sizeof(char));
		if (!map->grid[i.y])
			return (free_2d(map->grid), "malloc error\n");
		while (i.x < map->size.x)
		{
			if (i.x < (int32_t)ft_strlen(full_file[index + i.y]))
				map->grid[i.y][i.x] = full_file[index + i.y][i.x];
			else
				map->grid[i.y][i.x] = ' ';
			i.x++;
		}
		i.y++;
	}
	map->player = (t_vector2){-1, -1};
	return (check_map(map));
}

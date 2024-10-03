/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/21 14:54:40 by lbartels      #+#    #+#                 */
/*   Updated: 2024/09/06 15:10:10 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

char	*get_rgb(char *line, t_rgb *cf)
{
	int32_t	i;
	int32_t	temp;

	if (cf->val[ALPHA] == 0xFF)
		return ("multiple declarations of C or F\n");
	i = RED;
	line++;
	skip_spaces(&line);
	while (i != ALPHA)
	{
		temp = ft_atoi(line);
		if (temp > 255 || temp < 0 || (temp == 0 && *line != '0'))
			return ("rgb value not between 0 - 255\n");
		cf->val[i] = ft_atoi(line);
		while (*line && ft_isdigit(*line))
			line++;
		if (*line == ',')
			line++;
		else if (*line)
			return ("non numerical value in rgb\n");
		i--;
	}
	cf->val[ALPHA] = 0xFF;
	return (NULL);
}

char	*get_texture(char *line, t_cub3d *cub3d, mlx_image_t **image)
{
	char			*temp;
	mlx_texture_t	*texture;

	if (*image)
		return ("multiple declarations of texture\n");
	line += 2;
	skip_spaces(&line);
	temp = ft_substr(ft_strchr(line, '.'), 0, \
		ft_strchr(ft_strchr(line, '.'), ' ') - ft_strchr(line, '.'));
	if (!temp)
	{
		return ("malloc error\n");
	}
	texture = mlx_load_png(temp);
	if (!texture)
		return (free(temp), "not a valid path\n");
	*image = mlx_texture_to_image(cub3d->mlx, texture);
	mlx_delete_texture(texture);
	free(temp);
	return (NULL);
}

char	*check_textures(t_cub3d cub3d)
{
	if (!(cub3d.image.no && cub3d.image.so && cub3d.image.we \
		&& cub3d.image.ea && cub3d.image.c.val[ALPHA] == 0xFF \
		&& cub3d.image.f.val[ALPHA] == 0xFF))
		return ("couldn't get textures/rgb\n");
	return (NULL);
}

char	*parse_textures(char **full_file, t_cub3d *cub3d, int32_t *index)
{
	char	*err_msg;

	*index = 0;
	while (full_file[*index] && !ft_isdigit(full_file[*index][0]))
	{
		skip_spaces(&full_file[*index]);
		if (!ft_strncmp(full_file[*index], "NO ", 3))
			err_msg = get_texture(full_file[*index], cub3d, &cub3d->image.no);
		else if (!ft_strncmp(full_file[*index], "SO ", 3))
			err_msg = get_texture(full_file[*index], cub3d, &cub3d->image.so);
		else if (!ft_strncmp(full_file[*index], "WE ", 3))
			err_msg = get_texture(full_file[*index], cub3d, &cub3d->image.we);
		else if (!ft_strncmp(full_file[*index], "EA ", 3))
			err_msg = get_texture(full_file[*index], cub3d, &cub3d->image.ea);
		else if (!ft_strncmp(full_file[*index], "F ", 2))
			err_msg = get_rgb(full_file[*index], &cub3d->image.f);
		else if (!ft_strncmp(full_file[*index], "C ", 2))
			err_msg = get_rgb(full_file[*index], &cub3d->image.c);
		else
			return ("unexpected token\n");
		if (err_msg)
			return (err_msg);
		(*index)++;
	}
	return (check_textures(*cub3d));
}

char	*parse_all(t_cub3d *cub3d, int32_t fd)
{
	char	*full_file;
	char	**grid;
	int32_t	index;
	char	*err_msg;

	if (fd == -1)
		return ("file does not exist\n");
	full_file = read_file(fd);
	close(fd);
	if (!full_file)
		return ("reading file\n");
	if (!check_multiple_nl_in_map(full_file))
		return (free(full_file), "multiple new lines in map\n");
	grid = ft_split(full_file, '\n');
	free(full_file);
	if (!grid)
		return ("split failed\n");
	cub3d->image = (t_image){.no = NULL, .ea = NULL, .so = NULL, .we = NULL};
	err_msg = parse_textures(grid, cub3d, &index);
	if (err_msg)
		return (free_2d(grid), err_msg);
	err_msg = parse_map(grid, index, &cub3d->map);
	if (err_msg)
		free_2d(cub3d->map.grid);
	return (free_2d(grid), err_msg);
}

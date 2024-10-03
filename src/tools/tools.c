/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tools.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/21 15:15:30 by lbartels      #+#    #+#                 */
/*   Updated: 2024/09/06 14:50:09 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	skip_spaces(char **line)
{
	int	i;

	i = 0;
	while ((*line)[i] && (*line)[i] == ' ')
		(*line)++;
}

char	*str_join(char *dest, char *src)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = ft_calloc(ft_strlen(dest) + ft_strlen(src) + 1, sizeof(char));
	if (!new_str)
		return (free(dest), free(src), NULL);
	i = 0;
	while (dest[i])
	{
		new_str[i] = dest[i];
		i++;
	}
	j = 0;
	while (src[j])
	{
		new_str[i + j] = src[j];
		j++;
	}
	free(dest);
	new_str[i + j] = '\0';
	return (new_str);
}

void	free_2d(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*read_file(int fd)
{
	int		bytes_read;
	char	*buffer;
	char	*str;

	buffer = ft_calloc(2, sizeof(char));
	str = ft_calloc(2, sizeof(char));
	if (!buffer | !str)
		return (free(buffer), free(str), NULL);
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read == -1)
			return (free(str), free(buffer), NULL);
		buffer[1] = '\0';
		if (bytes_read)
			str = str_join(str, buffer);
		if (!str)
			return (NULL);
	}
	free(buffer);
	return (str);
}

bool	check_if_wall(char **map, t_ivector2 i)
{
	return (!i.y || map[i.y - 1][i.x] == ' '
			|| !i.x || map[i.y][i.x - 1] == ' '
			|| !map[i.y + 1] || map[i.y + 1][i.x] == ' '
			|| !map[i.y][i.x + 1] || map[i.y][i.x + 1] == ' ');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 15:20:57 by akuijer       #+#    #+#                 */
/*   Updated: 2024/02/06 12:35:48 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_realloc(char *ptr_in, int size, int add)
{
	char	*ptr_out;
	int		i;

	i = 0;
	ptr_out = ft_calloc(size + add, 1);
	if (!ptr_out)
	{
		return (NULL);
	}
	while (i < size && i < size + add)
	{
		*(ptr_out + i) = *(ptr_in + i);
		i++;
	}
	free(ptr_in);
	return (ptr_out);
}

static void	*free_all(char **remain, char **buffer)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	if (remain && *remain)
	{
		free(*remain);
		*remain = NULL;
	}
	return (NULL);
}

static char	*loop(int fd, char *buffer, char *remain)
{
	int	read_result;

	if (!buffer[0])
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result <= 0)
			return (free_all(&remain, &buffer));
	}
	while (!ft_strchr(buffer, '\n'))
	{
		buffer = ft_realloc(buffer,
				(int)ft_strlen(buffer) + 1, BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		read_result = read(fd, buffer + ft_strlen(buffer), BUFFER_SIZE);
		if (!read_result)
			return (buffer);
		if (read_result < 0)
			return (NULL);
	}
	return (buffer);
}

static char	*get_extra(char *buffer)
{
	int		string_len;
	int		result_len;
	char	*result;

	if (!ft_strchr(buffer, '\n'))
	{
		return (NULL);
	}
	string_len = ft_strchr(buffer, '\n') + 1 - buffer;
	result_len = ft_strlen(buffer + string_len);
	result = ft_calloc(result_len + 1, sizeof(char));
	if (!result)
	{
		return (NULL);
	}
	while (--result_len >= 0)
	{
		result[result_len] = buffer[string_len + result_len];
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remain;

	if (fd < 0 || fd == 2 || BUFFER_SIZE <= 0)
		return (free_all(&remain, 0));
	if (remain)
		buffer = ft_realloc(remain, ft_strlen(remain) + 1, 0);
	else
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free_all(&remain, 0));
	buffer = loop(fd, buffer, remain);
	if (!buffer)
		return (free_all(&remain, 0));
	remain = get_extra(buffer);
	if ((!ft_strchr(buffer, '\n') && remain) || (remain && !remain[0]))
		free_all(&remain, 0);
	else
		buffer = ft_realloc(buffer, ft_strclen(buffer, '\n') + 1, 1);
	return (buffer);
}

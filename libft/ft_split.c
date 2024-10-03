/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 15:24:31 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/26 15:47:20 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_stringptr_length(const char *s, char c, int i)
{
	int		count;

	count = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i])
		{
			count++;
		}
		while (s[i] != c && s[i])
		{
			i++;
		}
	}
	return (count);
}

static int	get_len(const char *s, char c, int i)
{
	int	start_i;

	while (s[i] && s[i] == c)
	{
		i++;
	}
	start_i = i;
	while (s[i])
	{
		if (s[i] == c)
		{
			break ;
		}
		i++;
	}
	return (i - start_i);
}

static void	fill_string(const char *str_in, char *str_out, char c, int *i)
{
	int	j;

	j = 0;
	while (str_in[*i] && str_in[*i] == c)
	{
		(*i)++;
	}
	while (str_in[*i])
	{
		if (str_in[*i] == c)
		{
			break ;
		}
		str_out[j] = str_in[*i];
		(*i)++;
		j++;
	}
}

char	**free_all(char **failed_array, int length)
{
	while (length)
	{
		free(failed_array[length - 1]);
		length--;
	}
	free(failed_array);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	int		str_count;
	int		i;
	int		j;
	char	**str_array;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	str_count = get_stringptr_length(s, c, 0);
	str_array = (char **)ft_calloc(str_count + 1, sizeof(char *));
	if (!str_array)
		return (0);
	while (s[i] && j < str_count)
	{
		str_array[j] = (char *)ft_calloc(get_len(s, c, i) + 1, sizeof(char));
		if (!str_array[j])
			return (free_all(str_array, j));
		fill_string(s, str_array[j], c, &i);
		j++;
	}
	return (str_array);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// }

// int	count_segments(const char *s, char c)
// {
// 	int	count;
// 	int	i;

// 	count = 0;
// 	i = 0;
// 	if (s[i])
// 	{
// 		count = 1;
// 	}
// 	while (s[i])
// 	{
// 		if (s[i] == c && s[i - 1] != c)
// 		{
// 			count++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }

// int get_len(const char *s, char c, int len)
// {
// 	int start_len;

// 	start_len = len;
// 	while (s[len] && s[len] != c)
// 	{
// 		len++;
// 	}
// 	return (len - start_len);
// }

// void	free_all(char **ptr, int count)
// {
// 	while (count >= 0)
// 	{
// 		free(ptr[count]);
// 		count--;
// 	}
// 	free(ptr);
// }

// char	**ft_split(const char *s, char c)
// {
// 	char	*new_str;
// 	int		ptr_count;
// 	char	**result;
// 	int		ptr_i;
// 	int		src_i;
// 	int 	dst_len;

// 	ptr_i = 0;
// 	src_i = 0;
// 	new_str = ft_strtrim(s, c);
// 	ptr_count = count_segments(s, c);
// 	result = (char **)ft_calloc(ptr_count + 1, sizeof(char **));
// 	if (!result)
// 	{
// 		return (0);
// 	}
// 	while (ptr_i < ptr_count)
// 	{
// 		dst_len = get_len(s, c, src_i);
// 		result[ptr_i] = calloc(dst_len + 1, sizeof(char));
// 		if (!result[ptr_i])
// 		{
// 			free_all(result, ptr_i);
// 			free(new_str);
// 			return (0);
// 		}
// 		strlcpy(result[ptr_i], s + src_i, dst_len + 1);
// 		src_i += dst_len + 1;
// 		ptr_i++;
// 	}
// 	free(new_str);
// 	return (result);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 17:28:02 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/27 11:55:26 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i])
	{
		i++;
	}
	while ((i + j + 1) < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}

//not fully sure of all edge-cases work

// #include <bsd/string.h>
// #include <stdio.h>

// int main(void)
// {
// 	char str1[12] = "Hi Mom!", str2[12] = "Hi Mom!";
// 	printf("%zu\n", ft_strlcat(str1, " aaaa", 15));
// 	printf("%zu\n", strlcat(str2, " aaaa", 15));
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// }
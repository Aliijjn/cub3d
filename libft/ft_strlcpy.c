/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 15:33:48 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/13 16:43:44 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (dst[i] && size > 0)
	{
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// int main(void)
// {
// 	char str1[] = "Hi Mom!", str2[] = "Hi Mom!";
// 	printf("%i\n", ft_strlcpy(str1, "aaaa", 4));
// 	printf("%i\n", strlcpy(str1, "aaaa", 4));
// 	printf("%s\n", str1);
// 	printf("%s\n", str2);
// }
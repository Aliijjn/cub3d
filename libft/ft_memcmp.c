/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 19:02:06 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/27 12:14:38 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
	{
		return (0);
	}
	while (i < n - 1)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

// int main(void)
// {
// 	char str1[] = "abcAB";
// 	char str2[] = "abcABc";

// 	printf("%i\n", ft_memcmp(str1, str2, 5));
// 	printf("%i\n", memcmp(str1, str2, 5));
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:56:42 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/13 13:36:44 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
		{
			return ((void *)s + i);
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char str[] = {0, 1, 2 ,3 ,4 ,5};

// 	printf("%s\n", (char*)ft_memchr(str, 0, 0));
// 	printf("%s\n", (char*)memchr(str, c, 19));
// }
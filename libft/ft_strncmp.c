/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:37:49 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/27 12:20:38 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
	{
		return (0);
	}
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
		{
			break ;
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int main(void)
// {
// 	char str1[] = "abcAB";
// 	char str2[] = "abcABc";

// 	printf("%i\n", ft_strncmp(str1, str2, 6));
// 	printf("%i\n", strncmp(str1, str2, 6));
// }
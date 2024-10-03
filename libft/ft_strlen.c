/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 15:11:13 by akuijer       #+#    #+#                 */
/*   Updated: 2024/03/21 14:26:49 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	for (int i = 0; i < 128; i++)
// 	{
// 		char *str = (char*)calloc(i + 1, sizeof(char));
// 		for (int j = i; j < i; j++)
// 		{
// 			str[j] = 'a';
// 		}
// 		if (ft_strlen(str) != strlen(str))
// 		{
// 			printf("ERROR at length %i", i);
// 			printf("%u", ft_strlen(str));
// 			printf("%lu", strlen(str));
// 			continue;
// 		}
// 		printf("ok ");
// 	}
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 15:20:59 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/27 12:16:36 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = c;
		i++;
	}
	return ((void *) str);
}

// int	main(void)
// {
// 	#define TEST_STRING "Hi Mom!"
// 	#define MEMSET_LENGTH 5	
// 	char str1[] = TEST_STRING;
// 	char str2[] = TEST_STRING;
// 	ft_memset(str1, 0, MEMSET_LENGTH);
// 	memset(str2, 0, MEMSET_LENGTH);
// 	for (int i = 0; i < (int)sizeof(str1); i++)
// 	{
// 		if (str1[i] != str2[i])
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%c\n", str1[i]);
// 			printf("%c\n", str2[i]);
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }
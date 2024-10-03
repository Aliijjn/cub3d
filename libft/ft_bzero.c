/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:26:24 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/23 13:54:32 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	while (n--)
	{
		((char *)str)[n] = 0;
	}
}

// int	main(void)
// {
// 	#define TEST_STRING "Hi Mom!"
// 	#define MEMSET_LENGTH 5
// 	char str1[] = TEST_STRING;
// 	char str2[] = TEST_STRING;
// 	ft_bzero(str1, MEMSET_LENGTH);
// 	bzero(str2, MEMSET_LENGTH);
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
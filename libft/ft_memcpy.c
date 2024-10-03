/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:37:29 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/27 12:15:33 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
	{
		return (0);
	}
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	#define TEST_ARR { 1, 2, 3, 4, 5, 6 }
// 	#define MEMSET_LENGTH 4
// 	int	arr1[] = TEST_ARR;
// 	int	arr2[] = TEST_ARR;
// 	ft_memcpy(arr1, "aaaa",MEMSET_LENGTH);
// 	memcpy(arr2, "aaaa",MEMSET_LENGTH);
// 	for (int i = 0; i < (int)sizeof(arr1) / (int)sizeof(int); i++)
// 	{
// 		if (arr1[i] != arr2[i])
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%c\n", arr1[i]);
// 			printf("%c\n", arr2[i]);
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }
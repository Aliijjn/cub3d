/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:10:17 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/27 12:05:48 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 0;
		size = 0;
	}
	if (nmemb && (size * nmemb) / nmemb != size)
	{
		return (0);
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
	{
		return (0);
	}
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// int main(void)
// {
// 	#define CALLOC_LENGTH 0
// 	#define CALLOC_SIZE (int)sizeof(int)
// 	void *ptr1 = ft_calloc(CALLOC_LENGTH, CALLOC_SIZE);
// 	void *ptr2 = calloc(CALLOC_LENGTH, CALLOC_SIZE);
// 	for (int i = 0; i < CALLOC_LENGTH * CALLOC_SIZE; i++)
// 	{
// 		if (((char*)ptr1)[i] != ((char*)ptr2)[i])
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%c\n", ((char*)ptr1)[i]);
// 			printf("%c\n", ((char*)ptr2)[i]);
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// 	printf("\n%p\n", ptr1);
// 	printf("%p\n", ptr2);
// }
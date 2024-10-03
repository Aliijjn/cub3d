/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 17:08:15 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/26 14:20:39 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (0);
	if (s > d)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (dest);
	}
	while (n)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (dest);
}

// int	main(void)

// 	#define MEMSET_LENGTH 4
// 	char str1[] = "1234567890";
// 	char str2[] = "1234567890";
// 	ft_memmove(str1, "7777",MEMSET_LENGTH);
// 	memmove(str2, "7777",MEMSET_LENGTH);
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
// 	printf("\n%s", str1);
// 	printf("\n%s", str2);
// }
// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
// 	printf("%s\n", (char *)ft_memmove(sResult, sResult + 1, 2));
// 	printf("%s\n", (char *)memmove(sResult, sResult + 1, 2));
// }
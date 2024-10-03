/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:40:32 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/24 12:08:10 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*s2;

	i = 0;
	len = ft_strlen(s);
	s2 = (char *)malloc(len + 1);
	if (!s2)
	{
		return (0);
	}
	while (i < len)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

// int	main(void)
// {
// 	#define STRING "Hi Mom!"
// 	char *str1 = ft_strdup(STRING);
// 	char *str2 = strdup(STRING);
// 	for (int i = 0; i < 8; i++)
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
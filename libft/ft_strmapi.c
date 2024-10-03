/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 15:32:57 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/20 16:01:27 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	xor(unsigned int i, char c)
// {
// 	return (c ^= (char)i);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	if (!s || !f)
	{
		return (0);
	}
	s2 = (char *)malloc(ft_strlen(s) + 1);
	if (!s2)
	{
		return (0);
	}
	while (s[i])
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

// int main(void)
// {
// 	char str1[] = "XOR encryption go brrrr!";
// 	printf("%s\n", ft_strmapi(str1, xor));
// 	printf("%s\n", ft_strmapi(ft_strmapi(str1, xor), xor));
// }
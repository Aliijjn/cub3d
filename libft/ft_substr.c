/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:05:16 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/26 14:16:13 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(s);
	if ((long)(str_len - start) < 0)
	{
		len = 0;
	}
	else if (str_len - start < len)
	{
		len = str_len - start;
	}
	s2 = (char *)ft_calloc(len + 1, sizeof(char));
	if (!s2)
	{
		return (0);
	}
	while (i < len)
	{
		s2[i] = s[i + start];
		i++;
	}
	return (s2);
}

// int main(void)
// {
// 	#define STRING "On the corner there's a banker with a motorcar."
// 	printf("%s\n", ft_substr(STRING, 14, 32));
// }
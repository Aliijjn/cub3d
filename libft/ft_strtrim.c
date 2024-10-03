/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:35:32 by akuijer       #+#    #+#                 */
/*   Updated: 2024/03/21 14:16:18 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		j;
	int		count;
	char	*s2;

	i = 0;
	j = 0;
	count = ft_strlen(s1);
	while (check_set(s1[count - 1], set) && count)
		count--;
	while (count && check_set(s1[i], set))
	{
		i++;
		count--;
	}
	s2 = (char *)ft_calloc(count + 1, sizeof(char));
	if (!s2)
		return (0);
	while (j < count)
		s2[j++] = s1[i++];
	return (s2);
}

// int main(void)
// {
// 	printf("%s\n", ft_strtrim("Hi mom!", "aioue."));
// }
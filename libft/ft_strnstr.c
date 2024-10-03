/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 19:08:31 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/26 14:29:28 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char *big, const char *little, int remaining_len)
{
	int	i;

	i = 0;
	while (little[i])
	{
		if (big[i] != little[i])
		{
			return (0);
		}
		i++;
	}
	if (remaining_len >= i || remaining_len < 0)
	{
		return (1);
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!little[0])
	{
		return ((char *)big);
	}
	while (big[i] && (i < len || (long)len < 0))
	{
		if (check(big + i, little, len - i) == 1)
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char str[] = "abcdefghij023401256789";
// 	char str2[] = "";

// 	printf("%s\n", ft_strnstr(str, str2, 18));
// 	//printf("%s\n", strnstr(str, c, 18));
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:35:57 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/13 14:46:41 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			j = i;
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		j = i;
	}
	if (j >= 0)
	{
		return ((char *)s + j);
	}
	return (0);
}

// int main(void)
// {
// 	char str[] = "abcdef0ghij01234567890";
// 	int c = '0';

// 	printf("%s\n", ft_strrchr(str, c));
// 	printf("%s\n", strrchr(str, c));
// }
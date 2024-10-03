/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:00:29 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/25 12:18:09 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)s + i);
	}
	return (0);
}

// int main(void)
// {
// 	char str[] = "abcdefghij0123456789";
// 	int c = '0';

// 	printf("%s\n", ft_strchr(str, c));
// 	printf("%s\n", strchr(str, c));
// }
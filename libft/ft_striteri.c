/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 12:10:30 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/12 15:53:52 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// static void	capitalise(unsigned int i, char *s)
// {
// 	if (i == 0 && s[i] >= 'a' && s[i] <= 'z')
// 	{
// 		s[i] -= 32;
// 	}
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// int	main(void)
// {
// 	char str[] = "this isn't capitalised :0";
// 	ft_striteri(str, capitalise);
// 	printf("%s\n", str);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 17:55:19 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/12 15:53:56 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

// int	main(void)
// {
// 	for (int i = 0; i < 256; i++)
// 	{
// 		if (ft_toupper(i) != toupper(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_toupper(i));
// 			printf("%i\n", toupper(i));
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }
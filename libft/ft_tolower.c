/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 17:57:34 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/12 15:53:56 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

// int	main(void)
// {
// 	for (int i = 0; i < 256; i++)
// 	{
// 		if (ft_tolower(i) != tolower(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_tolower(i));
// 			printf("%i\n", tolower(i));
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }
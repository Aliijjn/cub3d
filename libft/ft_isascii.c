/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:36:04 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/12 15:53:46 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
	{
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	for (int i = 0; i < 256; i++)
// 	{
// 		if (ft_isascii(i) != isascii(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isascii(i));
// 			printf("%i\n", isascii(i));
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }
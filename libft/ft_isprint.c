/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:38:18 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/12 15:53:47 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((c >= ' ' && c <= '~'))
	{
		return (16384);
	}
	return (0);
}

// int	main(void)
// {
// 	for (int i = 0; i < 256; i++)
// 	{
// 		if (ft_isprint(i) != isprint(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isprint(i));
// 			printf("%i\n", isprint(i));
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }
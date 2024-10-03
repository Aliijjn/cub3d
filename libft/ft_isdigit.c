/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:31:14 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/12 15:53:47 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (2048);
	}
	return (0);
}

// int	main(void)
// {
// 	for (int i = 0; i < 256; i++)
// 	{
// 		if (ft_isdigit(i) != isdigit(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isdigit(i));
// 			printf("%i\n", isdigit(i));
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }
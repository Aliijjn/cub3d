/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:04:12 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/12 15:53:46 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1024);
	}
	return (0);
}

// int	main(void)
// {
// 	for (int i = 0; i < 256; i++)
// 	{
// 		if (ft_isalpha(i) != isalpha(i))
// 		{
// 			printf("\nERROR at %i:\n", i);
// 			printf("%i\n", ft_isalpha(i));
// 			printf("%i\n", isalpha(i));
// 			continue;
// 		}
// 	printf("ok ");
// 	}
// }
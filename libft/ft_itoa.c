/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 12:52:50 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/18 19:01:29 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_length(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
	{
		length++;
	}
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static void	loop_int(long n, int length, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		str[length] = n % 10 + '0';
		n /= 10;
		length--;
	}
}

char	*ft_itoa(int n)
{
	int		length;
	char	*str_out;

	length = get_int_length(n);
	str_out = (char *)ft_calloc(length + 1, sizeof(char));
	if (!str_out)
	{
		return (0);
	}
	loop_int((long)n, length - 1, str_out);
	return (str_out);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(INT_MIN));
// }

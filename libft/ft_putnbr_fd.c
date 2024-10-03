/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 13:28:22 by akuijer       #+#    #+#                 */
/*   Updated: 2023/10/24 12:58:56 by akuijer       ########   odam.nl         */
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

static void	ft_itoa_fd(int n, char *s)
{
	int		length;

	ft_memset(s, 0, 20);
	length = get_int_length(n);
	loop_int((long)n, length - 1, s);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	s[20];

	i = 0;
	ft_itoa_fd(n, s);
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int main(void)
// {
// 	int fd = open("test4.txt", O_RDWR | O_CREAT);
// 	ft_putnbr_fd(1234567890, fd);
// }
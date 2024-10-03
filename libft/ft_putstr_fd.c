/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 13:21:46 by akuijer       #+#    #+#                 */
/*   Updated: 2024/04/24 15:47:18 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// int main(void)
// {
// 	int fd = open("test2.txt", O_RDWR | O_CREAT);
// 	ft_putstr_fd("No time to wallow in the mire", fd);
// }
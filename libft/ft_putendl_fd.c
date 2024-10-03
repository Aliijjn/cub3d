/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akuijer <akuijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 13:31:26 by akuijer       #+#    #+#                 */
/*   Updated: 2024/05/06 13:44:12 by akuijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

// int main(void)
// {
// 	int fd = open("test3.txt", O_RDWR | O_CREAT);
// 	ft_putendl_fd("No time to wallow in the mire", fd);
// }
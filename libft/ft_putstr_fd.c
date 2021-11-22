/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <sashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:07:11 by sashly            #+#    #+#             */
/*   Updated: 2020/11/06 13:06:20 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putstr3(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, 1);
	ft_putstr_fd(s2, 1);
	ft_putstr_fd(s3, 1);
}

void	ft_putstr_fd_col(char *s, char *col, int fd)
{
	if (s)
	{
		write(fd, col, ft_strlen(col));
		write(fd, s, ft_strlen(s));
		write(fd, "\033[0m", 4);
	}
}

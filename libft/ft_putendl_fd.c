/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <sashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:01:35 by sashly            #+#    #+#             */
/*   Updated: 2020/11/06 13:06:08 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

void 	ft_putendl_fd_col(char *s, char *col, int fd)
{
	if (s)
	{
		write(fd, col, ft_strlen(col));
		write(fd, s, ft_strlen(s));
		write(fd, "\033[0m", 4);
		write(fd, "\n", 1);
	}
}

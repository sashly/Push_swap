/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:43:25 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:43:44 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split_free(char **split, int ret)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (ret);
}

int	ft_split_size(char **split)
{
	int	ssize;

	ssize = 0;
	while (split[ssize])
		ssize++;
	return (ssize);
}

void	ft_split_print(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		write(1, split[i], ft_strlen(split[i]));
		write(1, "\n", 1);
		i++;
	}
}

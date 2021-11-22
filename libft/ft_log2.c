/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:40:27 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:41:55 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_log2(unsigned int nbr)
{
	unsigned int	log2_val;

	log2_val = 0;
	if (nbr == 0)
		return (-1);
	while (nbr > 1)
	{
		nbr = nbr >> 1;
		log2_val++;
	}
	return (log2_val);
}

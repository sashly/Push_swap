/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:00:16 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:00:19 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_operation_rrr(t_push_swap *ps, int print, int rec)
{
	ps_operation_rra(ps, 0, 0);
	ps_operation_rrb(ps, 0, 0);
	if (print)
		write(PS_STDOUT, "rrr\n", 4);
	if (rec && ps->rec)
		ps_push_front(ps->rec, PS_RRR);
}

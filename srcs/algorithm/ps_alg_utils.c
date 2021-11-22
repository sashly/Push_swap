/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:23:29 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:23:56 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_stack_is_sorted(t_stack *st)
{
	t_dllist	*it;

	it = st->head;
	while (it->next)
	{
		if (it->val > it->next->val)
			return (0);
		it = it->next;
	}
	return (1);
}

void	ps_stack_min_max(t_stack *st, int *min, int *max)
{
	*min = st->head->val;
	*max = st->head->val;
	if (st->head->next->val < *min)
		*min = st->head->next->val;
	if (st->head->next->val > *max)
		*max = st->head->next->val;
	if (st->tail->val < *min)
		*min = st->tail->val;
	if (st->tail->val > *max)
		*max = st->tail->val;
}

void 	ps_arrange_two(t_push_swap *ps, int print, int rec)
{
	if (ps->a.size < 2)
		return ;
	if (ps->a.head->val > ps->a.head->next->val)
		ps->f_op[PS_SA](ps, print, rec);
}

void	ps_arrange_three(t_push_swap *ps, int print, int rec)
{
	int	min;
	int	max;

	if (ps->a.size < 3)
		return ;
	ps_stack_min_max(&ps->a, &min, &max);
	if (max == ps->a.tail->val)
	{
		if (ps->a.head->val > ps->a.head->next->val)
			ps->f_op[PS_SA](ps, print, rec);
	}
	else if (min == ps->a.tail->val)
	{
		if (ps->a.head->val > ps->a.head->next->val)
			ps->f_op[PS_SA](ps, print, rec);
		ps->f_op[PS_RRA](ps, print, rec);
	}
	else
	{
		if (ps->a.head->val < ps->a.head->next->val)
			ps->f_op[PS_SA](ps, print, rec);
		ps->f_op[PS_RA](ps, print, rec);
	}
}

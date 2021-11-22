/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg_insertion_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:25:59 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:26:49 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_get_stack_max(t_stack *st, t_dllist **max)
{
	t_dllist	*it;

	if (!max)
		return ;
	it = st->head;
	*max = it;
	while (it)
	{
		if (it->val > (*max)->val)
			*max = it;
		it = it->next;
	}
}

static void	ps_get_stack_max_less_than(t_stack *st, int ins_val, t_dllist **max)
{
	t_dllist	*max_less_ins;
	t_dllist	*it;

	it = st->head;
	ps_get_stack_max(st, max);
	max_less_ins = NULL;
	while (it)
	{
		if (it->val < ins_val && (!max_less_ins || max_less_ins->val < it->val))
			max_less_ins = it;
		it = it->next;
	}
	if (max_less_ins)
		*max = max_less_ins;
}

static int	ps_get_route_to_insert(t_stack *st, int ins_val, int *op)
{
	t_dllist	*it;
	t_dllist	*max;
	int			route;
	int			tmp;

	tmp = 0;
	*op = PS_RB;
	ps_get_stack_max_less_than(st, ins_val, &max);
	it = st->head;
	while (it != max && ++tmp)
		it = it->next;
	route = tmp;
	tmp = 0;
	it = st->tail;
	while (it != max && ++tmp)
		it = it->prev;
	if (tmp + 1 < route)
	{
		route = (tmp + 1);
		*op = PS_RRB;
	}
	return (route);
}

static void	ps_isort_align_and_push_a(t_push_swap *ps, int print, int rec)
{
	t_dllist	*max;
	t_dllist	*it;
	int			route;

	route = 0;
	ps_get_stack_max(&ps->b, &max);
	it = ps->b.head;
	while (it != max && ++route)
		it = it->next;
	while (route--)
		ps->f_op[PS_RB](ps, print, rec);
	while (ps->b.size)
		ps->f_op[PS_PA](ps, print, rec);
}

void	ps_insertion_sort(t_push_swap *ps, int print, int rec)
{
	int	route;
	int	op;

	if (ps->a.size == 1)
		return ;
	while (ps->a.size)
	{
		if (ps->b.size < 2)
		{
			ps->f_op[PS_PB](ps, print, rec);
			if (ps->b.size == 2 && ps->b.head->val < ps->b.head->next->val)
				ps->f_op[PS_SB](ps, print, rec);
		}
		else
		{
			route = ps_get_route_to_insert(&ps->b, ps->a.head->val, &op);
			while (route--)
				ps->f_op[op](ps, print, rec);
			ps->f_op[PS_PB](ps, print, rec);
		}
	}
	ps_isort_align_and_push_a(ps, print, rec);
}

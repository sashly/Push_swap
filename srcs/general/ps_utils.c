/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:01:24 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:01:35 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_init(t_push_swap *ps)
{
	ps->a.head = NULL;
	ps->a.tail = NULL;
	ps->a.size = 0;
	ps->b.head = NULL;
	ps->b.tail = NULL;
	ps->b.size = 0;
	ps->f_op[PS_SA] = ps_operation_sa;
	ps->f_op[PS_SB] = ps_operation_sb;
	ps->f_op[PS_SS] = ps_operation_ss;
	ps->f_op[PS_PA] = ps_operation_pa;
	ps->f_op[PS_PB] = ps_operation_pb;
	ps->f_op[PS_RA] = ps_operation_ra;
	ps->f_op[PS_RB] = ps_operation_rb;
	ps->f_op[PS_RR] = ps_operation_rr;
	ps->f_op[PS_RRA] = ps_operation_rra;
	ps->f_op[PS_RRB] = ps_operation_rrb;
	ps->f_op[PS_RRR] = ps_operation_rrr;
	ps->f_sort = ps_quick_sort;
	ps->rec = NULL;
	ps->option_m = PS_NORM_M;
	ps->col_m = PS_COLM_DEF;
	ps->color_a = PS_COL_DEF;
	ps->color_b = PS_COL_DEF;
}

void 	ps_push_front(t_stack *stk, int value)
{
	int	tail_f;

	tail_f = 0;
	if (!stk->head)
		tail_f = 1;
	ft_dllist_push_front(&stk->head, value);
	if (stk->head)
	{
		if (tail_f)
			stk->tail = stk->head;
		stk->size++;
	}
}

int	ps_stack_clear(t_stack *a)
{
	a->tail = NULL;
	a->size = 0;
	while (a->head)
		ft_dllist_del_node(&a->head, a->head);
	return (1);
}

int	push_swap_clear(t_push_swap *ps)
{
	ps_stack_clear(&ps->a);
	ps_stack_clear(&ps->b);
	if (ps->rec)
	{
		ps_stack_clear(ps->rec);
		free(ps->rec);
	}
	return (1);
}

int	push_swap_copy_stack(t_stack *dest, t_stack *src)
{
	t_dllist	*it;

	it = src->tail;
	while (it)
	{
		ps_push_front(dest, it->val);
		it = it->prev;
	}
	return (1);
}

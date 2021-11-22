/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:59:20 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 10:59:43 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_operation_sa(t_push_swap *ps, int print, int rec)
{
	int	tmp;

	if (ps->a.size > 1)
	{
		tmp = ps->a.head->val;
		ps->a.head->val = ps->a.head->next->val;
		ps->a.head->next->val = tmp;
	}
	if (print)
		write(PS_STDOUT, "sa\n", 3);
	if (rec && ps->rec)
		ps_push_front(ps->rec, PS_SA);
}

void	ps_operation_sb(t_push_swap *ps, int print, int rec)
{
	int	tmp;

	if (ps->b.size > 1)
	{
		tmp = ps->b.head->val;
		ps->b.head->val = ps->b.head->next->val;
		ps->b.head->next->val = tmp;
	}
	if (print)
		write(PS_STDOUT, "sb\n", 3);
	if (rec && ps->rec)
		ps_push_front(ps->rec, PS_SB);
}

void	ps_operation_ss(t_push_swap *ps, int print, int rec)
{
	ps_operation_sa(ps, 0, 0);
	ps_operation_sb(ps, 0, 0);
	if (print)
		write(PS_STDOUT, "ss\n", 3);
	if (rec && ps->rec)
		ps_push_front(ps->rec, PS_SS);
}

void 	ps_operation_pa(t_push_swap *ps, int print, int rec)
{
	if (ps->b.size)
	{
		ps_push_front(&ps->a, ps->b.head->val);
		ft_dllist_del_node(&ps->b.head, ps->b.head);
		if (ps->b.size == 1)
			ps->b.tail = NULL;
		ps->b.size--;
	}
	if (print)
		write(PS_STDOUT, "pa\n", 3);
	if (rec && ps->rec)
		ps_push_front(ps->rec, PS_PA);
}

void 	ps_operation_pb(t_push_swap *ps, int print, int rec)
{
	if (ps->a.size)
	{
		ps_push_front(&ps->b, ps->a.head->val);
		ft_dllist_del_node(&ps->a.head, ps->a.head);
		if (ps->a.size == 1)
			ps->a.tail = NULL;
		ps->a.size--;
	}
	if (print)
		write(PS_STDOUT, "pb\n", 3);
	if (rec && ps->rec)
		ps_push_front(ps->rec, PS_PB);
}

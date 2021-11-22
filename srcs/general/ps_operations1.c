/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:59:51 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:00:02 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_operation_ra(t_push_swap *ps, int print, int rec)
{
	t_dllist	*tmp;

	if (ps->a.size > 1)
	{
		tmp = ps->a.head;
		ps->a.head = ps->a.head->next;
		ps->a.head->prev = NULL;
		tmp->prev = ps->a.tail;
		ps->a.tail->next = tmp;
		ps->a.tail = ps->a.tail->next;
		ps->a.tail->next = NULL;
	}
	if (print)
		write(PS_STDOUT, "ra\n", 3);
	if (rec && ps->rec)
		ps_push_front(ps->rec, PS_RA);
}

void	ps_operation_rb(t_push_swap *ps, int print, int rec)
{
	t_dllist	*tmp;

	if (ps->b.size > 1)
	{
		tmp = ps->b.head;
		ps->b.head = ps->b.head->next;
		ps->b.head->prev = NULL;
		tmp->prev = ps->b.tail;
		ps->b.tail->next = tmp;
		ps->b.tail = ps->b.tail->next;
		ps->b.tail->next = NULL;
	}
	if (print)
		write(PS_STDOUT, "rb\n", 3);
	if (rec && ps->rec)
		ps_push_front(ps->rec, PS_RB);
}

void	ps_operation_rr(t_push_swap *ps, int print, int rec)
{
	ps_operation_ra(ps, 0, 0);
	ps_operation_rb(ps, 0, 0);
	if (print)
		write(PS_STDOUT, "rr\n", 3);
	if (rec && ps->rec)
		ps_push_front(ps->rec, PS_RR);
}

void	ps_operation_rra(t_push_swap *ps, int print, int rec)
{
	t_dllist	*tmp;

	if (ps->a.size > 1)
	{
		tmp = ps->a.tail;
		ps->a.tail = ps->a.tail->prev;
		ps->a.tail->next = NULL;
		tmp->next = ps->a.head;
		ps->a.head->prev = tmp;
		tmp->prev = NULL;
		ps->a.head = tmp;
	}
	if (print)
		write(PS_STDOUT, "rra\n", 4);
	if (rec && ps->rec)
		ps_push_front(ps->rec, PS_RRA);
}

void	ps_operation_rrb(t_push_swap *ps, int print, int rec)
{
	t_dllist	*tmp;

	if (ps->b.size > 1)
	{
		tmp = ps->b.tail;
		ps->b.tail = ps->b.tail->prev;
		ps->b.tail->next = NULL;
		tmp->next = ps->b.head;
		ps->b.head->prev = tmp;
		tmp->prev = NULL;
		ps->b.head = tmp;
	}
	if (print)
		write(PS_STDOUT, "rrb\n", 4);
	if (rec && ps->rec)
		ps_push_front(ps->rec, PS_RRB);
}

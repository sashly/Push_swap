/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg_selection_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:25:20 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:25:50 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_ssort_get_lookup(t_push_swap *ps, int **lookup)
{
	t_dllist	*it;
	int			i;

	i = 0;
	it = ps->a.head;
	*lookup = (int *)malloc(sizeof(int) * ps->a.size);
	if (!(*lookup))
		return (0);
	while (it)
	{
		(*lookup)[i] = it->val;
		i++;
		it = it->next;
	}
	ft_quick_sort(*lookup, ps->a.size);
	return (1);
}

static int	ps_ssort_get_route(t_stack *st, int val, int *op)
{
	t_dllist	*it;
	int			route;
	int			tmp;

	tmp = 0;
	*op = PS_RA;
	it = st->head;
	while (it->val != val && ++tmp)
		it = it->next;
	route = tmp;
	it = st->tail;
	tmp = 0;
	while (it->val != val && ++tmp)
		it = it->prev;
	if (tmp + 1 < route)
	{
		*op = PS_RRA;
		route = (tmp + 1);
	}
	return (route);
}

static void	ps_ssort_select_to_b(t_push_swap *ps, int *lookup, int p, int rec)
{
	int	s;
	int	route;
	int	size;
	int	swap_f;
	int	op;

	s = 0;
	size = ps->a.size - 3;
	while (s < size)
	{
		if (ps_stack_is_sorted(&ps->a))
			break ;
		swap_f = 0;
		route = ps_ssort_get_route(&ps->a, lookup[s], &op);
		while (route--)
		{
			if (ps->a.head->val == lookup[s] && s < size && ++route && ++swap_f)
				ps->f_op[PS_PB](ps, p, rec);
			else
				ps->f_op[op](ps, p, rec);
		}
		ps->f_op[PS_PB](ps, p, rec);
		if (++s && swap_f)
			ps->f_op[PS_SB](ps, p, rec);
	}
}

void	ps_selection_sort(t_push_swap *ps, int print, int rec)
{
	int	*lookup;

	if (ps->a.size == 1)
		return ;
	if (!ps_ssort_get_lookup(ps, &lookup))
		return ;
	if (ps->a.size > 3)
		ps_ssort_select_to_b(ps, lookup, print, rec);
	if (ps->a.size == 3)
		ps_arrange_three(ps, print, rec);
	else
		ps_arrange_two(ps, print, rec);
	while (ps->b.size)
		ps->f_op[PS_PA](ps, print, rec);
	free(lookup);
}

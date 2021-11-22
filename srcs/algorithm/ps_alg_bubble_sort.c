/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg_bubble_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:27:01 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:28:15 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_bubble_sort_partition_a(t_push_swap *ps, int print, int rec)
{
	int	median;
	int	size;
	int	old_size;

	old_size = ps->a.size;
	size = old_size;
	if (!ps_find_stack_median(&ps->a, ps->a.size, &median))
		return (0);
	while (size > old_size / 2 + (old_size % 2))
	{
		if (ps->a.head->val < median && --size)
			ps->f_op[PS_PB](ps, print, rec);
		else
			ps->f_op[PS_RA](ps, print, rec);
	}
	return (1);
}

static void	ps_bubble_sort_loop(t_push_swap *ps, int *sw_f, int print, int rec)
{
	t_dllist	*a;
	t_dllist	*b;
	int			i[2];

	i[0] = 0;
	i[1] = 0;
	while (i[0] < ps->a.size - 1 || i[1] < ps->b.size - 1)
	{
		a = ps->a.head;
		b = ps->b.head;
		if ((i[0] < (ps->a.size - 1) && a->val > a->next->val)
			&& (i[1] < (ps->b.size - 1) && b->val < b->next->val) && ++(*sw_f))
			ps->f_op[PS_SS](ps, print, rec);
		else if (i[0] < (ps->a.size - 1) && a->val > a->next->val && ++(*sw_f))
			ps->f_op[PS_SA](ps, print, rec);
		else if (i[1] < (ps->b.size - 1) && b->val < b->next->val && ++(*sw_f))
			ps->f_op[PS_SB](ps, print, rec);
		ps->f_op[PS_RR](ps, print, rec);
		i[0]++;
		i[1]++;
	}
}

void	ps_bubble_sort(t_push_swap *ps, int print, int rec)
{
	int	swap_f;

	if (ps->a.size == 1 || !ps_bubble_sort_partition_a(ps, print, rec))
		return ;
	swap_f = 1;
	while (swap_f)
	{
		swap_f = 0;
		ps_bubble_sort_loop(ps, &swap_f, print, rec);
		if (ps->a.size == ps->b.size)
			ps->f_op[PS_RR](ps, print, rec);
		else
			ps->f_op[PS_RA](ps, print, rec);
	}
	while (ps->b.size)
		ps->f_op[PS_PA](ps, print, rec);
}

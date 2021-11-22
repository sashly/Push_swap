/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg_quick_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:29:26 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:30:01 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_init_partition_stack_a(t_push_swap *ps, int is_pow2,
									 int print, int rec)
{
	int	median;
	int	st_size;

	while (ps->a.size > (2 - is_pow2))
	{
		if (!ps_find_stack_median(&ps->a, ps->a.size, &median))
			return (0);
		st_size = ps->a.size;
		while (ps->a.size > st_size / 2 + (st_size % 2))
		{
			if (ps->a.head->val < median)
				ps->f_op[PS_PB](ps, print, rec);
			else if (ps->a.tail->val < median)
			{
				ps->f_op[PS_RRA](ps, print, rec);
				ps->f_op[PS_PB](ps, print, rec);
			}
			else
				ps->f_op[PS_RA](ps, print, rec);
		}
	}
	if (ps->a.size == 2 && ps->a.head->val > ps->a.head->next->val)
		ps->f_op[PS_SA](ps, print, rec);
	return (1);
}

static int	ps_partition_stack_a(t_push_swap *ps, int depth, int print, int rec)
{
	int	median;
	int	st_size[2];
	int	rotate;

	st_size[1] = ft_is_pow2(depth);
	while (depth > (2 - st_size[1]))
	{
		if (!ps_find_stack_median(&ps->a, depth, &median))
			return (0);
		st_size[0] = depth;
		rotate = 0;
		while (st_size[0] > depth / 2 + (depth % 2))
		{
			if (ps->a.head->val < median && st_size[0]--)
				ps->f_op[PS_PB](ps, print, rec);
			else if (++rotate)
				ps->f_op[PS_RA](ps, print, rec);
		}
		depth = st_size[0];
		while (rotate--)
			ps->f_op[PS_RRA](ps, print, rec);
	}
	if (depth == 2 && ps->a.head->val > ps->a.head->next->val)
		ps->f_op[PS_SA](ps, print, rec);
	return (1);
}

static int	ps_partition_stack_b(t_push_swap *ps, int depth, int print, int rec)
{
	int	median;
	int	rotate;
	int	st_size;
	int	last;

	rotate = 0;
	last = (depth == ps->b.size);
	st_size = depth;
	if (!ps_find_stack_median(&ps->b, depth, &median))
		return (0);
	while (st_size > depth / 2)
	{
		if (ps->b.head->val >= median && --st_size)
			ps->f_op[PS_PA](ps, print, rec);
		else if (++rotate)
			ps->f_op[PS_RB](ps, print, rec);
	}
	while (!last && rotate--)
		ps->f_op[PS_RRB](ps, print, rec);
	return (1);
}

static void	ps_qsort_rec(t_push_swap *ps, int depth, int print, int rec)
{
	int	chunks[32];
	int	chunk_it;

	chunk_it = ft_log2((unsigned)depth) - 1;
	ps_qsort_fill_chunks(chunks, depth);
	if (!ps->b.size)
	{
		if (!ps_init_partition_stack_a(ps, ft_is_pow2(ps->a.size), print, rec))
			return ;
	}
	else if (!ps_partition_stack_a(ps, depth, print, rec))
		return ;
	while (chunk_it >= 0)
	{
		if (chunks[chunk_it] < 30)
			ps_select_sort_ba_chunk(ps, chunks[chunk_it--], print, rec);
		else
		{
			if (!ps_partition_stack_b(ps, chunks[chunk_it], print, rec))
				return ;
			ps_qsort_rec(ps, chunks[chunk_it] / 2 + (chunks[chunk_it] % 2),
				print, rec);
			chunks[chunk_it] -= chunks[chunk_it] / 2 + (chunks[chunk_it] % 2);
		}
	}
}

void	ps_quick_sort(t_push_swap *ps, int print, int rec)
{
	if (ps_stack_is_sorted(&ps->a))
		return ;
	if (ps->a.size < 11)
		ps_selection_sort(ps, print, rec);
	else
		ps_qsort_rec(ps, ps->a.size, print, rec);
}

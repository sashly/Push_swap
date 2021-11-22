/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg_qsort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:30:14 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:30:48 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_qsort_fill_chunks(int *chunks, int size_old)
{
	int	size;
	int	i;

	i = 0;
	size = size_old;
	while (size > 1)
	{
		size = size_old / 2;
		size_old -= size;
		chunks[i] = size;
		i++;
	}
}

static void	ps_ssort_ba_chunk_loop(t_push_swap *ps, int s, int *look, int *pars)
{
	int	swap_f;
	int	route;
	int	op;

	while (s >= 0)
	{
		swap_f = 0;
		route = ps_get_stack_route(&ps->b, look[s], &op);
		s--;
		while (route--)
		{
			if (s >= 0 && ps->b.head->val == look[s] && ++swap_f)
			{
				if (op == PS_RRB)
					route++;
				ps->f_op[PS_PA](ps, pars[0], pars[1]);
			}
			else
				ps->f_op[op](ps, pars[0], pars[1]);
		}
		ps->f_op[PS_PA](ps, pars[0], pars[1]);
		if (swap_f && s--)
			ps->f_op[PS_SA](ps, pars[0], pars[1]);
	}
}

int	ps_select_sort_ba_chunk(t_push_swap *ps, int depth, int print, int rec)
{
	int	*lookup;
	int	pars[2];

	if (!ps_get_lookup(&ps->b, &lookup, depth))
		return (0);
	pars[0] = print;
	pars[1] = rec;
	ps_ssort_ba_chunk_loop(ps, depth - 1, lookup, pars);
	if (ps->a.size > 1 && ps->a.head->val > ps->a.head->next->val)
		ps->f_op[PS_SA](ps, print, rec);
	free(lookup);
	return (1);
}

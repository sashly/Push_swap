/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_alg_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:24:11 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:25:04 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_find_stack_median(t_stack *st, int depth, int *median)
{
	t_dllist	*it;
	int			i;
	int			*arr;

	i = 0;
	it = st->head;
	arr = (int *)malloc(sizeof(int) * depth);
	if (!arr)
		return (0);
	while (i < depth)
	{
		arr[i] = it->val;
		it = it->next;
		i++;
	}
	ft_quick_sort(arr, depth);
	*median = arr[depth / 2];
	free(arr);
	return (1);
}

int	ps_get_stack_route(t_stack *st, int val, int *op)
{
	t_dllist	*it;
	int			route;
	int			tmp;

	tmp = 0;
	*op = PS_RB;
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
		route = (tmp + 1);
		*op = PS_RRB;
	}
	return (route);
}

int 	ps_get_lookup(t_stack *st, int **lookup, int depth)
{
	t_dllist	*it;
	int			i;

	i = 0;
	it = st->head;
	*lookup = (int *)malloc(sizeof(int) * depth);
	if (!(*lookup))
		return (0);
	while (i < depth)
	{
		(*lookup)[i] = it->val;
		it = it->next;
		i++;
	}
	ft_quick_sort(*lookup, depth);
	return (1);
}

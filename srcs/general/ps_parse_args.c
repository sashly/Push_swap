/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:00:36 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:01:09 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_check_duplicates(t_stack *a)
{
	t_dllist	*it_o;
	t_dllist	*it_i;

	it_o = a->head;
	while (it_o)
	{
		it_i = it_o;
		while (it_i->next)
		{
			it_i = it_i->next;
			if (it_i && it_o->val == it_i->val)
				return (0);
		}
		it_o = it_o->next;
	}
	return (1);
}

int	ps_parse_args(t_stack *a, int argc_begin, int argc_end, char **argv)
{
	char	**split;
	int		val;
	int		i;
	int		j;

	i = argc_end;
	while (i >= argc_begin)
	{
		split = ft_split_charset(argv[i], " 	\n\v\r\f");
		j = ft_split_size(split) - 1;
		while (j >= 0)
		{
			if (!ft_atoi_check(split[j], &val))
				return (ft_split_free(split, 0));
			ps_push_front(a, val);
			j--;
		}
		ft_split_free(split, 1);
		i--;
	}
	return (ps_check_duplicates(a));
}

void	ps_stack_set_null(t_stack *st)
{
	st->head = NULL;
	st->tail = NULL;
	st->size = 0;
}

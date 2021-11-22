/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:19:18 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:19:20 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_ck_operation_case(char *operation)
{
	if (!ft_strcmp(operation, "sa"))
		return (PS_SA);
	else if (!ft_strcmp(operation, "sb"))
		return (PS_SB);
	else if (!ft_strcmp(operation, "ss"))
		return (PS_SS);
	else if (!ft_strcmp(operation, "pa"))
		return (PS_PA);
	else if (!ft_strcmp(operation, "pb"))
		return (PS_PB);
	else if (!ft_strcmp(operation, "ra"))
		return (PS_RA);
	else if (!ft_strcmp(operation, "rb"))
		return (PS_RB);
	else if (!ft_strcmp(operation, "rr"))
		return (PS_RR);
	else if (!ft_strcmp(operation, "rra"))
		return (PS_RRA);
	else if (!ft_strcmp(operation, "rrb"))
		return (PS_RRB);
	else if (!ft_strcmp(operation, "rrr"))
		return (PS_RRR);
	return (-1);
}

int	ps_ck_check_ps_ret(t_push_swap *ps, int ret)
{
	if (ret)
	{
		if (ps->col_m == PS_COLM_COL)
			write(PS_STDOUT, "\033[32mOK\033[0m\n", 12);
		else
			write(PS_STDOUT, "OK\n", 3);
	}
	else
	{
		if (ps->col_m == PS_COLM_COL)
			write(PS_STDOUT, "\033[31mKO\033[0m\n", 12);
		else
			write(PS_STDOUT, "KO\n", 3);
	}
	return (ret);
}

int	ps_ck_evaluate_push_swap(t_push_swap *ps)
{
	t_dllist	*it;

	if (ps->b.size)
		return (ps_ck_check_ps_ret(ps, 0));
	it = ps->a.head;
	while (it->next)
	{
		if (it->val > it->next->val)
			return (ps_ck_check_ps_ret(ps, 0));
		it = it->next;
	}
	return (ps_ck_check_ps_ret(ps, 1));
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc > 1)
	{
		push_swap_init(&ps);
		if (!ps_ck_parse_argv(argc, argv, &ps) && push_swap_clear(&ps))
			return (0);
		if (!ps_ck_read_instructions(&ps, PS_STDIN) && push_swap_clear(&ps))
			return (0);
		ps_ck_evaluate_push_swap(&ps);
		push_swap_clear(&ps);
	}
	return (0);
}

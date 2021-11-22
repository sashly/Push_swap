/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:03:54 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:04:41 by sashly           ###   ########.fr       */
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

int	ps_ck_read_instr_ret(char *operation, int error)
{
	free(operation);
	if (error)
	{
		write(PS_STDERR, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	ps_ck_read_instructions(t_push_swap *ps, int input)
{
	char	*operation;
	int		cs;
	int		gnl;
	int		ope_count;
	int		ps_pr_ret;

	gnl = 1;
	ope_count = 0;
	while (gnl)
	{
		gnl = get_next_line(input, &operation);
		if (!gnl)
			break ;
		cs = ps_ck_operation_case(operation);
		if (cs == -1)
			return (ps_ck_read_instr_ret(operation, 1));
		ps->f_op[cs](ps, 0, 0);
		free(operation);
		ope_count++;
	}
	return (ps_ck_read_instr_ret(operation, 0));
}

int	ps_ck_check_push_swap(t_push_swap *ps)
{
	t_dllist	*it;

	if (ps->b.size)
		return (write(PS_STDOUT, "KO\n", 3) * 0);
	it = ps->a.head;
	while (it->next)
	{
		if (it->val > it->next->val)
			return (write(PS_STDOUT, "KO\n", 3) * 0);
		it = it->next;
	}
	return (write(PS_STDOUT, "OK\n", 3) / 3);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc > 1)
	{
		push_swap_init(&ps);
		if (!ps_parse_args(&ps.a, 1, argc - 1, argv) && ps_stack_clear(&ps.a))
			return (write(PS_STDERR, "Error\n", 6) * 0);
		if (!ps_ck_read_instructions(&ps, PS_STDIN) && push_swap_clear(&ps))
			return (0);
		ps_ck_check_push_swap(&ps);
		push_swap_clear(&ps);
	}
	return (0);
}

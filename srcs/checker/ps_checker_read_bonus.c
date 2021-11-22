/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_read_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:19:37 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:20:31 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ps_ck_print_debug(t_push_swap *ps, char *operation, int cs, int gnl)
{
	int	width;

	if (ps->option_m == PS_DEBUG_M || ps->option_m == PS_MANUAL_M
		|| (ps->option_m == PS_MANUAL_E && cs != -1))
	{
		if (gnl == 0)
			write(PS_STDOUT, "\n", 1);
		if (operation && ps->col_m == PS_COLM_DEF && ps->option_m == PS_DEBUG_M)
			ft_putendl_fd(operation, 1);
		else if (operation && ps->option_m == PS_DEBUG_M)
			ft_putendl_fd_col(operation, PS_CYAN, 1);
		width = ps_print(ps, ps->color_a, ps->color_b);
		if (ps->col_m == PS_COLM_COL)
			write(PS_STDOUT, PS_BLUE, PS_COLOR_S);
		write(PS_STDOUT, PS_SEP, width + 1);
		write(PS_STDOUT, PS_RESET_COL, PS_RESCOL_S);
		if (ps->option_m == PS_DEBUG_M || gnl == 0)
			write(PS_STDOUT, "\n", 1);
		else
			write(PS_STDOUT, PS_PAD, 3);
	}
}

int	ps_ck_read_instructions(t_push_swap *ps, int input)
{
	char	*operation;
	int		cs;
	int		gnl;
	int		ps_pr_ret;

	gnl = 1;
	ps_ck_print_debug(ps, NULL, 1, 1);
	while (gnl)
	{
		if (ps->option_m == PS_MANUAL_M || ps->option_m == PS_MANUAL_E)
			ft_putstr_fd_col("operation> ", ps->color_a, 1);
		gnl = get_next_line(input, &operation);
		if (!gnl)
			break ;
		cs = ps_ck_operation_case(operation);
		if (cs == -1 && ps->option_m != PS_MANUAL_E)
			return (ps_ck_read_instr_ret(operation, 1));
		if (cs != -1)
			ps->f_op[cs](ps, 0, 0);
		ps_ck_print_debug(ps, operation, cs, gnl);
		free(operation);
	}
	ps_ck_print_debug(ps, NULL, 1, gnl);
	return (ps_ck_read_instr_ret(operation, 0));
}

int	ps_ck_print_help(t_push_swap *ps)
{
	ps->option_m = PS_HELP_M;
	ft_putstr_fd("Checker usage:  ./checker [-options] <NUMBERS>\n", 1);
	ft_putstr_fd("Options:        --help   -  help;\n", 1);
	ft_putstr_fd("                -v   	   -  debug mode;\n", 1);
	ft_putstr_fd("                -m   	   -  manual mode;\n", 1);
	ft_putstr_fd("                -c   	   -  color mode;\n", 1);
	ft_putstr_fd("                -e  	   -  ignoring errors"
		"(only for manual mode);\n", 1);
	return (1);
}

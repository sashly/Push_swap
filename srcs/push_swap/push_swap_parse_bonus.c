/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:30:00 by sashly            #+#    #+#             */
/*   Updated: 2021/04/29 22:32:41 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_print_help(t_push_swap *ps)
{
	ps->option_m = PS_HELP_M;
	ft_putstr_fd("Push_Swap usage:  ./push_swap [-options] <NUMBERS>\n", 1);
	ft_putstr_fd("Options:          --help      -   help;\n", 1);
	ft_putstr_fd("                  -v          -   mlx visualization;\n", 1);
	ft_putstr_fd("                  -a[1,2,3]   -   alternative sort algorithm "
		"(1 - insertion sort, 2 - selection sort, "
		"3 - bubble sort);\n", 1);
	ft_putstr_fd("                  -vc[1,2,3]  -   visual algorithms compare "
		"(base algorithm with an alternative);\n", 1);
	ft_putstr_fd("                  -va[1,2,3]  -   visualization of "
		"alternative algorithm;\n", 1);
	return (1);
}

int	ps_parse_option_flags(char *str, t_push_swap *ps)
{
	while (*str)
	{
		if (*str == 'v')
			ps->col_m = PS_VISUAL;
		else if (*str == 'a' && ps->option_m == PS_NORM_M)
			ps->option_m = PS_ALT_ALG_D;
		else if (*str == 'c' && ps->option_m == PS_NORM_M
			&& ps->col_m == PS_VISUAL)
			ps->option_m = PS_COMP_D;
		else if ((*str == '1' || *str == '2' || *str == '3')
			&& ps->option_m != PS_MANUAL_M)
			ps->option_m += *str - '0';
		else
			return (0);
		str++;
	}
	if (ps->option_m == PS_ALT_ALG_D || ps->option_m == PS_COMP_D)
		return (0);
	return (1);
}

int	ps_parse_option(int argc, char **argv, t_push_swap *ps)
{
	char	*str;

	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "--help"))
			return (ps_print_help(ps));
		else if (argv[1][0] == '-' && argv[1][1])
			return (ps_parse_option_flags(&argv[1][1], ps));
	}
	return (0);
}

int	ps_parse_argv(int argc, char **argv, t_push_swap *ps)
{
	if (ps_parse_option(argc, argv, ps))
	{
		if (argc < 3)
			return (0);
		if (!ps_parse_args(&ps->a, 2, argc - 1, argv) && ps_stack_clear(&ps->a))
			return (write(PS_STDERR, "Error\n", 6) * 0);
	}
	else
		if (!ps_parse_args(&ps->a, 1, argc - 1, argv) && ps_stack_clear(&ps->a))
			return (write(PS_STDERR, "Error\n", 6) * 0);
	return (1);
}

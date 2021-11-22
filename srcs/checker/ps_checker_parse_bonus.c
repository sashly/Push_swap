/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_parse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:21:02 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:22:20 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_ck_parse_option_flags(char *str, t_push_swap *ps)
{
	while (*str)
	{
		if (*str == 'c')
		{
			ps->col_m = PS_COLM_COL;
			ps->color_a = PS_GREEN;
			ps->color_b = PS_PURPLE;
		}
		else if (*str == 'm' && ps->option_m == PS_NORM_M)
			ps->option_m = PS_MANUAL_M;
		else if (*str == 'v' && ps->option_m == PS_NORM_M)
			ps->option_m = PS_DEBUG_M;
		else if (*str == 'e' && ps->option_m == PS_MANUAL_M)
			ps->option_m = PS_MANUAL_E;
		else
			return (0);
		str++;
	}
	return (1);
}

int	ps_ck_parse_option(int argc, char **argv, t_push_swap *ps)
{
	char	*str;

	if (argc > 1)
	{
		if (!ft_strcmp(argv[1], "--help"))
			return (ps_ck_print_help(ps));
		else if (argv[1][0] == '-')
			return (ps_ck_parse_option_flags(&argv[1][1], ps));
	}
	return (0);
}

int	ps_ck_parse_argv(int argc, char **argv, t_push_swap *ps)
{
	if (ps_ck_parse_option(argc, argv, ps))
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

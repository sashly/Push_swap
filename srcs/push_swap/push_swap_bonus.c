/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:28:45 by sashly            #+#    #+#             */
/*   Updated: 2021/04/29 22:29:52 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_mlx.h"

int	ps_set_options_visual(t_push_swap *ps, t_push_swap *alt)
{
	ps->rec = (t_stack *)malloc(sizeof(t_stack));
	if (!ps->rec)
		return (0);
	ps_stack_set_null(ps->rec);
	if (ps->option_m >= PS_COMP_1)
	{
		alt->rec = (t_stack *)malloc(sizeof(t_stack));
		if (!ps->rec)
			return (0);
		ps_stack_set_null(alt->rec);
		ps_stack_set_null(&alt->a_copy);
		push_swap_copy_stack(&alt->a, &ps->a);
		push_swap_copy_stack(&alt->a_copy, &alt->a);
	}
	ps_stack_set_null(&ps->a_copy);
	push_swap_copy_stack(&ps->a_copy, &ps->a);
	return (1);
}

int	ps_set_options(t_push_swap *ps, t_push_swap *alt)
{
	if (ps->option_m != PS_NORM_M || ps->col_m == PS_VISUAL)
	{
		if (ps->option_m == PS_ALT_ALG_1)
			ps->f_sort = ps_insertion_sort;
		else if (ps->option_m == PS_ALT_ALG_2)
			ps->f_sort = ps_selection_sort;
		else if (ps->option_m == PS_ALT_ALG_3)
			ps->f_sort = ps_bubble_sort;
		else if (ps->option_m == PS_COMP_1)
			alt->f_sort = ps_insertion_sort;
		else if (ps->option_m == PS_COMP_2)
			alt->f_sort = ps_selection_sort;
		else if (ps->option_m == PS_COMP_3)
			alt->f_sort = ps_bubble_sort;
		if (ps->col_m == PS_VISUAL)
			if (!ps_set_options_visual(ps, alt))
				return (0);
	}
	return (1);
}

void	push_swap_visualization(t_push_swap *ps, t_push_swap *alt)
{
	ps->f_sort(ps, 0, 1);
	if (ps->option_m == PS_COMP_1 || ps->option_m == PS_COMP_2
		|| ps->option_m == PS_COMP_3)
		alt->f_sort(alt, 0, 1);
	mlx_main(ps, alt);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	t_push_swap	alt;

	if (argc > 1)
	{
		push_swap_init(&ps);
		push_swap_init(&alt);
		if (!ps_parse_argv(argc, argv, &ps) && push_swap_clear(&ps))
			return (0);
		if (!ps_set_options(&ps, &alt) && push_swap_clear(&ps)
			&& push_swap_clear(&alt))
			return (0);
		if (ps.col_m == PS_VISUAL)
			push_swap_visualization(&ps, &alt);
		else
			ps.f_sort(&ps, 1, 0);
		push_swap_clear(&ps);
		push_swap_clear(&alt);
	}
	return (0);
}

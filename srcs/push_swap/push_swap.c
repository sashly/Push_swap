/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:55:41 by sashly            #+#    #+#             */
/*   Updated: 2021/04/29 21:56:03 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc > 1)
	{
		push_swap_init(&ps);
		if (!ps_parse_args(&ps.a, 1, argc - 1, argv) && ps_stack_clear(&ps.a))
			return (write(PS_STDERR, "Error\n", 6) * 0);
		ps.f_sort(&ps, 1, 0);
		push_swap_clear(&ps);
	}
	return (0);
}

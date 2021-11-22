/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:26:35 by sashly            #+#    #+#             */
/*   Updated: 2021/04/15 13:26:47 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_print_int_count_digits(int nbr)
{
	int	cd;

	cd = 0;
	if (!nbr)
		cd++;
	if (nbr < 0)
		cd++;
	while (nbr)
	{
		cd++;
		nbr /= 10;
	}
	return (cd);
}

static void	ps_print_stack_width(t_push_swap *ps, int *w)
{
	t_dllist	*tmp_dl;
	int			tmp_w;

	w[0] = 1;
	w[1] = 1;
	tmp_dl = ps->a.head;
	while (tmp_dl)
	{
		tmp_w = ps_print_int_count_digits(tmp_dl->val);
		if (tmp_w > w[0])
			w[0] = tmp_w;
		tmp_dl = tmp_dl->next;
	}
	tmp_dl = ps->b.head;
	while (tmp_dl)
	{
		tmp_w = ps_print_int_count_digits(tmp_dl->val);
		if (tmp_w > w[1])
			w[1] = tmp_w;
		tmp_dl = tmp_dl->next;
	}
}

static void	ps_print_stack_elem(int val, int stack_w, const char *color,
								const char *off)
{
	int	cd;

	cd = ps_print_int_count_digits(val);
	write(PS_STDOUT, color, PS_COLOR_S);
	write(PS_STDOUT, off, ft_strlen((char *)off));
	write(PS_STDOUT, PS_PAD, stack_w - cd);
	ft_putnbr_fd(val, PS_STDOUT);
	write(PS_STDOUT, "|", 1);
}

static int	ps_print_tail(int *w, const char *color1, const char *color2)
{
	write(PS_STDOUT, color1, PS_COLOR_S);
	write(PS_STDOUT, PS_PAD, 1 + w[0] / 2);
	write(PS_STDOUT, "^", 1);
	write(PS_STDOUT, color2, PS_COLOR_S);
	write(PS_STDOUT, PS_PAD, (w[0] - 1 - (w[0] / 2)) + w[1] / 2 + 3);
	write(PS_STDOUT, "^", 1);
	write(PS_STDOUT, "\n", 1);
	write(PS_STDOUT, color1, PS_COLOR_S);
	write(PS_STDOUT, "|", 1);
	write(PS_STDOUT, PS_PAD, w[0] / 2);
	write(PS_STDOUT, "a", 1);
	write(PS_STDOUT, PS_PAD, w[0] - 1 - w[0] / 2);
	write(PS_STDOUT, "|", 1);
	write(PS_STDOUT, color2, PS_COLOR_S);
	write(PS_STDOUT, " |", 2);
	write(PS_STDOUT, PS_PAD, w[1] / 2);
	write(PS_STDOUT, "b", 1);
	write(PS_STDOUT, PS_PAD, w[1] - 1 - w[1] / 2);
	write(PS_STDOUT, "|", 1);
	write(PS_STDOUT, "\n", 1);
	write(PS_STDOUT, PS_RESET_COL, PS_RESCOL_S);
	return (w[0] + w[1] + 5);
}

int	ps_print(t_push_swap *ps, const char *color1, const char *color2)
{
	t_dllist	*tmp[2];
	int			w[2];
	int			i;

	i = ft_max2i(ps->a.size, ps->b.size);
	ps_print_stack_width(ps, w);
	tmp[0] = ps->a.head;
	tmp[1] = ps->b.head;
	while (i > 0)
	{
		if (i <= ps->a.size)
		{
			ps_print_stack_elem(tmp[0]->val, w[0], color1, "|");
			tmp[0] = tmp[0]->next;
		}
		else
			write(PS_STDOUT, PS_PAD, w[0] + 2);
		if ((i--) <= ps->b.size)
		{
			ps_print_stack_elem(tmp[1]->val, w[1], color2, " |");
			tmp[1] = tmp[1]->next;
		}
		write(PS_STDOUT, "\n", 1);
	}
	return (ps_print_tail(w, color1, color2));
}

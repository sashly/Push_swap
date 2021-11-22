/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:52:14 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:55:15 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"
# include "ds_dllist.h"

# define PS_STDIN	0
# define PS_STDOUT	1
# define PS_STDERR	2

# define PS_BLACK		"\033[30m"
# define PS_RED			"\033[31m"
# define PS_GREEN		"\033[32m"
# define PS_YELLOW		"\033[33m"
# define PS_BLUE		"\033[34m"
# define PS_PURPLE		"\033[35m"
# define PS_CYAN		"\033[36m"
# define PS_WHITE		"\033[37m"
# define PS_COL_DEF		"\033[39m"
# define PS_RESET_COL	"\033[0m"
# define PS_COLOR_S		5
# define PS_RESCOL_S	4

# define PS_PAD		"                              "
# define PS_SEP		"------------------------------"
# define PS_PAD_S	30

typedef struct s_stack
{
	t_dllist	*head;
	t_dllist	*tail;
	int			size;
}							t_stack;

typedef struct s_push_swap	t_push_swap;

typedef void				(*t_op_funct)(t_push_swap *, int, int);

typedef void				(*t_ft_sort)(t_push_swap *, int, int);

# define PS_SA			0
# define PS_SB			1
# define PS_SS			2
# define PS_PA			3
# define PS_PB			4
# define PS_RA			5
# define PS_RB			6
# define PS_RR			7
# define PS_RRA			8
# define PS_RRB			9
# define PS_RRR			10

# define PS_HELP_M		-1
# define PS_NORM_M		0
# define PS_DEBUG_M		1
# define PS_MANUAL_M	2
# define PS_MANUAL_E	3
# define PS_ALT_ALG_D	4
# define PS_ALT_ALG_1	5
# define PS_ALT_ALG_2	6
# define PS_ALT_ALG_3	7
# define PS_COMP_D		8
# define PS_COMP_1		9
# define PS_COMP_2		10
# define PS_COMP_3		11

# define PS_VISUAL		1

# define PS_COLM_DEF	0
# define PS_COLM_COL	1

struct	s_push_swap
{
	t_stack		a;
	t_stack		b;
	t_stack		a_copy;
	t_op_funct	f_op[11];
	t_ft_sort	f_sort;
	t_stack		*rec;
	int			option_m;
	int			col_m;
	char		*color_a;
	char		*color_b;
};

void	push_swap_init(t_push_swap *ps);
int		push_swap_clear(t_push_swap *ps);
int		ps_stack_clear(t_stack *a);
void	ps_stack_set_null(t_stack *st);
void	ps_push_front(t_stack *stk, int value);
int		push_swap_copy_stack(t_stack *dest, t_stack *src);
int		ps_parse_args(t_stack *a, int argc_begin, int argc_end, char **argv);
int		ps_print(t_push_swap *ps, const char *color1, const char *color2);

int		ps_ck_parse_argv(int argc, char **argv, t_push_swap *ps);
int		ps_ck_read_instructions(t_push_swap *ps, int input);
int		ps_ck_print_help(t_push_swap *ps);
int		ps_ck_operation_case(char *operation);

int		ps_parse_argv(int argc, char **argv, t_push_swap *ps);

void	ps_operation_sa(t_push_swap *ps, int print, int rec);
void	ps_operation_sb(t_push_swap *ps, int print, int rec);
void	ps_operation_ss(t_push_swap *ps, int print, int rec);
void	ps_operation_pa(t_push_swap *ps, int print, int rec);
void	ps_operation_pb(t_push_swap *ps, int print, int rec);
void	ps_operation_ra(t_push_swap *ps, int print, int rec);
void	ps_operation_rb(t_push_swap *ps, int print, int rec);
void	ps_operation_rr(t_push_swap *ps, int print, int rec);
void	ps_operation_rra(t_push_swap *ps, int print, int rec);
void	ps_operation_rrb(t_push_swap *ps, int print, int rec);
void	ps_operation_rrr(t_push_swap *ps, int print, int rec);

void	ps_bubble_sort(t_push_swap *ps, int print, int rec);
void	ps_insertion_sort(t_push_swap *ps, int print, int rec);
void	ps_selection_sort(t_push_swap *ps, int print, int rec);
void	ps_quick_sort(t_push_swap *ps, int print, int rec);

void	ps_qsort_fill_chunks(int *chunks, int size_old);
int		ps_select_sort_ba_chunk(t_push_swap *ps, int depth, int print, int rec);

int		ps_stack_is_sorted(t_stack *st);
void	ps_arrange_two(t_push_swap *ps, int print, int rec);
void	ps_arrange_three(t_push_swap *ps, int print, int rec);
void	ps_stack_min_max(t_stack *st, int *min, int *max);
int		ps_find_stack_median(t_stack *st, int depth, int *median);
int		ps_get_stack_route(t_stack *st, int val, int *op);
int		ps_get_lookup(t_stack *st, int **lookup, int depth);

#endif

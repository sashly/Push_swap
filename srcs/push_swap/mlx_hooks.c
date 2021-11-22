/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:35:35 by sashly            #+#    #+#             */
/*   Updated: 2021/04/29 21:36:03 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void 	hooks_exit(t_mlx_ptrs *p)
{
	push_swap_clear(p->ps);
	push_swap_clear(p->alt);
	mlx_destroy_image(p->mlx, p->wimg->img);
	free(p->wimg);
	exit(EXIT_SUCCESS);
}

int	hmlx_red_cross(t_mlx_ptrs *p)
{
	hooks_exit(p);
	return (1);
}

int	hooks_mlx_main(int k, t_mlx_ptrs *p)
{
	if (k == HOOK_ESC)
		hooks_exit(p);
	else if (k == HOOK_SPACE)
		p->play ^= 1;
	else if (k == HOOK_RIGHT)
		p->mv_f = 1;
	else if (k == HOOK_LEFT)
		p->mv_b = 1;
	return (1);
}

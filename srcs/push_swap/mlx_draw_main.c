/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:26:49 by sashly            #+#    #+#             */
/*   Updated: 2021/04/29 21:28:30 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void 	mlx_draw_playback_forward(t_mlx_ptrs *p, t_ps_grid *grid,
								  t_dllist **it, t_dllist **it_a)
{
	if (*it)
	{
		p->ps->f_op[(*it)->val](p->ps, 0, 0);
		if ((*it)->prev)
			*it = (*it)->prev;
	}
	if (*it_a)
	{
		p->alt->f_op[(*it_a)->val](p->alt, 0, 0);
		if ((*it_a)->prev)
			*it_a = (*it_a)->prev;
	}
	p->mv_f = 0;
	mlx_draw_push_swap(p, p->ps, grid, 0);
	if (*it_a)
		mlx_draw_push_swap(p, p->alt, grid, 1);
}

void 	mlx_draw_playback_back(t_mlx_ptrs *p, t_ps_grid *grid,
							   t_dllist **it, t_dllist **it_a)
{
	if ((*it) && (*it)->next)
	{
		*it = (*it)->next;
		p->ps->f_op[ps_get_opposite_op((*it)->val)](p->ps, 0, 0);
	}
	if ((*it_a) && (*it_a)->next)
	{
		*it_a = (*it_a)->next;
		p->alt->f_op[ps_get_opposite_op((*it_a)->val)](p->alt, 0, 0);
	}
	p->mv_b = 0;
	mlx_draw_push_swap(p, p->ps, grid, 0);
	if (*it_a)
		mlx_draw_push_swap(p, p->alt, grid, 1);
}

void 	mlx_draw_playback_arrows(t_mlx_ptrs *p, t_ps_grid *grid,
								 t_dllist **it, t_dllist **it_a)
{
	ft_mlx_draw_rect(p->wimg, gv2i(0, 0), gv2i(p->wres, p->hres), PS_MLX_BCOL);
	if (p->mv_f)
		mlx_draw_playback_forward(p, grid, it, it_a);
	else if (p->mv_b)
		mlx_draw_playback_back(p, grid, it, it_a);
}

void	mlx_draw_playback(t_mlx_ptrs *p, t_ps_grid *grid,
						  t_dllist **it, t_dllist **it_a)
{
	if (p->play)
	{
		ft_mlx_draw_rect(p->wimg, gv2i(0, 0),
			gv2i(p->wres, p->hres), PS_MLX_BCOL);
		if (*it)
		{
			p->ps->f_op[(*it)->val](p->ps, 0, 0);
			*it = (*it)->prev;
		}
		if (*it_a)
		{
			p->ps->f_op[(*it_a)->val](p->alt, 0, 0);
			*it_a = (*it_a)->prev;
		}
		mlx_draw_push_swap(p, p->ps, grid, 0);
		if (p->ps->option_m >= PS_COMP_1)
			mlx_draw_push_swap(p, p->alt, grid, 1);
	}
	else if (p->mv_f || p->mv_b)
		mlx_draw_playback_arrows(p, grid, it, it_a);
}

void	mlx_draw_main(t_mlx_ptrs *p, t_ps_grid *grid)
{
	t_dllist	*it;
	t_dllist	*it_a;

	it_a = NULL;
	it = p->ps->rec->tail;
	if (p->ps->option_m >= PS_COMP_1)
		it_a = p->alt->rec->tail;
	ft_mlx_draw_rect(p->wimg, gv2i(0, 0), gv2i(p->wres, p->hres), PS_MLX_BCOL);
	while (1)
	{
		mlx_do_sync(p->mlx);
		mlx_draw_playback(p, grid, &it, &it_a);
		mlx_put_image_to_window(p->mlx, p->win, p->wimg->img, 0, 0);
		mlx_hook(p->win, 2, 1L << 0, &hooks_mlx_main, p);
		mlx_hook(p->win, 17, 1L << 2, &hmlx_red_cross, p);
	}
}

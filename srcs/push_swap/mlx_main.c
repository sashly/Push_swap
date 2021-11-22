/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:36:15 by sashly            #+#    #+#             */
/*   Updated: 2021/04/29 21:50:58 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	ps_init_grid(t_ps_grid *grid, t_vec2i res, int cmp)
{
	grid[0].col_bg = PS_MLX_BCOL;
	grid[0].col_sa = PS_MLX_COL1;
	grid[0].col_sb = PS_MLX_COL2;
	grid[0].offs_w = (int)(PS_GRID_OFFS_W * (float)res.xi);
	grid[0].offs_hu = (int)(PS_GRID_OFFS_HU * (float)res.yi);
	grid[0].offs_hd = (int)(PS_GRID_OFFS_HD * (float)res.yi);
	grid[0].ws2 = res.xi - 2 * grid[0].offs_w;
	grid[0].offs_b = (int)(PS_GRID_OFFS_B * (float)grid[0].ws2);
	grid[0].ws = (grid[0].ws2 - grid[0].offs_b) / 2;
	grid[0].hs = res.yi - grid[0].offs_hu - grid[0].offs_hd;
	grid[0].pa = gv2i(grid[0].offs_w, grid[0].offs_hu + grid[0].hs);
	grid[0].pb = gv2i(grid[0].offs_w + grid[0].offs_b + grid[0].ws,
			grid[0].offs_hu + grid[0].hs);
	grid[0].h_step = (int)((float)grid[0].hs / (float)grid[0].nbr_size);
	grid[0].offs_wnm = (int)((float)grid[0].ws * PS_GRID_OFFS_N_MIN);
	if (cmp)
	{
		ft_memcpy((void *)(&grid[1]), (void *)(&grid[0]), sizeof(t_ps_grid));
		grid[1].pa = gv2i(res.xi + grid[1].offs_w,
				grid[1].offs_hu + grid[1].hs);
		grid[1].pb = gv2i(grid[1].pa.xi + grid[1].offs_b + grid[1].ws,
				grid[1].offs_hu + grid[1].hs);
		grid[1].col_sa = PS_MLX_COL3;
		grid[1].col_sb = PS_MLX_COL4;
	}
}

int	ft_mlx_init_ptrs(t_push_swap *ps, t_push_swap *alt, t_mlx_ptrs *p,
					  t_ps_grid *grid)
{
	p->win = NULL;
	p->wimg = NULL;
	p->wres = R_MLX_WIDTH;
	p->hres = R_MLX_HEIGHT;
	p->ps = ps;
	p->alt = alt;
	grid[0].nbr_size = ps->a.size;
	ps_stack_min_max(&ps->a, &grid[0].n_min, &grid[0].n_max);
	if (ps->option_m >= PS_COMP_1)
	{
		ps_init_grid(grid, gv2i(p->wres / 2, p->hres), 1);
		ps_stack_clear(&p->alt->a);
		push_swap_copy_stack(&p->alt->a, &p->alt->a_copy);
	}
	else
		ps_init_grid(grid, gv2i(p->wres, p->hres), 0);
	ps_stack_clear(&p->ps->a);
	push_swap_copy_stack(&p->ps->a, &p->ps->a_copy);
	p->wimg = (t_img *)malloc(sizeof(t_img));
	if (!p->wimg)
		return (0);
	p->play = 1;
	p->mv_f = 0;
	p->mv_b = 0;
	return (1);
}

int	mlx_draw_push_swap_val(t_ps_grid *g, int col_s, t_vec2i c, int *nbr_w)
{
	double	col_cf;
	int		col;

	*nbr_w = g[c.xi].offs_wnm + (int)(((float)(g[c.xi].ws
					- g[c.xi].offs_wnm)) * ((float)(c.yi - g[c.xi].n_min)
				/ (float)(g[c.xi].n_max - g[c.xi].n_min)));
	col_cf = PS_COL_CFF - (PS_COL_CFF - 1.) * ((float)(c.yi - g[c.xi].n_min)
			/ (float)(g[c.xi].n_max - g[c.xi].n_min));
	col = ft_add_shade(col_s, (double)col_cf);
	return (col);
}

void	mlx_draw_push_swap(t_mlx_ptrs *p, t_push_swap *ps, t_ps_grid *g, int c)
{
	t_dllist	*it;
	int			nbr_w;
	int			h_tmp;
	int			col;

	it = ps->a.tail;
	h_tmp = g[c].offs_hu + g[c].hs;
	while (it)
	{
		col = mlx_draw_push_swap_val(g, g[c].col_sa, gv2i(c, it->val), &nbr_w);
		ft_mlx_draw_rectd(p->wimg, gv2i(g[c].pa.xi, h_tmp),
			gv2i(nbr_w, g[c].h_step), col);
		h_tmp -= g[c].h_step;
		it = it->prev;
	}
	it = ps->b.tail;
	h_tmp = g[c].offs_hu + g[c].hs;
	while (it)
	{
		col = mlx_draw_push_swap_val(g, g[c].col_sb, gv2i(c, it->val), &nbr_w);
		ft_mlx_draw_rectd(p->wimg, gv2i(g[c].pb.xi, h_tmp),
			gv2i(nbr_w, g[c].h_step), col);
		h_tmp -= g[c].h_step;
		it = it->prev;
	}
}

int	mlx_main(t_push_swap *ps, t_push_swap *alt)
{
	t_mlx_ptrs	p;
	t_ps_grid	grid[2];

	p.mlx = mlx_init();
	ft_mlx_init_ptrs(ps, alt, &p, grid);
	p.win = mlx_new_window(p.mlx, p.wres, p.hres, "Push_Swap");
	ft_mlx_get_wimg(&p);
	mlx_draw_main(&p, grid);
	mlx_loop(p.mlx);
	return (1);
}

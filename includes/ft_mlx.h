/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:49:03 by sashly            #+#    #+#             */
/*   Updated: 2021/04/30 11:51:59 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include "push_swap.h"

# include <mlx.h>

typedef struct s_vec2i
{
	int	xi;
	int	yi;
}				t_vec2i;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		img_w;
	int		img_h;
	char	*name;
}				t_img;

typedef struct s_mlx_ptrs
{
	void		*mlx;
	void		*win;
	t_img		*wimg;
	t_push_swap	*ps;
	t_push_swap	*alt;
	int			wres;
	int			hres;
	int			play;
	int			mv_f;
	int			mv_b;
}				t_mlx_ptrs;

# define R_MLX_WIDTH		800
# define R_MLX_HEIGHT		1200

# define PS_MLX_BCOL		0x1E1C2E
# define PS_MLX_BCOL_A		0x1A172E
# define PS_MLX_COL1		0x6C95ED
# define PS_MLX_COL2		0x955CCA
# define PS_MLX_COL3		0x59B045
# define PS_MLX_COL4		0xABDA58
# define PS_MLX_COL5		0x7EE0ED
# define PS_MLX_COL6		0xDC4F76

# define COL_T				0
# define COL_R				1
# define COL_G				2
# define COL_B				3

# define PS_GRID_OFFS_W		0.05
# define PS_GRID_OFFS_HU	0.05
# define PS_GRID_OFFS_HD	0.1
# define PS_GRID_OFFS_B		0.035
# define PS_GRID_OFFS_N_MIN	0.05
# define PS_COL_CFF			1.55

# define HOOK_ESC			53
# define HOOK_SPACE			49
# define HOOK_LEFT			123
# define HOOK_RIGHT			124

typedef struct s_ps_grid
{
	int		ws2;
	int		ws;
	int		hs;
	int		offs_w;
	int		offs_hu;
	int		offs_hd;
	int		offs_b;
	t_vec2i	pa;
	t_vec2i	pb;
	int		h_step;
	int		offs_wnm;
	int		col_bg;
	int		col_sa;
	int		col_sb;
	int		nbr_size;
	int		n_min;
	int		n_max;
}				t_ps_grid;

int		mlx_main(t_push_swap *ps, t_push_swap *alt);
int		ft_mlx_get_wimg(t_mlx_ptrs *p);
void	mlx_draw_main(t_mlx_ptrs *p, t_ps_grid *grid);
void	mlx_draw_push_swap(t_mlx_ptrs *p, t_push_swap *ps, t_ps_grid *g, int c);

t_vec2i	gv2i(int xi, int yi);
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_mlx_draw_rect(t_img *img, t_vec2i point, t_vec2i res, int col);
void	ft_mlx_draw_rectd(t_img *img, t_vec2i point, t_vec2i res, int col);
int		ps_get_opposite_op(int op);

int		hmlx_red_cross(t_mlx_ptrs *ptrs);
int		hooks_mlx_main(int k, t_mlx_ptrs *p);

int		ft_add_shade(int trgb, double distance);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:09:36 by sashly            #+#    #+#             */
/*   Updated: 2021/04/29 21:34:18 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_trgb_components(int trgb, int component)
{
	if (component == COL_T)
		return ((trgb >> 24) & 0xFF);
	else if (component == COL_R)
		return ((trgb >> 16) & 0xFF);
	else if (component == COL_G)
		return ((trgb >> 8) & 0xFF);
	else if (component == COL_B)
		return (trgb & 0xFF);
	return (1);
}

int	ft_add_shade(int trgb, double distance)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = ft_trgb_components(trgb, COL_T);
	r = ft_trgb_components(trgb, COL_R);
	g = ft_trgb_components(trgb, COL_G);
	b = ft_trgb_components(trgb, COL_B);
	r = (int)(r * distance);
	if (r > 255)
		r = 255;
	g = (int)(g * distance);
	if (g > 255)
		g = 255;
	b = (int)(b * distance);
	if (b > 255)
		b = 255;
	return (get_trgb(t, r, g, b));
}

int	ft_mlx_get_wimg(t_mlx_ptrs *p)
{
	p->wimg->img = mlx_new_image(p->mlx, p->wres, p->hres);
	if (!p->wimg->img)
		return (0);
	p->wimg->addr = mlx_get_data_addr(p->wimg->img, &p->wimg->bpp,
			&p->wimg->line_len, &p->wimg->endian);
	if (!p->wimg->addr)
		return (0);
	p->wimg->img_w = p->wres;
	p->wimg->img_h = p->hres;
	return (1);
}

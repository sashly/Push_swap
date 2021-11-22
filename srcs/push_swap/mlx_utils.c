/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:08:55 by sashly            #+#    #+#             */
/*   Updated: 2021/04/29 21:14:02 by sashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

t_vec2i	gv2i(int xi, int yi)
{
	t_vec2i	ret;

	ret.xi = xi;
	ret.yi = yi;
	return (ret);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_mlx_draw_rect(t_img *img, t_vec2i point, t_vec2i res, int col)
{
	int	x;
	int	y;

	y = point.yi;
	while (y < point.yi + res.yi)
	{
		x = point.xi;
		while (x < point.xi + res.xi)
			ft_mlx_pixel_put(img, x++, y, col);
		y++;
	}
}

void	ft_mlx_draw_rectd(t_img *img, t_vec2i point, t_vec2i res, int col)
{
	int	x;
	int	y;

	y = point.yi;
	while (y > point.yi - res.yi)
	{
		x = point.xi;
		while (x < point.xi + res.xi)
			ft_mlx_pixel_put(img, x++, y, col);
		y--;
	}
}

int	ps_get_opposite_op(int op)
{
	if (op == PS_SA || op == PS_SB || op == PS_SS)
		return (op);
	else if (op == PS_RA || op == PS_RB || op == PS_RR)
		return (op + 3);
	else if (op == PS_RRA || op == PS_RRB || op == PS_RRR)
		return (op - 3);
	else if (op == PS_PA)
		return (PS_PB);
	else if (op == PS_PB)
		return (PS_PA);
	return (-1);
}

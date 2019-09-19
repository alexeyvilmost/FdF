/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:57:57 by pallspic          #+#    #+#             */
/*   Updated: 2019/09/19 21:16:19 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	pixel(t_main data, t_coor where, int color)
{
	return (mlx_pixel_put(data.mlx, data.win, where.x, where.y,
						(data.color_mode) ? color : 0xFFFFFF));
}

static int	color_calc(t_coor from, t_coor where, t_line info)
{
	t_color	d;

	d.min_color = (from.color > where.color) ? where.color : from.color;
	d.dif_color = ft_abs(from.color - where.color) / 257;
	d.size = ft_abs((info.div > 1) ? from.y - where.y : from.x - where.x);
	d.curr = ft_abs((info.div > 1) ? info.cr.y - from.y : info.cr.x - from.x);
	d.curr = (from.z < where.z) ? d.size - d.curr : d.curr;
	d.colr = (d.size) ? trunc(((double)d.curr / (double)d.size) *
										(double)d.dif_color) : 0;
	d.result = d.min_color + d.colr * 257;
	if (!d.dif_color)
		return (d.min_color);
	return (d.result);
}

static void	draw_sline(t_main data, t_coor from, t_coor where, t_line info)
{
	if (info.cr.x == where.x)
		while (info.cr.y != where.y)
		{
			pixel(data, info.cr, color_calc(from, where, info));
			info.cr.y += info.i.y;
		}
	else
		while (info.cr.x != where.x)
		{
			pixel(data, info.cr, color_calc(from, where, info));
			info.cr.x += info.i.x;
		}
}

static void	draw_line(t_main d, t_coor f, t_coor w)
{
	t_line	i;

	i.dx = ft_abs(f.x - w.x);
	i.dy = ft_abs(f.y - w.y);
	i.div = (double)i.dy / (double)i.dx;
	i.i = newc((f.x > w.x) ? -1 : 1, (f.y > w.y) ? -1 : 1);
	i.error = 0;
	i.cr = newc(f.x, f.y);
	if (i.cr.x == w.x || i.cr.y == w.y)
		return (draw_sline(d, f, w, i));
	while (i.cr.x != w.x && i.cr.y != w.y)
	{
		i.error += i.div;
		pixel(d, i.cr, color_calc(f, w, i));
		while (i.error >= 1)
		{
			i.error--;
			i.cr.y += i.i.y;
			if (i.error >= 1)
				pixel(d, i.cr, color_calc(f, w, i));
		}
		i.cr.x += i.i.x;
	}
}

void		print_map(t_main data, t_coor **y)
{
	int i;
	int j;

	i = -1;
	while (++i < data.m)
	{
		j = -1;
		while (++j < data.n)
		{
			pixel(data, y[i][j], y[i][j].color);
			if (j != data.n - 1)
				draw_line(data, y[i][j], y[i][j + 1]);
			if (i != data.m - 1)
				draw_line(data, y[i][j], y[i + 1][j]);
		}
		free(y[i]);
	}
	free(y);
}

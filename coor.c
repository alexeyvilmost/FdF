/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:55:25 by pallspic          #+#    #+#             */
/*   Updated: 2019/09/20 00:33:13 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	flex_window(t_main *main)
{
	main->height = main->dy * (2 * (ft_min(main->n, main->m)) +
			ft_abs(main->m - main->n) + 2) + main->max_z * main->dz;
	main->weight = main->dx * (2 * (ft_min(main->n, main->m)) +
			ft_abs(main->m - main->n) + 2);
	if ((main->height > 1080 || main->weight > 1920) && (main->dy > 2
				&& main->dx > 3 && main->dz > 1))
	{
		main->dx -= 3;
		main->dy -= 2;
		main->dz -= 1;
		return (flex_window(main));
	}
	if (main->n >= main->m)
		main->basex = (main->weight / 2) + (ft_abs(main->n - main->m)
				* (main->dx / 2));
	else
		main->basex = (main->weight / 2) - (ft_abs(main->n - main->m)
				* (main->dx / 2));
}

void	struct_init(t_main *main, t_coor base, t_coor diffs, int diff_z)
{
	(void)base;
	main->dx = diffs.x;
	main->dy = diffs.y;
	main->dz = diff_z;
	flex_window(main);
	main->projection = 1;
	main->mlx = mlx_init();
	main->win = mlx_new_window(main->mlx, main->weight, main->height, "FdF");
	main->basey = main->height - (main->dy * 2);
	ft_printf("Usage:\nScroll - zoom\nArrows - movement\n"
			"Mouse buttons - change altitude\nEsc - exit\n"
			"Space - color mode\n\"P\" - change projection\n");
}

t_coor	new_full(t_main d, int curr, t_coor b, t_coor i)
{
	t_coor new;

	if (d.projection)
	{
		new.x = b.x - d.dx * i.y;
		new.y = b.y - i.y * d.dy - (curr * d.dz);
	}
	else
	{
		new.x = d.basex - d.dx * i.y;
		new.y = d.basey - i.x * d.dx;
	}
	new.z = curr * d.dz;
	if ((new.z / 2) < 256)
		new.color = 0xFFFFFF - (new.z / 2) * 257;
	else
		new.color = 0xFF0000;
	return (new);
}

t_coor	newc(short x, short y)
{
	t_coor	new;

	new.x = x;
	new.y = y;
	return (new);
}

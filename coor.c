/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:55:25 by pallspic          #+#    #+#             */
/*   Updated: 2019/09/19 18:18:15 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	struct_init(t_main *main, t_coor base, t_coor diffs, int diff_z)
{
	main->m = 0;
	main->n = 0;
	main->dx = diffs.x;
	main->dy = diffs.y;
	main->dz = diff_z;
	main->basex = base.x;
	main->basey = base.y;
	main->projection = 1;
	main->mlx = mlx_init();
	main->win = mlx_new_window(main->mlx, 1920, 1080, "fdf by pallspic");
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
		new.x = d.basex - d.dy * i.y;
		new.y = d.basey - i.x * d.dy;
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

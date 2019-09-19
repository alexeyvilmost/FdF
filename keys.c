/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:00:09 by pallspic          #+#    #+#             */
/*   Updated: 2019/09/19 18:22:00 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		close_(void *params)
{
	(void)params;
	exit(0);
}

int		key_press(int key, t_main *data)
{
	if (key == 53)
		return (close_(NULL));
	if ((key >= 123 && key <= 126) || key == 49)
	{
		mlx_clear_window(data->mlx, data->win);
		if (key == 123)
			data->basex -= 10;
		else if (key == 124)
			data->basex += 10;
		else if (key == 125)
			data->basey += 10;
		else if (key == 126)
			data->basey -= 10;
		else if (key == 49)
			data->color_mode = !data->color_mode;
		print_map(*data, fill_map(data->raw_data, *data));
	}
	else if (key == 35)
	{
		mlx_clear_window(data->mlx, data->win);
		data->projection = !data->projection;
		print_map(*data, fill_map(data->raw_data, *data));
	}
	return (0);
}

int		mouse_press(int key, int x, int y, t_main *data)
{
	(void)(x * y);
	if (key == 1 || key == 2 || key == 4 || key == 5)
	{
		mlx_clear_window(data->mlx, data->win);
		if (key == 1)
			data->dz += 3;
		else if (key == 2 && data->dz >= 5)
			data->dz -= 3;
		else if (key == 2)
			data->dz = 0;
		else if (key == 4)
		{
			data->dx += 3;
			data->dy += 2;
			data->dz += 1;
		}
		else if (key == 5 && data->dx > 7 && data->dy > 4 && data->dz > 1)
		{
			data->dx -= 3;
			data->dy -= 2;
			data->dz -= 1;
		}
		print_map(*data, fill_map(data->raw_data, *data));
	}
	return (0);
}

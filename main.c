/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:55:31 by pallspic          #+#    #+#             */
/*   Updated: 2019/09/19 17:35:09 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		main(int ac, char **av)
{
	t_main	data;
	int		fd;

	if (ac != 2)
		return (ft_printf("Usage: ./fdf 'path_to_file_name'\n") * 0);
	struct_init(&data, newc(BASEX, BASEY), newc(DIFFX, DIFFY), DIFFZ);
	fd = open(av[1], O_RDONLY);
	data.raw_data = input_init(fd, &data);
	print_map(data, fill_map(data.raw_data, data));
	mlx_key_hook(data.win, key_press, &data);
	mlx_mouse_hook(data.win, mouse_press, &data);
	mlx_hook(data.win, 17, 1L << 17, close_, NULL);
	mlx_loop(data.mlx);
	return (0);
}

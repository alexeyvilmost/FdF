/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:55:31 by pallspic          #+#    #+#             */
/*   Updated: 2019/09/19 22:54:26 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		main(int ac, char **av)
{
	t_main	data;
	int		fd;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (ft_printf("Usage: ./fdf 'path_to_file_name'\n") * 0);
	if (fd == -1)
		return (ft_printf("Can't open file %s\n", av[1]) * 0);
	data.n = 0;
	data.m = 0;
	data.raw_data = input_init(fd, &data);
	struct_init(&data, newc(BASEX, BASEY), newc(DIFFX, DIFFY), DIFFZ);
	print_map(data, fill_map(data.raw_data, data));
	mlx_key_hook(data.win, key_press, &data);
	mlx_mouse_hook(data.win, mouse_press, &data);
	mlx_hook(data.win, 17, 1L << 17, close_, NULL);
	mlx_loop(data.mlx);
	close_(&data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:59:00 by pallspic          #+#    #+#             */
/*   Updated: 2019/09/20 00:33:48 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define BASEX 900
# define BASEY 1079
# define DIFFX 30
# define DIFFY 20
# define DIFFZ 10

typedef struct {
	int		min_color;
	int		dif_color;
	int		size;
	int		curr;
	int		result;
	int		colr;
}			t_color;

typedef struct
{
	short	x;
	short	y;
	short	z;
	int		color;
}			t_coor;

typedef struct
{
	int		n;
	int		m;
	int		dz;
	int		dy;
	int		dx;
	int		max_z;
	int		basey;
	int		basex;
	int		height;
	int		weight;
	int		*raw_data;
	void	*mlx;
	void	*win;
	_Bool	projection;
	_Bool	color_mode;
}			t_main;

typedef struct
{
	short	dx;
	short	dy;
	double	div;
	t_coor	i;
	t_coor	cr;
	double	error;
}			t_line;

void		print_map(t_main data, t_coor **input);
t_coor		**fill_map(const int *main, t_main data);
int			*input_init(int fd, t_main *data);
int			mouse_press(int key, int x, int y, t_main *data);
int			key_press(int key, t_main *data);
int			close_(t_main *data);
void		struct_init(t_main *main, t_coor base, t_coor diffs, int diff_z);
t_coor		newc(short x, short y);
t_coor		new_full(t_main d, int curr, t_coor b, t_coor i);

#endif

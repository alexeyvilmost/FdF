/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pallspic <pallspic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:55:38 by pallspic          #+#    #+#             */
/*   Updated: 2019/09/20 00:33:13 by pallspic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_coor	**fill_map(const int *m, t_main d)
{
	int		i;
	int		j;
	int		by;
	int		bx;
	t_coor	**ret;

	bx = d.basex;
	by = d.basey;
	i = -1;
	ret = (t_coor **)ft_memalloc(sizeof(t_coor *) * d.m);
	while (++i < d.m)
	{
		j = -1;
		ret[i] = (t_coor *)ft_memalloc(sizeof(t_coor) * d.n);
		while (++j < d.n)
			ret[i][j] = new_full(d, m[i * d.n + j], newc(bx, by), newc(i, j));
		by -= d.dy;
		bx += d.dx;
	}
	return (ret);
}

int		*vector_conv(t_list *main, t_main *data)
{
	t_list	*temp;
	int		*vector;
	int		i;

	i = 0;
	temp = main;
	(data->m) ? data->n /= data->m : 0;
	data->max_z = 0;
	vector = (int *)ft_memalloc(data->n * data->m * sizeof(int));
	while (i < data->n * data->m)
	{
		if (temp->content > data->max_z)
			data->max_z = temp->content;
		vector[i++] = temp->content;
		temp = temp->next;
	}
	ft_lstdel(&main);
	return (vector);
}

int		*input_init(int fd, t_main *data)
{
	t_list	*main;
	t_list	*temp;
	char	**nums;
	char	*line;
	int		i;

	main = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		nums = ft_strsplit(line, ' ');
		i = 0;
		while (nums && nums[i])
		{
			temp = ft_lstnew(ft_atoi(nums[i]));
			ft_lstadd(&main, temp);
			main = temp;
			data->n++;
			free(nums[i]);
			i++;
		}
		free(nums);
		free(line);
		data->m++;
	}
	return (vector_conv(main, data));
}

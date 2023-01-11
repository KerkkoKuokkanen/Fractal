/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:16:10 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/03/11 13:32:08 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

// seven is the number of different possible color combinations for this code

int	out2(int keycode, t_zoom *zm)
{
	if (keycode == 53)
	{
		mlx_destroy_image(zm->mlx, zm->img_ptr);
		free(zm);
		exit(0);
	}
	if (keycode == 49)
	{
		if (zm->col_pallet < 7)
			zm->col_pallet++;
		else
			zm->col_pallet = 1;
		thread_worker(zm);
		mlx_put_image_to_window(zm->mlx, zm->win, zm->img_ptr->image, 0, 0);
	}
	return (0);
}

int	ft_mouse2(int button, int x, int y, t_zoom *zm)
{
	double		cx;
	double		cy;

	if (button == 4 && x > 0 && x < WIN_WIDTH_BOX
		&& y > 0 && y < WIN_HEIGHT_BOX)
	{
		cx = (zm->x_start + ((double)x / WIN_WIDTH_BOX)
				* (zm->x_end - zm->x_start));
		cy = (zm->y_start + ((double)y / WIN_HEIGHT_BOX)
				* (zm->y_end - zm->y_start));
		zm->x_start = zm->x_start + (fabs(zm->x_start - cx) * 0.1);
		zm->y_start = zm->y_start + (fabs(zm->y_start - cy) * 0.1);
		zm->x_end = zm->x_end - (fabs(zm->x_end - cx) * 0.1);
		zm->y_end = zm->y_end - (fabs(zm->y_end - cy) * 0.1);
		zm->delta_num *= 0.9;
		zm->color_map = 1.0 / ((zm->delta_num)
				/ fmax(WIN_HEIGHT_BOX, WIN_WIDTH_BOX)) * COLOR;
		thread_worker(zm);
		mlx_put_image_to_window(zm->mlx, zm->win, zm->img_ptr->image, 0, 0);
	}
	else if (button == 5 && x > 0 && x < WIN_WIDTH_BOX
		&& y > 0 && y < WIN_HEIGHT_BOX)
		zm_out_box(x, y, zm);
	return (0);
}

void	draw_choose(t_brot_zoom *zm)
{
	if (zm->j_b == 0)
		draw_machine_brot(zm, 0, 0);
	else if (zm->j_b == 1)
		draw_machine_julia(zm, 0, 0);
	else
		draw_machine_ship(zm, 0, 0);
}

int	ft_mouse(int button, int x, int y, t_brot_zoom *zm)
{
	if (button == 4 && x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		if (zm->zoom_lock == 0)
			zm->zoom_lock = 1;
		zm_in(x, y, zm);
	}
	else if (button == 5 && x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT)
	{
		if (zm->zoom_lock == 0)
			zm->zoom_lock = 1;
		zm_out(x, y, zm);
	}
	return (0);
}

int	out(int keycode, t_brot_zoom *zm)
{
	int	i;

	i = 0;
	if (keycode == 53)
	{
		mlx_destroy_image(zm->mlx, zm->ptr_img);
		free(zm);
		exit(0);
	}
	if (keycode == 49)
	{
		while (i < 20)
		{
			zm->color = rand() % 0xFFFFFF;
			i++;
		}
		draw_choose(zm);
	}
	return (0);
}

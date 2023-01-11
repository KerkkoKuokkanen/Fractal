/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:10:23 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/03/11 13:32:44 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	line_saver(t_zoom *zm, void	*mlx, void	*win, t_image *img)
{
	zm->mlx = mlx;
	zm->win = win;
	zm->img_ptr = img;
}

// -8 and 8 symbolize the complex plain start and end on both axis
// delta is the distanse between start and end on axis
// colormap makes the color nice according to zoom
// col_pallet determines the bits set for color. It is not random colors
// different x values are for the four areas of the window

void	initialize(t_zoom *zm)
{
	zm->x = 0;
	zm->x1 = 200;
	zm->x2 = 400;
	zm->x3 = 600;
	zm->col_pallet = 1;
	zm->x_start = -8;
	zm->y_start = -8;
	zm->x_end = 8;
	zm->y_end = 8;
	zm->delta_num = 16;
	zm->color_map = 1.0 / ((zm->delta_num)
			/ fmax(WIN_HEIGHT_BOX, WIN_WIDTH_BOX)) * COLOR;
}

// these x cordinates are for each chunk
// so for each 200 pixel area in the for the x-axis

void	x_val_initialize(t_zoom *zm)
{
	zm->x = 0;
	zm->x1 = 200;
	zm->x2 = 400;
	zm->x3 = 600;
}

// The intiger tells us what fractal we want to draw

void	find_brot_vs_julia(t_brot_zoom *zm, int brot_julia)
{
	zm->j_b = brot_julia;
	zm->color = 0xF0F0F0;
	if (zm->j_b == 0)
	{
		zm->re_start = -2;
		zm->re_end = 1;
		zm->im_start = -1;
		zm->im_end = 1;
	}
	else if (zm->j_b == 1)
	{
		zm->re_start = -2.5;
		zm->re_end = 2.5;
		zm->im_start = -2;
		zm->im_end = 2;
		zm->zoom_lock = 0;
	}
	else
	{
		zm->re_start = -2.2;
		zm->re_end = 1.2;
		zm->im_start = -1.7;
		zm->im_end = 0.7;
	}
}

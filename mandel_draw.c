/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:22:27 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/03/01 16:17:05 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_machine_brot(t_brot_zoom *zm, double x, double y)
{
	double	c;
	double	c1;
	int		color;
	int		m;

	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGHT)
		{
			c = (zm->re_start + (x / WIN_WIDTH) * (zm->re_end - zm->re_start));
			c1 = (zm->im_start + (y / WIN_HEIGHT)
					* (zm->im_end - zm->im_start));
			m = number(c, c1);
			if (m != 0)
				color = 0xfffffff - (int)(m * 0xfffffff / MAX_ITER);
			else
				color = 0;
			set_pixel_bort(zm->ptr_img, color, x, y);
			y++;
		}
		x++;
		y = 0;
	}
	mlx_put_image_to_window(zm->mlx, zm->win, zm->ptr_img->image, 0, 0);
}

void	draw_machine_julia(t_brot_zoom *zm, double x, double y)
{
	double	c;
	double	c1;
	int		color;
	int		m;

	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGHT)
		{
			c = (zm->re_start + (x / WIN_WIDTH) * (zm->re_end - zm->re_start));
			c1 = (zm->im_start + (y / WIN_HEIGHT)
					* (zm->im_end - zm->im_start));
			m = julia(c, c1, zm->c_c, zm->c_c1);
			if (m != 0)
				color = zm->color - (int)(m * zm->color / MAX_ITER);
			else
				color = 0;
			set_pixel_bort(zm->ptr_img, color, x, y);
			y++;
		}
		x++;
		y = 0;
	}
	mlx_put_image_to_window(zm->mlx, zm->win, zm->ptr_img->image, 0, 0);
}

void	draw_machine_ship(t_brot_zoom *zm, double x, double y)
{
	double	c;
	double	c1;
	int		color;
	int		m;

	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGHT)
		{
			c = (zm->re_start + (x / WIN_WIDTH) * (zm->re_end - zm->re_start));
			c1 = (zm->im_start + (y / WIN_HEIGHT) * (zm->im_end - zm->im_start));
			m = burning_ship(c, c1);
			if (m != 0)
				color = zm->color - (int)(m * zm->color / MAX_ITER);
			else
				color = 0;
			set_pixel_bort(zm->ptr_img, color, x, y);
			y++;
		}
		x++;
		y = 0;
	}
	mlx_put_image_to_window(zm->mlx, zm->win, zm->ptr_img->image, 0, 0);
}

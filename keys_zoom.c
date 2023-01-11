/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:02:15 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/06/01 15:20:42 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zm_out(int x, int y, t_brot_zoom *zm)
{
	double	c;
	double	c1;

	c = (zm->re_start + ((double)x / WIN_WIDTH)
			* (zm->re_end - zm->re_start));
	c1 = (zm->im_start + ((double)y / WIN_HEIGHT)
			* (zm->im_end - zm->im_start));
	zm->re_start = zm->re_start - (fabs(zm->re_start - c) * 1.01);
	zm->re_end = zm->re_end + (fabs(zm->re_end - c) * 1.01);
	zm->im_start = zm->im_start - (fabs(zm->im_start - c1) * 1.01);
	zm->im_end = zm->im_end + (fabs(zm->im_end - c1) * 1.01);
	draw_choose(zm);
}

void	zm_in(int x, int y, t_brot_zoom *zm)
{
	double	c;
	double	c1;

	c = (zm->re_start + ((double)x / WIN_WIDTH) * (zm->re_end - zm->re_start));
	c1 = (zm->im_start + ((double)y / WIN_HEIGHT)
			* (zm->im_end - zm->im_start));
	zm->re_start = zm->re_start + (fabs(zm->re_start - c) * 0.1);
	zm->re_end = zm->re_end - (fabs(zm->re_end - c) * 0.1);
	zm->im_start = zm->im_start + (fabs(zm->im_start - c1) * 0.1);
	zm->im_end = zm->im_end - (fabs(zm->im_end - c1) * 0.1);
	draw_choose(zm);
}

void	zm_out_box(int x, int y, t_zoom *zm)
{
	double		cx;
	double		cy;

	cx = (zm->x_start + ((double)x / WIN_WIDTH_BOX)
			* (zm->x_end - zm->x_start));
	cy = (zm->y_start + ((double)y / WIN_HEIGHT_BOX)
			* (zm->y_end - zm->y_start));
	zm->x_start = zm->x_start - (fabs(zm->x_start - cx) * 0.1);
	zm->y_start = zm->y_start - (fabs(zm->y_start - cy) * 0.1);
	zm->x_end = zm->x_end + (fabs(zm->x_end - cx) * 0.1);
	zm->y_end = zm->y_end + (fabs(zm->y_end - cy) * 0.1);
	zm->delta_num = zm->delta_num * 1.1;
	zm->color_map = 1.0 / ((zm->delta_num)
			/ fmax(WIN_HEIGHT_BOX, WIN_WIDTH_BOX)) * COLOR;
	thread_worker(zm);
	mlx_put_image_to_window(zm->mlx, zm->win, zm->img_ptr->image, 0, 0);
}

int	ft_mouse_move(int x, int y, t_brot_zoom *zm)
{
	if (x > 0 && x < WIN_WIDTH && y > 0 && y < WIN_HEIGHT && zm->zoom_lock == 0)
	{
		zm->c_c = (zm->re_start + ((double)x / WIN_WIDTH)
				* (zm->re_end - zm->re_start));
		zm->c_c1 = (zm->im_start + ((double)y / WIN_HEIGHT)
				* (zm->im_end - zm->im_start));
		draw_choose(zm);
	}
	return (0);
}

void	init_lines(t_brot_zoom *zm, t_image *img, void *win, void *mlx)
{
	zm->ptr_img = img;
	zm->win = win;
	zm->mlx = mlx;
}

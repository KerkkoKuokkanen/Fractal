/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_draw_machines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:46:20 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/03/01 16:01:13 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// The reason for many drawing functions is that multithreading does not
// relly work well when trying to run the same function multiple times at the
// same time.

double	mandelbox(double cx, double cy, int n)
{
	double	dot;
	double	d;
	double	zx;
	double	zy;

	d = 1.0;
	zx = cx;
	zy = cy;
	while (n < MAX_ITER)
	{
		ballfold_boxfold(&zx, &zy, &d, &dot);
		zx = SCALE * zx + cx;
		zy = SCALE * zy + cy;
		d = d * SCALE + 1.0;
		if (dot > BOUND)
			break ;
		n++;
	}
	return (sqrt(zx * zx + zy * zy) / d);
}

void	*draw_machine1(void *cp)
{
	t_draw_tool	d;
	t_zoom		*zm;

	zm = (t_zoom *)cp;
	while (zm->x < FRIST_CHUNCK)
	{
		d.y = 0;
		while (d.y < WIN_HEIGHT_BOX)
		{
			d.cx = (zm->x_start + ((double)zm->x / WIN_WIDTH_BOX)
					* (zm->x_end - zm->x_start));
			d.cy = (zm->y_start + ((double)d.y / WIN_HEIGHT_BOX)
					* (zm->y_end - zm->y_start));
			d.val = fmin((int)(mandelbox(d.cx, d.cy, 0)
						* zm->color_map), COLOR);
			color_check(zm, &d.color, &d.val);
			set_pixel(zm->img_ptr, d.color, zm->x, d.y);
			d.y++;
		}
		zm->x++;
	}
	return (NULL);
}

void	*draw_machine2(void *cp)
{
	t_draw_tool	d;
	t_zoom		*zm;

	zm = (t_zoom *)cp;
	while (zm->x1 < SECOND_CHUNK)
	{
		d.y = 0;
		while (d.y < WIN_HEIGHT_BOX)
		{
			d.cx = (zm->x_start + ((double)zm->x1 / WIN_WIDTH_BOX)
					* (zm->x_end - zm->x_start));
			d.cy = (zm->y_start + ((double)d.y / WIN_HEIGHT_BOX)
					* (zm->y_end - zm->y_start));
			d.val = fmin((int)(mandelbox(d.cx, d.cy, 0)
						* zm->color_map), COLOR);
			color_check(zm, &d.color, &d.val);
			set_pixel(zm->img_ptr, d.color, zm->x1, d.y);
			d.y++;
		}
		zm->x1++;
	}
	return (NULL);
}

void	*draw_machine3(void *cp)
{
	t_draw_tool	d;
	t_zoom		*zm;

	zm = (t_zoom *)cp;
	while (zm->x2 < THIRD_CHUNK)
	{
		d.y = 0;
		while (d.y < WIN_HEIGHT_BOX)
		{
			d.cx = (zm->x_start + ((double)zm->x2 / WIN_WIDTH_BOX)
					* (zm->x_end - zm->x_start));
			d.cy = (zm->y_start + ((double)d.y / WIN_HEIGHT_BOX)
					* (zm->y_end - zm->y_start));
			d.val = fmin((int)(mandelbox(d.cx, d.cy, 0)
						* zm->color_map), COLOR);
			color_check(zm, &d.color, &d.val);
			set_pixel(zm->img_ptr, d.color, zm->x2, d.y);
			d.y++;
		}
		zm->x2++;
	}
	return (NULL);
}

void	*draw_machine4(void *cp)
{
	t_draw_tool	d;
	t_zoom		*zm;

	zm = (t_zoom *)cp;
	while (zm->x3 < LAST_CHUNK)
	{
		d.y = 0;
		while (d.y < WIN_HEIGHT_BOX)
		{
			d.cx = (zm->x_start + ((double)zm->x3 / WIN_WIDTH_BOX)
					* (zm->x_end - zm->x_start));
			d.cy = (zm->y_start + ((double)d.y / WIN_HEIGHT_BOX)
					* (zm->y_end - zm->y_start));
			d.val = fmin((int)(mandelbox(d.cx, d.cy, 0)
						* zm->color_map), COLOR);
			color_check(zm, &d.color, &d.val);
			set_pixel(zm->img_ptr, d.color, zm->x3, d.y);
			d.y++;
		}
		zm->x3++;
	}
	return (NULL);
}

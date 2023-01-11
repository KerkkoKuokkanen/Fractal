/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:40:41 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/02/24 17:10:11 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <strings.h>
#include <complex.h>

#define WIN_WIDTH 1200
#define WIN_HEIGHT 1200
#define PII 3.1415926535
#define MAX_ITER 20

typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;

typedef struct		t_zoom
{
	double re_start;
	double re_end;
	double im_start;
	double im_end;
}					t_zoom;


static void	ft_bzero2(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = '\0';
		i++;
	}
}

static void	*ft_memalloc(size_t size)
{
	void	*alloc;

	alloc = malloc(size);
	if (alloc == NULL)
		return (NULL);
	ft_bzero2(alloc, size);
	return (alloc);
}

static int out(int keycode)
{
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}

static void	set_pixel(t_image *img, int color, int x, int y)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_WIDTH)
		return ;
	*(int*)(img->ptr + (((int)x + (int)y * WIN_WIDTH) * img->bpp)) = color;
}

double	mandelboxDist(double zx, double zy, double zz)
{
	int i = 0;
	double d = 1.0;
	double cx = zx;
	double cy = zy;
	double cz = zz;
	double dot;
	double scale = 2.0;
	double inversion;

	while (i < MAX_ITER)
	{
		if (zx > 1.0) zx = 2.0-zx;
		else if (zx < -1.0) zx = -2.0-zx;
		if (zy > 1.0) zy = 2.0-zy;
		else if (zy < -1.0) zy = -2.0-zy;
		if (zz > 1.0) zz = 2.0-zz;
		else if (zz <- 1.0) zz = -2.0-zz;

		dot = zx*zx+zy*zy+zz*zz;
		if (dot < 0.5)
		{
			zx *= 2.0;
			zy *= 2.0;
			zz *= 2.0;
			d *= 2.0;
		}
		else if (dot < 1.0)
		{
			inversion = 1.0/dot;
			zx *= inversion;
			zy *= inversion;
			zz *= inversion;
			d *= inversion;
		}
		zx = scale*zx+cx;
		zy = scale*zy+cy;
		zz = scale*zz+cz;
		d = d*scale+1.0;
		i++;
	}
	return (sqrt(zx*zx+zy*zy+zz*zz)/d);
}

int main()
{
	double ratio = (double)WIN_HEIGHT / WIN_WIDTH;
	int x = 0;
	int y = 0;
	double maxdist = 50.0;
	double mindist = 0.0001;
	double camera_dir_x;
	double camera_dir_y;
	double camera_dir_z = 1.0;
	double march_x = 0.0;
	double march_y = 0.0;
	double march_z = -25.0;
	double t = 0.0;
	double currdist;
	int steps;
	int color;
	t_zoom	*zm;
	zm = (t_zoom *)malloc(sizeof(t_zoom));
	zm->re_start = -1000;
	zm->re_end = 1000;
	zm->im_start = -1000;
	zm->im_end = 1000;
	void	*mlx;
	void	*win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "test");
	t_image		*img;
	img = ft_memalloc(sizeof(t_image));
	img->image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride, &img->endian);
	img->bpp /= 8;
	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGHT)
		{
			camera_dir_x = (double)x / WIN_WIDTH - 0.5;
			camera_dir_y = ((double)y / WIN_HEIGHT - 0.5) * ratio;
			camera_dir_z = 1.0;
			currdist = maxdist;
			march_x = 0.0;
			march_y = 0.0;
			march_z = -25.0;
			t = 0.0;
			steps = 255;
			while (steps >= 0)
			{
				currdist = mandelboxDist(march_x, march_y, march_z);
				if (currdist < mindist)
					break ;
				t += currdist;
				if (t > maxdist)
					break ;
				march_x = camera_dir_x * t;
				march_y = camera_dir_y * t;
				march_z = camera_dir_z * t - 25.0;
				steps--;
			}
			color = 0;
			if (currdist < mindist)
			{
				color = steps;
				color ^= steps << 16;
				color ^= steps << 8;
			}
			set_pixel(img, color, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx, win, img->image, 0, 0);
	mlx_key_hook(win, &out, zm);
	mlx_loop(mlx);
	return (0);
}

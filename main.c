/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:27:46 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/06/02 11:45:03 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	set_pixel(t_image *img, int color, int x, int y)
{
	if (x < 0 || x >= WIN_WIDTH_BOX || y < 0 || y >= WIN_WIDTH_BOX)
		return ;
	*(int *)(img->ptr + (((int)x + (int)y
					* WIN_WIDTH_BOX) * CAST_JUMP)) = color;
}

void	ballfold_boxfold(double *zx, double *zy, double *d, double *dot)
{
	double	inversion;

	if (*zx > 1.0)
		*zx = 2.0 - *zx;
	else if (*zx < -1.0)
		*zx = -2.0 - *zx;
	if (*zy > 1.0)
		*zy = 2.0 - *zy;
	else if (*zy < -1.0)
		*zy = -2.0 - *zy;
	*dot = *zx * *zx + *zy * *zy;
	if (*dot < 0.5)
	{
		*zx *= 2.0;
		*zy *= 2.0;
		*d *= 2.0;
	}
	else if (*dot < 1.0)
	{
		inversion = 1.0 / *dot;
		*zx *= inversion;
		*zy *= inversion;
		*d *= inversion;
	}
}

static void	mandelbox_formula(void)
{
	void	*mlx;
	void	*win;
	t_image	*img;
	t_zoom	*zm;

	zm = (t_zoom *)malloc(sizeof(t_zoom));
	img = (t_image *)malloc(sizeof(t_image));
	if (zm == NULL || img == NULL)
	{
		printf("memory error\n");
		exit(0);
	}
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH_BOX, WIN_HEIGHT_BOX, "mandelbox");
	img->image = mlx_new_image(mlx, WIN_WIDTH_BOX, WIN_HEIGHT_BOX);
	img->ptr = mlx_get_data_addr(img->image,
			&img->bpp, &img->stride, &img->endian);
	line_saver(zm, mlx, win, img);
	initialize(zm);
	thread_worker(zm);
	mlx_key_hook(win, &out2, zm);
	mlx_hook(win, 4, 0, &ft_mouse2, zm);
	mlx_hook(win, 6, 0, &ft_mouse2, zm);
	mlx_put_image_to_window(zm->mlx, zm->win, zm->img_ptr->image, 0, 0);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	else if (ft_strcmp2(argv[1], "mandelbox") == 0)
		mandelbox_formula();
	else if (ft_strcmp2(argv[1], "mandelbrot") == 0)
		mandelbrot_formula(MANB);
	else if (ft_strcmp2(argv[1], "julia") == 0)
		mandelbrot_formula(JULIA);
	else if (ft_strcmp2(argv[1], "burningship") == 0)
		mandelbrot_formula(SHIP);
	else
		usage();
}

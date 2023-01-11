/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brot_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:23:02 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/06/01 17:54:05 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double c, double c1, double c_c, double c_c1)
{
	double	z;
	double	z1;
	double	temp;
	int		n;

	z = c;
	z1 = c1;
	n = 0;
	while (n < MAX_ITER)
	{
		if (((z1 * z1) + (z * z)) > 4)
			return (n);
		temp = z1;
		z1 = z * z1 + z * z1 + c_c1;
		z = z * z + temp * temp * (-1) + c_c;
		n++;
	}
	return (0);
}

int	number(double c, double c1)
{
	double	z;
	double	z1;
	double	temp;
	int		n;

	z = c;
	z1 = c1;
	n = 0;
	while (n < MAX_ITER)
	{
		if (((z1 * z1) + (z * z)) > 4)
			return (n);
		temp = z1;
		z1 = z * z1 + z * z1 + c1;
		z = z * z + temp * temp * (-1) + c;
		n++;
	}
	return (0);
}

int	burning_ship(double c, double c1)
{
	double	z;
	double	z1;
	double	temp;
	int		n;

	z = c;
	z1 = c1;
	n = 0;
	while (n < MAX_ITER)
	{
		z1 = fabs(z1);
		z = fabs(z);
		if (((z1 * z1) + (z * z)) > 4)
			return (n);
		temp = z1;
		z1 = z * z1 + z * z1 + c1;
		z = z * z + temp * temp * (-1) + c;
		n++;
	}
	return (0);
}

void	set_pixel_bort(t_image *img, int color, int x, int y)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_WIDTH)
		return ;
	*(int *)(img->ptr + (((int)x + (int)y * WIN_WIDTH) * CAST_JUMP)) = color;
}

void	mandelbrot_formula(int brot_julia)
{
	t_brot_zoom	*zm;
	t_image		*img;
	void		*mlx;
	void		*win;

	zm = (t_brot_zoom *)malloc(sizeof(t_brot_zoom));
	if (zm == NULL)
		err1_brot();
	img = (t_image *)malloc(sizeof(t_image));
	if (img == NULL)
		err2_brot(zm);
	find_brot_vs_julia(zm, brot_julia);
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "test");
	img->image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img->ptr = mlx_get_data_addr(img->image,
			&img->bpp, &img->stride, &img->endian);
	init_lines(zm, img, win, mlx);
	draw_choose(zm);
	mlx_key_hook(win, &out, zm);
	mlx_hook(win, 4, 0, &ft_mouse, zm);
	mlx_hook(win, 6, 0, &ft_mouse, zm);
	mlx_hook(win, 6, 0, &ft_mouse_move, zm);
	mlx_loop(mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:23:07 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/03/11 13:23:38 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define WIN_WIDTH_BOX 800
# define WIN_HEIGHT_BOX 800
# define FRIST_CHUNCK 200
# define SECOND_CHUNK 400
# define THIRD_CHUNK 600
# define LAST_CHUNK 800
# define SCALE 2.0
# define CAST_JUMP 4
# define BOUND 36
# define COLOR 255.0
# define WIN_WIDTH 1128
# define WIN_HEIGHT 752
# define MANB 0
# define JULIA 1
# define SHIP 2

// Change MAX_ITER if you want to zoom deeper. Makes the program slower.
# define MAX_ITER 80

# include "minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}				t_image;

typedef struct t_draw_tool
{
	int		val;
	int		color;
	double	cx;
	double	cy;
	int		y;
}				t_draw_tool;

typedef struct t_zoom
{
	int			x;
	int			x1;
	int			x2;
	int			x3;
	int			col_pallet;
	double		x_start;
	double		y_start;
	double		x_end;
	double		y_end;
	long double	delta_num;
	long double	color_map;
	void		*mlx;
	void		*win;
	t_image		*img_ptr;
}				t_zoom;

typedef struct t_brot_zoom
{
	double	re_start;
	double	re_end;
	double	im_start;
	double	im_end;
	double	c_c;
	double	c_c1;
	int		zoom_lock;
	int		j_b;
	int		color;
	t_image	*ptr_img;
	void	*mlx;
	void	*win;
}				t_brot_zoom;

int		julia(double c, double c1, double c_c, double c_c1);
int		number(double c, double c1);
int		burning_ship(double c, double c1);
int		out(int keycode, t_brot_zoom *zm);
int		ft_mouse(int button, int x, int y, t_brot_zoom *zm);
int		out2(int keycode, t_zoom *zm);
int		ft_mouse2(int button, int x, int y, t_zoom *zm);
int		ft_strcmp2(const char *str1, const char *str2);
int		ft_mouse_move(int x, int y, t_brot_zoom *zm);
void	color_check(t_zoom *zm, int *col, int *val);
void	thread_worker(t_zoom *zm);
void	pallet_one(int *col, int *val);
void	usage(void);
void	draw_choose(t_brot_zoom *zm);
void	draw_machine_brot(t_brot_zoom *zm, double x, double y);
void	draw_machine_julia(t_brot_zoom *zm, double x, double y);
void	draw_machine_ship(t_brot_zoom *zm, double x, double y);
void	thread_worker(t_zoom *zm);
void	mandelbrot_formula(int brot_julia);
void	err1_brot(void);
void	err2_brot(t_brot_zoom *zm);
void	err1(void);
void	err2(t_zoom *zm);
void	*draw_machine1(void *cp);
void	*draw_machine2(void *cp);
void	*draw_machine3(void *cp);
void	*draw_machine4(void *cp);
void	zm_out_box(int x, int y, t_zoom *zm);
void	zm_in(int x, int y, t_brot_zoom *zm);
void	zm_out(int x, int y, t_brot_zoom *zm);
void	color_check(t_zoom *zm, int *col, int *val);
void	set_pixel(t_image *img, int color, int x, int y);
void	line_saver(t_zoom *zm, void	*mlx, void	*win, t_image *img);
void	ballfold_boxfold(double *zx, double *zy, double *d, double *dot);
void	initialize(t_zoom *zm);
void	x_val_initialize(t_zoom *zm);
void	find_brot_vs_julia(t_brot_zoom *zm, int brot_julia);
void	set_pixel_bort(t_image *img, int color, int x, int y);
// This function is in keys_zoom.c so that I dont need to create more files
void	init_lines(t_brot_zoom *zm, t_image *img, void *win, void *mlx);
double	mandelbox(double cx, double cy, int n);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:26:22 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/05/30 13:39:05 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	write(1, "usage ./fractol", 16);
	write(1, " (one fractal: mandelbrot, julia, mandelbox, ", 45);
	write(1, "burningship)\n", 13);
	exit(0);
}

int	ft_strcmp2(const char *str1, const char *str2)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		sign = ((unsigned char *)str1)[i] - ((unsigned char *)str2)[i];
		if (sign != 0)
			return (sign);
		i++;
	}
	return (sign);
}

void	pallet_one(int *col, int *val)
{
	*col = *val;
	*col ^= *val << 8;
	*col ^= *val << 16;
}

void	color_check(t_zoom *zm, int *col, int *val)
{
	*col = 0;
	if (zm->col_pallet == 1)
		pallet_one(col, val);
	else if (zm->col_pallet == 2)
		*col = *val;
	else if (zm->col_pallet == 3)
		*col ^= *val << 8;
	else if (zm->col_pallet == 4)
		*col ^= *val << 16;
	else if (zm->col_pallet == 5)
	{
		*col = *val;
		*col ^= *val << 8;
	}
	else if (zm->col_pallet == 6)
	{
		*col ^= *val << 8;
		*col ^= *val << 16;
	}
	else
	{
		*col = *val;
		*col ^= *val << 16;
	}
}

void	thread_worker(t_zoom *zm)
{
	pthread_t	*thread_id;

	thread_id = (pthread_t *)malloc(sizeof(pthread_t) * 4);
	x_val_initialize(zm);
	pthread_create(&thread_id[0], NULL, draw_machine1, (void *)zm);
	pthread_create(&thread_id[1], NULL, draw_machine2, (void *)zm);
	pthread_create(&thread_id[2], NULL, draw_machine3, (void *)zm);
	pthread_create(&thread_id[3], NULL, draw_machine4, (void *)zm);
	pthread_join(thread_id[0], NULL);
	pthread_join(thread_id[1], NULL);
	pthread_join(thread_id[2], NULL);
	pthread_join(thread_id[3], NULL);
	free(thread_id);
}

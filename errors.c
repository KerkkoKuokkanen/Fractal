/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:40:35 by kkuokkan          #+#    #+#             */
/*   Updated: 2022/03/01 14:41:24 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	err1_brot(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	err2_brot(t_brot_zoom *zm)
{
	free(zm);
	write(1, "error\n", 6);
	exit(0);
}

void	err1(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void	err2(t_zoom *zm)
{
	free(zm);
	write(1, "error\n", 6);
	exit(0);
}

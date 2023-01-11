# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 17:03:24 by kkuokkan          #+#    #+#              #
#    Updated: 2022/02/24 17:11:44 by kkuokkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

USER = kkuokkan
GMP_PATH = /Users/$(USER)/.brew/Cellar/gmp/6.2.1_1/lib/libgmp.a
FLAGS = -Wall -Wextra -Werror
F_WORK = -framework OpenGL -framework Appkit
MLX = -lmlx

all:
	@@gcc $(FLAGS) gmp_test.c $(MLX) $(F_WORK) $(GMP_PATH)

gmp:
	@@gcc $(FLAGS) gmp_test.c $(MLX) $(F_WORK) $(GMP_PATH)

3d:
	@@gcc $(FLAGS) 3d_box.c $(MLX) $(F_WORK)

fclean:
	rm -f a.out
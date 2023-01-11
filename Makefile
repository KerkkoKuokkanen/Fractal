# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 11:49:44 by kkuokkan          #+#    #+#              #
#    Updated: 2022/03/08 15:03:12 by kkuokkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Wextra -Werror
F_WORK = -framework OpenGL -framework Appkit
MLX = -lmlx
SRCS = main.c brot_main.c errors.c box_draw_machines.c initialize.c keys.c	\
		mandel_draw.c misc.c keys_zoom.c
OFILES = $(SRCS:.c=.o)
HDR = fractol.h

all: $(NAME)

$(NAME):
	@@gcc $(FLAGS) -c $(SRCS) -I $(HDR)
	@@gcc -o $(NAME) $(OFILES) -I $(HDR) $(MLX) $(F_WORK)

clean:
	@@rm -f $(OFILES);

fclean: clean
	@@rm -f fractol

re: fclean all
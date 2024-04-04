# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 12:41:30 by aglanuss          #+#    #+#              #
#    Updated: 2024/04/04 12:52:03 by aglanuss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror -Imlx

SRC = src/main.c src/utils/fractol_init.c src/utils/ft_error_print.c\
			src/utils/look_error.c src/utils/ft_atod.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

# ? MAC
GNOME_FLAGS = -framework OpenGL -framework AppKit
GNOME_PATH = ./minilibx-mac/
MLX_PATH = $(GNOME_PATH)/libmlx.a

FLAGS = -I $(GNOME_PATH) -I includes/fractol.h $(CFLAGS)

all : _mlx $(NAME)

$(NAME) : $(OBJECTS) $(MLX_PATH) includes/fractol.h Makefile
	$(CC) $(FLAGS) $(OBJECTS) $(MLX_PATH) $(GNOME_FLAGS) -o $(NAME)

%.o : %.c includes/fractol.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean :
	make clean -C $(GNOME_PATH)
	rm -f $(OBJECTS)

fclean : clean
	make clean -C $(GNOME_PATH)
	rm -f $(NAME)

re : fclean all

_mlx :
	make -C $(GNOME_PATH)

.PHONY: all clean fclean re _mlx
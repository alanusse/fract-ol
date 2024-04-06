# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglanuss <aglanuss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 12:41:30 by aglanuss          #+#    #+#              #
#    Updated: 2024/04/07 00:08:58 by aglanuss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Imlx

SRCS = src/main.c

INCLUDES = includes/fractol.h

OBJS = $(SRCS:.c=.o)

MLX_PATH = lib/mlx

all: $(NAME)

$(MLX_PATH)/libmlx.a:
	$(MAKE) -C $(MLX_PATH)

$(NAME): $(MLX_PATH)/libmlx.a $(OBJS) Makefile
	$(CC) $(FLAGS) $(OBJS) -Llib/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	$(MAKE) -C $(MLX_PATH) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

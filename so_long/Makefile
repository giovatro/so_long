# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 15:18:22 by gtroiano          #+#    #+#              #
#    Updated: 2024/01/16 15:18:30 by gtroiano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

C_FLAGS = -Werror -Wextra -Wall
MLX_FLAGS = -Lminilibx -lmlx -framework OpenGL -framework AppKit

MLX = minilibx/
LIBFT = libft/

LIBRARY = libft/libft.a minilibx/libmlx.a

SOURCE = logic/*.c

COMPILE = $(CC) $(C_FLAGS) $(MLX_FLAGS) $(SOURCE) $(LIBRARY) -o $(NAME)

all:
		make -C $(MLX)
		make -C $(LIBFT)
		$(COMPILE)

clean:

fclean: clean
		make clean -C $(MLX)
		make clean -C $(LIBFT)
		rm -rf $(NAME)

re: fclean all
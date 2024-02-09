# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtroiano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 12:10:33 by gtroiano          #+#    #+#              #
#    Updated: 2024/02/08 12:10:37 by gtroiano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror


SOURCE = \
		ft_atoi.c\
		ft_calloc.c\
		ft_isdigit.c\
		ft_strchr.c\
		ft_strjoin.c\
		ft_strlen.c\
		ft_strnstr.c\
		ft_printf.c\
	    ft_putchar.c\
	    ft_putstr.c\
	    ft_putptr.c\
	    ft_putnbr.c\
	    ft_putuint.c\
	    ft_puthex.c\
		get_next_line_utils.c\
		get_next_line.c\
		utils.c

OBJECTS = $(SOURCE:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAG) -o $@ -c $<

$(NAME):	$(OBJECTS)
					ar rc  $(NAME) $(OBJECTS)
					ranlib $(NAME)
clean:				
					rm -f $(OBJECTS)
fclean:		clean	
					rm -f $(NAME)

re:			fclean all
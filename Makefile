# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrache <akrache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/20 16:10:39 by akrache           #+#    #+#              #
#    Updated: 2019/11/02 16:53:12 by akrache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS = main.c fractal/mandel.c hooks/hook.c hooks/key1.c colors/pixels.c \
		fractal/julia.c colors/colormode.c hooks/key2.c fractal/burning.c \
		hooks/key3.c hooks/key4.c hooks/key5.c colors/palette.c colors/palette2.c \
		fractal/tippetts.c hooks/key6.c fractal/thorn.c fractal/sativa.c\

OBJECT = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(LIBFT):
	@make -C libft

$(NAME) : $(LIBFT) $(OBJECT)
	$(CC) $(FLAGS) -I/usr/local/include $(LIBFT) $(OBJECT) -o $(NAME) -L/usr/local/lib/ -lmlx -framework OpenGL -framework Appkit

%.o: %.c fract.h
	$(CC) -I/usr/local/include -o $@ -c $< $(FLAGS)

.PHONY: clean

clean:
	/bin/rm -rf $(OBJECT)
	@make clean -C libft

fclean: clean
	/bin/rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

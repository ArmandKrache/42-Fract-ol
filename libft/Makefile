# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrache <akrache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:30:18 by akrache           #+#    #+#              #
#    Updated: 2018/12/03 13:35:23 by akrache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -I ./

SRCS = ft_putchar.c ft_putstr.c ft_strdup.c ft_strlen.c ft_isdigit.c \
		ft_isalpha.c ft_isalnum.c ft_memset.c ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcpy.c ft_strncpy.c \
		ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_bzero.c \
		ft_putendl.c ft_putnbr.c ft_memalloc.c ft_memdel.c ft_strnew.c \
		ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putnbr_fd.c ft_putendl_fd.c ft_lstadd.c ft_lstdel.c  ft_lstdelone.c  \
		ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_nb_digit.c ft_swap.c ft_strrev.c \
		ft_lstlen.c ft_lstiteri.c ft_lstaddback.c ft_strndup.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
		gcc $(CFLAGS) -c $(SRCS)
	    ar -rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
	    /bin/rm -f $(OBJS)

fclean: clean
	    /bin/rm -f $(NAME)

re: fclean all

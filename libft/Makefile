# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lufranco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 12:32:19 by lufranco          #+#    #+#              #
#    Updated: 2017/12/26 15:30:36 by lufranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_memset.c	\
	   get_next_line.c \
	   ft_bzero.c	\
	   ft_memcpy.c	\
	   ft_memccpy.c	\
	   ft_memmove.c	\
	   ft_memchr.c	\
	   ft_memcmp.c	\
	   ft_strlen.c	\
	   ft_strdup.c	\
	   ft_strcpy.c	\
	   ft_strncpy.c	\
	   ft_strcat.c	\
	   ft_strncat.c	\
	   ft_strlcat.c	\
	   ft_strchr.c	\
	   ft_strrchr.c	\
	   ft_strstr.c	\
	   ft_strnstr.c	\
	   ft_strcmp.c	\
	   ft_strncmp.c	\
	   ft_atoi.c	\
	   ft_isalpha.c	\
	   ft_isdigit.c	\
	   ft_isalnum.c	\
	   ft_isascii.c	\
	   ft_isprint.c	\
	   ft_toupper.c	\
	   ft_tolower.c	\
	   ft_memalloc.c	\
	   ft_memdel.c	\
	   ft_strnew.c	\
	   ft_strdel.c	\
	   ft_strclr.c	\
	   ft_striter.c	\
	   ft_striteri.c	\
	   ft_strmap.c	\
	   ft_strmapi.c	\
	   ft_strequ.c	\
	   ft_strnequ.c	\
	   ft_strsub.c	\
	   ft_strjoin.c	\
	   ft_strtrim.c	\
	   ft_strsplit.c	\
	   ft_itoa.c	\
	   ft_putchar.c	\
	   ft_putstr.c	\
	   ft_putendl.c	\
	   ft_putnbr.c	\
	   ft_putchar_fd.c	\
	   ft_putstr_fd.c	\
	   ft_putendl_fd.c	\
	   ft_putnbr_fd.c

OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: fclean all fclean

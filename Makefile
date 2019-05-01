# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swarner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/21 21:41:29 by swarner           #+#    #+#              #
#    Updated: 2019/04/21 21:41:31 by swarner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB_NAME = libft.a
FLAGS = -Wall -Wextra -Werror -c
HEADERS = ./includes
SRCS = src/logic.c src/main.c src/validation.c src/tools.c
OBJ = logic.o main.o validation.o tools.o
LIB_SRCS = 	lib/ft_strlen.c \
			lib/ft_putchar.c \
			lib/ft_putstr.c \
			lib/ft_strdup.c \
			lib/ft_atoi.c \
			lib/ft_strcpy.c \
			lib/ft_strncpy.c \
			lib/ft_strcmp.c \
			lib/ft_strncmp.c \
			lib/ft_isdigit.c \
			lib/ft_isprint.c \
			lib/ft_isascii.c \
			lib/ft_isalnum.c \
			lib/ft_isalpha.c \
			lib/ft_toupper.c \
			lib/ft_tolower.c \
			lib/ft_memset.c \
			lib/ft_bzero.c \
			lib/ft_memcpy.c \
			lib/ft_memccpy.c \
			lib/ft_memmove.c \
			lib/ft_memchr.c \
			lib/ft_memcmp.c \
			lib/ft_strcat.c \
			lib/ft_strncat.c \
			lib/ft_strlcat.c \
			lib/ft_strchr.c \
			lib/ft_strrchr.c \
			lib/ft_strstr.c \
			lib/ft_strnstr.c \
			lib/ft_putendl.c \
			lib/ft_putnbr.c \
			lib/ft_putchar_fd.c \
			lib/ft_putstr_fd.c \
			lib/ft_putendl_fd.c \
			lib/ft_putnbr_fd.c \
			lib/ft_memalloc.c \
			lib/ft_memdel.c \
			lib/ft_strnew.c \
			lib/ft_strdel.c \
			lib/ft_strclr.c \
			lib/ft_striter.c \
			lib/ft_striteri.c \
			lib/ft_strmap.c \
			lib/ft_strmapi.c \
			lib/ft_strequ.c \
			lib/ft_strnequ.c \
			lib/ft_strsub.c \
			lib/ft_strjoin.c \
			lib/ft_strtrim.c \
			lib/ft_itoa.c \
			lib/ft_strsplit.c \
			lib/ft_lstnew.c \
			lib/ft_lstadd.c \
			lib/ft_lstdelone.c \
			lib/ft_lstdel.c \
			lib/ft_lstiter.c \
			lib/ft_lstmap.c \
			lib/ft_rejoin.c \
			lib/ft_strjoin_free.c \
			lib/get_next_line.c \
			lib/ft_lstadd_end.c \
			lib/ft_lsthead_del.c \
			lib/ft_addnode.c

LIB_OBJ = 	ft_strlen.o \
			ft_putchar.o \
			ft_putstr.o \
			ft_strdup.o \
			ft_atoi.o \
			ft_strcpy.o \
			ft_strncpy.o \
			ft_strcmp.o \
			ft_strncmp.o \
			ft_isdigit.o \
			ft_isprint.o \
			ft_isascii.o \
			ft_isalnum.o \
			ft_isalpha.o \
			ft_toupper.o \
			ft_tolower.o \
			ft_memset.o \
			ft_bzero.o \
			ft_memcpy.o \
			ft_memccpy.o \
			ft_memmove.o \
			ft_memchr.o \
			ft_memcmp.o \
			ft_strcat.o \
			ft_strncat.o \
			ft_strlcat.o \
			ft_strchr.o \
			ft_strrchr.o \
			ft_strstr.o \
			ft_strnstr.o \
			ft_putendl.o \
			ft_putnbr.o \
			ft_putchar_fd.o \
			ft_putstr_fd.o \
			ft_putendl_fd.o \
			ft_putnbr_fd.o \
			ft_memalloc.o \
			ft_memdel.o \
			ft_strnew.o \
			ft_strdel.o \
			ft_strclr.o \
			ft_striter.o \
			ft_striteri.o \
			ft_strmap.o \
			ft_strmapi.o \
			ft_strequ.o \
			ft_strnequ.o \
			ft_strsub.o \
			ft_strjoin.o \
			ft_strtrim.o \
			ft_itoa.o \
			ft_strsplit.o \
			ft_lstnew.o \
			ft_lstadd.o \
			ft_lstdelone.o \
			ft_lstdel.o \
			ft_lstiter.o \
			ft_lstmap.o \
			ft_rejoin.o \
			ft_strjoin_free.o \
			get_next_line.o \
			ft_lstadd_end.o \
			ft_lsthead_del.o \
			ft_addnode.o

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I $(HEADERS) $(LIB_SRCS)
	ar rc $(LIB_NAME) $(LIB_OBJ)
	ranlib $(LIB_NAME)
	gcc $(FLAGS) -I $(HEADERS) $(SRCS)
	gcc $(OBJ) -L. -lft -o $(NAME)

leak_check: re
	valgrind --leak-check=full ./$(NAME) 1.txt

clean:
	/bin/rm -f $(OBJ) $(LIB_OBJ)

fclean: clean
	/bin/rm -f $(NAME) $(LIB_NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swarner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/21 21:41:29 by swarner           #+#    #+#              #
#    Updated: 2019/05/14 15:44:10 by gfoote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB_NAME = libft.a
FLAGS = -Wall -Wextra -Werror -c -g -O0
HEADERS = ./includes
SRC = logic_tools.c main.c validation.c tools.c logic.c
SRCDIR = src
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(SRC:.c=.o)
LIB_SRC = 	ft_strlen.c ft_putchar.c ft_putstr.c ft_strdup.c ft_atoi.c \
            ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_isdigit.c \
            ft_isprint.c ft_isascii.c ft_isalnum.c ft_isalpha.c ft_toupper.c \
            ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
            ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcat.c ft_strncat.c \
            ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
            ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_lstadd.c \
            ft_putendl_fd.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
            ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
            ft_putnbr_fd.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
            ft_strtrim.c ft_itoa.c ft_strsplit.c ft_lstnew.c ft_addnode.c \
            ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_rejoin.c \
            ft_strjoin_free.c get_next_line.c ft_lstadd_end.c ft_lsthead_del.c \
			ft_addnode_dlist.c ft_dlisthead_del.c ft_dlistadd_end.c \
			ft_dlist_new.c
LIBDIR = lib
LIB_SRCS = $(addprefix $(LIBDIR)/, $(LIB_SRC))
OBJDIR = objs
LIB_OBJS = $(addprefix $(OBJDIR)/, $(LIB_OBJ))
LIB_OBJ = $(LIB_SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I $(HEADERS) $(LIB_SRCS)
	@ar rc $(LIB_NAME) $(LIB_OBJ)
	@mkdir -p $(OBJDIR);
	@mv $(LIB_OBJ) $(OBJDIR)/
	@ranlib $(LIB_NAME)
	@gcc $(FLAGS) -I $(HEADERS) $(SRCS)
	@gcc $(OBJ) -L. -lft -o $(NAME)

leak_check: re
	@valgrind --leak-check=full ./$(NAME) 1.txt

clean:
	@/bin/rm -f $(OBJ) 
	@/bin/rm -rf $(OBJDIR)
	@rm -f .DS_STORE

fclean: clean
	@/bin/rm -f $(NAME) $(LIB_NAME)

re: fclean all

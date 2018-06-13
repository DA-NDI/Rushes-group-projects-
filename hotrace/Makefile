#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolgin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 18:42:23 by avolgin           #+#    #+#              #
#    Updated: 2018/03/25 21:43:10 by avolgin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = hotrace

SRC_HOTRACE = ./main.c \
		./hash_func.c \
		./hash_func_jenk.c \
		./del_hash_table.c

SRC_GET = ./get/ft_bzero.c \
		./get/ft_lstadd.c \
		./get/ft_memcpy.c \
		./get/ft_memdel.c \
		./get/ft_memset.c \
		./get/ft_memmove.c \
		./get/ft_strcat.c \
		./get/ft_strlcat.c \
		./get/ft_strlen.c \
		./get/ft_strncpy.c \
		./get/ft_memalloc.c \
		./get/ft_strchr.c \
		./get/ft_strdup.c \
		./get/ft_strjoin.c \
		./get/ft_strsub.c \
		./get/get_next_line.c \
		./get/ft_putendl.c \
		./get/ft_putchar.c \
		./get/ft_putstr.c \
		./get/ft_strcmp.c

OBJECT_GET = $(SRC_GET:.c=.o)

OBJECT_HR = $(SRC_HOTRACE:.c=.o)

FLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes/

all: $(NAME)

$(NAME) : $(OBJECT_HR)
		gcc -g -Os -o $(NAME) $(FLAGS) $(SRC_HOTRACE) $(SRC_GET) -I $(INCLUDES)
%.o: %.c
		@gcc $(FLAGS) -o $@ -c $<
clean:
		@/bin/rm -f $(OBJECT_HR)
fclean: clean
		@/bin/rm -f $(NAME)
re:		fclean all

tags:
		rm -f TAGS
		etags -e -R *.c *.h

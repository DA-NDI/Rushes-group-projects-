#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolgin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 18:42:23 by avolgin           #+#    #+#              #
#    Updated: 2018/05/16 17:20:26 by avolgin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Power\ 4

SRC_POW =./puissance.c valid.c play.c play2.c check_win.c print.c

OBJECT_POW = $(SRC_POW:.c=.o)

FLAGS = -Wall -Wextra

INCLUDES_MLX = -I /usr/local/include

LIBFT = ./libft/libftprintf.a

MLX_LIB = -L /usr/local/lib/

FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

SDL = -F /Library/Frameworks -framework SDL2

all: $(NAME)

$(NAME) : $(OBJECT_POW)
		make -C ./libft
		gcc -g -o $(NAME) $(FLAGS) $(INCLUDES_MLX) $(OBJECT_POW) $(LIBFT) \
		$(MLX_LIB) $(FRAMEWORK) -lpthread -lncurses $(SDL)
%.o: %.c
		gcc -g $(FLAGS) -o $@ -c $<
clean:
		make -C ./libft clean
		/bin/rm -f $(OBJECT_POW)
fclean: clean
		/bin/rm -f ./libft/libftprintf.a
		/bin/rm -f $(NAME)
re:		fclean all tags

tags:
		rm -f TAGS
		etags -R *.c *.h

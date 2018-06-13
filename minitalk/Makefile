#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolgin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 18:42:23 by avolgin           #+#    #+#              #
#    Updated: 2018/05/20 17:56:01 by dpolosuk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_CLIENT = ./client_src/client.c

SRC_SERVER = ./server_src/server.c

OBJECT_CLIENT = $(SRC_CLIENT:.c=.o)

OBJECT_SERVER = $(SRC_SERVER:.c=.o)

FLAGS = -Wall -Wextra #-Werror

LIBFT = ./libft/libftprintf.a

all: lib client server

lib:
	make -C ./libft

client: $(OBJECT_CLIENT)
	gcc -o client $(FLAGS) $(OBJECT_CLIENT) $(LIBFT)

server: $(OBJECT_SERVER)
	gcc -o server $(FLAGS) $(OBJECT_SERVER) $(LIBFT)

%.o: %.c
	gcc -g $(FLAGS) -o $@ -c $<

clean:
	make -C ./libft clean
	/bin/rm -f $(OBJECT_CLIENT)
	/bin/rm -f $(OBJECT_SERVER)

fclean: clean
	/bin/rm -f ./libft/libftprintf.a
	/bin/rm -f client
	/bin/rm -f server

re:		fclean all

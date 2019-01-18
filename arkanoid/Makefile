#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolgin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 18:42:23 by avolgin           #+#    #+#              #
#    Updated: 2019/01/05 12:24:49 by avolgin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = arkanoid

SRC_ARK =./main.c

OBJECT_ARK = $(SRC_ARK:.c=.o)

FLAGS = -Wall -Wextra

INCLUDES_ARK = -I ./includes/

INCLUDES_LIBFT = -I ./libft/includes

INCLUDES_GLFW = -I ./glfw/include/GLFW

LIBFT = ./libft/libft.a

GLFW = ./glfw/src/libglfw3.a

FRAMEWORK_GLFW = -F ./glfw/ -framework Cocoa \
	-framework OpenGL \
	-framework CoreVideo \
	-framework IOKit

FRAMEWORK_GLF = -L ./glfw/src -lglfw3 -framework OpenGL -framework Cocoa \
				-framework CoreVideo -framework IOKit

all:	glfw_submodule $(NAME)

$(NAME) : $(OBJECT_ARK)
	cd glfw ;\
	cmake . ;\
	cd .. ;\
	make -C ./glfw/src
	make -C ./libft
	@echo "\033[0;32mArkanoid compiled\033[0;0m"
	@gcc -o $(NAME) $(FLAGS) $(LIBFT) $(GLFW) -rpath @loader_path/glfw/src \
	$(FRAMEWORK_GLFW) $(OBJECT_ARK) $(INCLUDES_GLFW)

%.o: %.c includes/*.h
	gcc -g $(FLAGS) -o $@ -c $< $(INCLUDES_ARK) $(INCLUDES_LIBFT) $(INCLUDES_GLFW)

%.o: %.c
	gcc -g 	$(FLAGS) -o $@ -c $< $(INCLUDES_ARK) $(INCLUDES_LIBFT) $(INCLUDES_GLFW)

glfw_submodule:
	git submodule init ;\
	git submodule update ;\

clean:
	make -C ./libft clean
	/bin/rm -f $(OBJECT_ARK)
	rm -f TAGS

fclean: clean
	/bin/rm -f ./libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all tags

tags:
	etags -R *.c *.h

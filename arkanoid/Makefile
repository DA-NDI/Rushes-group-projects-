#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avolgin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 18:42:23 by avolgin           #+#    #+#              #
#    Updated: 2019/01/04 18:52:41 by avolgin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = arkanoid

SRC_ARK =./main.c

OBJECT_ARK = $(SRC_ARK:.c=.o)

FLAGS = -Wall -Wextra

INCLUDES_ARK = -I ./includes/

INCLUDES_LIBFT = -I ./src/libft/includes

INCLUDES_SDL2 = -I ./src/SDL/SDL2.framework/Headers

INCLUDES_SDL2_IMAGE = -I ./src/SDL/SDL2_image.framework/Headers

INCLUDES_SDL2_MIXER = -I ./src/SDL/SDL2_mixer.framework/Headers

LIBFT = ./src/libft/libft.a

INCLUDES_SDL2_TTF = -I ./src/SDL/SDL2_ttf.framework/Headers

FRAMEWORK_SDL2 = -F ./src/SDL -framework SDL2 \
	-framework SDL2_image \
	-framework SDL2_ttf \
	-framework SDL2_mixer

FRAMEWORK_MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(OBJECT_ARK)
	make -C ./src/libft
	@echo "\033[0;32mArkanoid compiled\033[0;0m"
	@gcc -o $(NAME) $(FLAGS) $(LIBFT) -rpath @loader_path/src/sdl $(OBJECT_ARK)

%.o: %.c includes/*.h
	gcc -g $(FLAGS) -o $@ -c $< $(INCLUDES_ARK) $(INCLUDES_LIBFT)

%.o: %.c
	gcc -g 	$(FLAGS) -o $@ -c $< $(INCLUDES_ARK) $(INCLUDES_LIBFT)

clean:
	make -C ./src/libft clean
	/bin/rm -f $(OBJECT_ARK)
	rm -f TAGS

fclean: clean
	/bin/rm -f ./src/libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all tags

tags:
	etags -R *.c *.h

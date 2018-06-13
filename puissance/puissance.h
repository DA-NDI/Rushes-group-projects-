/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 10:22:04 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/06 23:33:02 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_H
# define PUISSANCE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/ft_printf.h"
# include <fcntl.h>
# include <time.h>
# include <ncurses.h>

typedef struct	s_game
{
	int			rows;
	int			columns;
	int			x;
	int			y;
	char		player;
	char		**grid;
	char		mutch;
	int			count;
	int			mch;
}				t_game;

int				valid(char **input);
int				only_digit(char *str);
int				num_mutches(t_game *game);
int				play(t_game *game);
void			ft_print_map(t_game *game);

int				play2(t_game *game);

#endif

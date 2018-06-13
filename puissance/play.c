/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:29:18 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/06 16:48:17 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#define COLS game->columns

static	void	set_item(t_game *game, int column)
{
	int i;

	i = game->rows - 1;
	while (i >= 0)
	{
		if (game->grid[i][column] == '.')
		{
			game->grid[i][column] = 'X';
			game->y = i;
			game->x = column;
			game->count++;
			game->player = 'X';
			break ;
		}
		if (i == 0)
		{
			ft_putendl("Player1, choose another column");
			play(game);
		}
		--i;
	}
}

int				play(t_game *game)
{
	char	*tmp;
	int		column;
	int		ret;

	ft_printf("Player1, enter num [0 - %d] of column to move\n", COLS - 1);
	tmp = NULL;
	while ((ret = get_next_line(0, &tmp)) > 0)
	{
		if ((!only_digit(tmp)) || *tmp == '\0' || \
			((column = ft_atoi(tmp)) >= (COLS)))
		{
			ft_putendl("Column number too big, or has wrong symbols");
			free(tmp);
		}
		else
		{
			free(tmp);
			break ;
		}
	}
	if (ret == 0)
		play(game);
	else
		set_item(game, column);
	return (0);
}

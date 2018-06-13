/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:29:18 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/06 23:44:50 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#define MAP game->grid
#define COLS game->columns
#define ROWS game->rows
#define Y game->y
#define X game->x

static int	set_item(t_game *game, int column)
{
	int i;

	i = game->rows - 1;
	while (i >= 0)
	{
		if (MAP[i][column] == '.')
		{
			MAP[i][column] = 'O';
			game->y = i;
			game->x = column;
			game->count++;
			game->player = 'O';
			ft_putendl("AI move");
			return (1);
		}
		--i;
	}
	return (0);
}

static	int	check_win_c(t_game *game, int i, int j, int mch)
{
	if (num_mutches(game) > mch)
	{
		MAP[i][j] = '.';
		return (j);
	}
	return (-1);
}

static	int	check_win(t_game *game, char pl, int mch)
{
	int i;
	int j;

	j = -1;
	while (++j < COLS)
	{
		i = game->rows - 1;
		while (i >= 0)
		{
			if (MAP[i][j] == '.')
			{
				if (MAP[i + 1][j] == '.')
					break ;
				MAP[i][j] = pl;
				game->y = i;
				game->x = j;
				game->player = pl;
				if (check_win_c(game, i, j, mch) >= 0)
					return (check_win_c(game, i, j, mch));
				MAP[i][j] = '.';
			}
			--i;
		}
	}
	return (-1);
}

static	int	check_position(t_game *game)
{
	int		column;
	int		res;
	char	temp;

	temp = game->player;
	if ((res = check_win(game, 'O', 3)) >= 0)
		column = res;
	else if ((res = check_win(game, 'X', 3)) >= 0)
		column = res;
	else if ((res = check_win(game, 'X', 2)) >= 0)
		column = res;
	else if ((res = check_win(game, 'O', 2)) >= 0)
		column = res;
	else
	{
		srand(time(NULL));
		column = rand() % COLS;
	}
	game->player = temp;
	return (column);
}

int			play2(t_game *game)
{
	int		i;
	int		j;
	int		column;

	column = check_position(game);
	i = game->rows;
	j = column;
	while (column < COLS || j >= 0)
	{
		if (!set_item(game, column < COLS ? column : j))
		{
			if (column < COLS)
				column++;
			else
				j--;
		}
		else
			break ;
	}
	return (0);
}

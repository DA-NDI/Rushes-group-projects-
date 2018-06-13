/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:09:35 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/06 16:12:34 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"
#define ROWS game->rows
#define COLS game->columns
#define Y game->y
#define X game->x
#define GRID game->grid
#define PLAYER game->player

static int	check_hor(t_game *game)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while (++i < 4)
	{
		if ((X + i >= COLS) || (GRID[Y][X + i] != PLAYER))
			break ;
		else
			res++;
	}
	i = 0;
	while (--i > -4)
	{
		if ((X + i < 0) || (GRID[Y][X + i] != PLAYER))
			break ;
		else
			res++;
	}
	return (res);
}

static int	check_ver(t_game *game)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while (++i < 4)
	{
		if ((Y + i >= ROWS) || (GRID[Y + i][X] != PLAYER))
			break ;
		else
			res++;
	}
	i = 0;
	while (--i > -4)
	{
		if ((Y + i < 0) || (GRID[Y + i][X] != PLAYER))
			break ;
		else
			res++;
	}
	return (res);
}

static int	check_diag(t_game *game)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while (++i < 4)
	{
		if ((X + i >= COLS) || (Y - i < 0) || (GRID[Y - i][X + i] != PLAYER))
			break ;
		else
			res++;
	}
	i = 0;
	while (--i > -4)
	{
		if ((X + i < 0) || (Y - i >= ROWS) || (GRID[Y - i][X + i] != PLAYER))
			break ;
		else
			res++;
	}
	return (res);
}

static int	check_mirror_diag(t_game *game)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while (++i < 4)
	{
		if ((X - i < 0) || (Y - i < 0) || (GRID[Y - i][X - i] != PLAYER))
			break ;
		else
			res++;
	}
	i = 0;
	while (--i > -4)
	{
		if ((X - i >= COLS) || (Y - i >= ROWS) ||
			(GRID[Y - i][X - i] != PLAYER))
			break ;
		else
			res++;
	}
	return (res);
}

int			num_mutches(t_game *game)
{
	int res;
	int mth;

	mth = 0;
	if ((res = check_ver(game)) > mth)
	{
		game->mutch = 'v';
		mth = res;
	}
	if ((res = check_hor(game)) > mth)
	{
		game->mutch = 'h';
		mth = res;
	}
	if ((res = check_diag(game)) > mth)
	{
		game->mutch = 'd';
		mth = res;
	}
	if ((res = check_mirror_diag(game)) > mth)
	{
		game->mutch = 'm';
		mth = res;
	}
	return (mth);
}

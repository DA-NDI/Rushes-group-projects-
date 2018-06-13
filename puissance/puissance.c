/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 10:20:48 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/16 18:12:53 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

#define HEIGHT game->rows
#define WIDTH game->columns

t_game			*ft_init(void)
{
	t_game *game;

	if (!(game = (t_game*)malloc(sizeof(t_game) * 1)))
		return (NULL);
	game->x = 0;
	game->y = 0;
	game->count = 0;
	return (game);
}

static	int		ft_put_last(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < game->rows)
	{
		while (j < game->columns)
		{
			if (game->grid[i][j] == '.')
				game->grid[i][j] = game->player;
			j++;
		}
		j = 0;
		i++;
	}
	ft_print_map(game);
	if (num_mutches(game) == 4)
		ft_printf("Player %c win\n", game->player);
	else
		ft_putendl("Draw game!");
	return (0);
}

static	char	**ft_create_grid(int width, int height)
{
	char	**grid;
	int		i;
	int		j;
	int		k;

	if (!(grid = (char**)malloc(sizeof(char*) * (height + 1))))
		return (NULL);
	i = 0;
	while (i < height)
	{
		if (!(grid[i] = (char*)malloc(sizeof(char) * (width + 1))))
			return (NULL);
		j = 0;
		while (j < width && i != (height))
			grid[i][j++] = '.';
		grid[i][j] = '\0';
		i++;
	}
	if (!(grid[i] = ft_strnew(width)))
		return (NULL);
	j = 0;
	k = 0;
	while (j < width && width < 10)
		grid[i][j++] = '0' + k++;
	return (grid);
}

int				ft_move(t_game *game)
{
	int		move;

	srand(time(NULL));
	move = rand();
	while (1)
	{
		if (move % 2)
			play(game);
		else
			play2(game);
		move++;
		if (game->count == game->columns * game->rows)
			return (ft_put_last(game));
		ft_print_map(game);
		if (num_mutches(game) > 3)
		{
			ft_printf("Player %c win\n", game->player);
			return (0);
		}
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_game	*game;
	int		i;
	int		ret;

	if (argc != 3 || !valid(argv))
	{
		ft_putendl("arg1 is height of the grid. Minimum 6.");
		ft_putendl("arg2 is  width of the grid. Minimum 7.");
		return (1);
	}
	if (!(game = ft_init()))
		return (1);
	game->columns = ft_atoi(argv[1]);
	game->rows = ft_atoi(argv[2]);
	if (!(game->grid = ft_create_grid(game->columns, game->rows)))
		return (1);
	ret = 0;
	if (!ft_move(game))
		ret = 1;
	i = 0;
	while (i <= HEIGHT)
		free(game->grid[i++]);
	free(game->grid);
	free(game);
	return (ret);
}

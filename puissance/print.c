/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 15:40:15 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/06 16:15:04 by ahonchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

#define HEIGHT game->rows
#define WIDTH game->columns
#define GREEN "\x1B[32m"
#define RED "\x1B[31m"
#define END "\x1B[0m"

void		ft_print_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i <= HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (game->grid[i][j] == 'O')
				write(1, RED, ft_strlen(RED));
			else if (game->grid[i][j] == 'X')
				write(1, GREEN, ft_strlen(GREEN));
			ft_printf("%2c", game->grid[i][j++]);
			write(1, END, ft_strlen(END));
		}
		ft_putchar('\n');
		i++;
	}
}

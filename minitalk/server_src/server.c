/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:41:02 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/20 21:41:36 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_letter	g_letter;

void	signal_handler(int sig)
{
	if (g_letter.i == 8)
	{
		g_letter.i = 0;
		g_letter.letter = 0;
	}
	if (sig == SIGUSR1)
		g_letter.letter = g_letter.letter | 1;
	else if (sig == SIGUSR2)
		;
	if (g_letter.i < 7)
		g_letter.letter = g_letter.letter << 1;
	g_letter.i++;
	if (g_letter.i == 8)
	{
		g_letter.buffer[g_letter.buffer_conter] = g_letter.letter;
		g_letter.buffer_conter++;
		if (g_letter.letter == '\0')
		{
			g_letter.buffer[g_letter.buffer_conter] = g_letter.letter;
			g_letter.buffer_conter = 0;
			ft_putendl("\033[0;32mMessage received:\033[0;0m");
			write(1, g_letter.buffer, ft_strlen(g_letter.buffer));
			write(1, "\n", 1);
		}
	}
}

int		main(void)
{
	ft_printf("server_pid == \033[0;32m%d\033[0;0m\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	g_letter.i = 0;
	g_letter.buffer_conter = 0;
	g_letter.letter = 0;
	while (1)
		pause();
	return (0);
}

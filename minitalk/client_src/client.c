/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:33:28 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/20 21:40:20 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void		print_error_and_exit(char *error)
{
	ft_putstr(error);
	exit(1);
}

static void		send_signal(int pid, char *message, int message_len)
{
	int		i;
	int		j;

	i = -1;
	while (++i < message_len)
	{
		j = 0;
		while (j < 8)
		{
			if (message[i] & (0x80 >> j))
			{
				if (kill(pid, SIGUSR1) == -1)
					print_error_and_exit("Kill error...\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					print_error_and_exit("\033[0;31mKill error...\033[0;0m\n");
			}
			usleep(100);
			j++;
		}
	}
}

int				main(int argc, char **argv)
{
	int		message_len;

	if (argc != 3)
		print_error_and_exit("Usage: client <server_pid> <message>\n");
	if ((message_len = ft_strlen(argv[2]) + 1) > MAX_MESSAGE_LEN)
		print_error_and_exit("Message is too long!\n");
	send_signal(ft_atoi(argv[1]), argv[2], message_len);
	ft_putendl("\033[0;32mMessage sent.\033[0;0m");
	return (0);
}

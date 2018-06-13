/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:37:03 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/20 19:18:53 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/ft_printf.h"
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>

# define MAX_MESSAGE_LEN 100000

typedef struct		s_letter
{
	unsigned char	letter;
	unsigned int	i;
	char			buffer[MAX_MESSAGE_LEN];
	unsigned int	buffer_conter;
}					t_letter;

#endif

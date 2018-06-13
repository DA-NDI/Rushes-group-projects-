/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:36:11 by avolgin           #+#    #+#             */
/*   Updated: 2018/03/25 21:06:18 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include "get_next_line.h"
# include <fcntl.h>
# define SIZE 40031

typedef struct		s_keys
{
	char			*value;
	char			*key;
	struct s_keys	*next;
}					t_pair;

int					hash_position(char *key);
unsigned int		hash_func_jenk(char *key, size_t len);
void				del_hash_table(t_pair *hash_table);

#endif

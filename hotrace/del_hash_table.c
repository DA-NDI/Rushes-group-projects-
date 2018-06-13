/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_hash_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avykhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:10:38 by avykhova          #+#    #+#             */
/*   Updated: 2018/03/25 19:52:56 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/hotrace.h"

void		del_node(t_pair *hash_node)
{
	if (hash_node->next)
		del_node(hash_node->next);
	if (hash_node->value)
		free(hash_node->value);
	if (hash_node->key)
		free(hash_node->key);
	if (hash_node)
		free(hash_node);
}

void		del_hash_table(t_pair *hash_table)
{
	int		i;

	i = -1;
	while (++i < SIZE)
	{
		if (hash_table[i].next != NULL)
			del_node(hash_table[i].next);
		if (hash_table[i].value)
			free(hash_table[i].value);
		if (hash_table[i].key)
			free(hash_table[i].key);
	}
	if (hash_table)
		free(hash_table);
}

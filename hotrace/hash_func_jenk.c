/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_func_jenk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 10:03:06 by avolgin           #+#    #+#             */
/*   Updated: 2018/03/25 10:03:07 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/hotrace.h"

unsigned int	hash_func_jenk(char *key, size_t len)
{
	unsigned int	hash;
	unsigned int	i;

	i = 0;
	hash = 0;
	while (i < len)
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
		i++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash);
}

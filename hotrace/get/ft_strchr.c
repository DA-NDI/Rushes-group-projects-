/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:46:02 by avolgin           #+#    #+#             */
/*   Updated: 2018/03/25 14:36:23 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*copy_s;

	copy_s = (char*)s;
	a = (char)c;
	while (*copy_s != '\0')
	{
		if (*copy_s == a)
			return (copy_s);
		copy_s++;
	}
	if (*copy_s == '\0' && a == 0)
		return (copy_s);
	return (NULL);
}

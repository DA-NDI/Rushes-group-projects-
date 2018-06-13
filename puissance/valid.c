/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahonchar <ahonchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:36:51 by ahonchar          #+#    #+#             */
/*   Updated: 2018/05/16 15:50:22 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance.h"

int			only_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int			valid(char **input)
{
	if (!only_digit(input[1]) || !only_digit(input[2]))
	{
		ft_putendl("Input must contains only digits");
		return (0);
	}
	else if ((ft_atoi(input[1]) < 6) || (ft_atoi(input[2]) < 7))
	{
		ft_putendl("Minimum size 6x7");
		return (0);
	}
	else
		return (1);
}

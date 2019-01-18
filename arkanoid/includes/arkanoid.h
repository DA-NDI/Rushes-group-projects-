/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <avolgin@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 18:44:14 by avolgin           #+#    #+#             */
/*   Updated: 2019/01/05 14:00:03 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

#include <stdio.h>
#include <glfw3.h>
#include <libft.h>

typedef struct	s_arkanoid
{
	int			keys[1024];
	int			gamestate;
	int			width;
	int			height;
}				t_arkanoid;

#endif

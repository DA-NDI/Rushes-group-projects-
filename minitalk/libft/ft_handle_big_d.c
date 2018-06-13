/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_big_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:30:44 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/20 17:56:27 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

void	ft_handle_big_d(t_field *placeholder, va_list *ap, int *len)
{
	placeholder->length = l;
	ft_print_d_i(placeholder, ap, len);
}

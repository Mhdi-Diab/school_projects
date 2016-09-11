/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 18:13:00 by atamano           #+#    #+#             */
/*   Updated: 2014/12/20 19:37:38 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"
#include "format.h"

void	conversion_handle_c(void *ff, va_list ap, int *len)
{
	char		c;
	t_format	*f;

	f = (t_format *)ff;
	if (f->modifier == L)
		return (conversion_handle_big_c(ff, ap, len));
	c = (char)va_arg(ap, int);
	ft_putchar(c);
	*len = 1;
}

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
#include "width.h"

void	exec_x(void *ff, va_list ap, int *len)
{
	t_format	*f;
	char		*str;

	f = (t_format *)ff;
	str = modifier_handle_oux(ff, ap, f->conversion->c == 'X' ?
		"0123456789ABCDEF" : "0123456789abcdef");
	str = width_handle((t_format *)ff, str);
	*len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}

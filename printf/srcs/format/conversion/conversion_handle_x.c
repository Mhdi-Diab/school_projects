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

void	conversion_handle_x(void *ff, va_list ap, int *len)
{
	t_format	*f;
	char		*str;

	f = (t_format *)ff;
	if (f->conversion->conversion == 'X')
		str = conversion_arg_oux(ff, ap, "0123456789ABCDEF");
	else
		str = conversion_arg_oux(ff, ap, "0123456789abcdef");
	*len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}

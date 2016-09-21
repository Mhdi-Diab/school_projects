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
#include "exec.h"

char	*exec_x(void *ff, va_list ap)
{
	t_format	*f;
	char		*str;

	f = (t_format *)ff;
	if (f->options[OPT_SHARP])
	{
		f->precision += 2;
		return (exec_p(ff, ap));
	}
	str = modifier_handle_oux(ff, ap, f->conversion->c == 'X' ?
		"0123456789ABCDEF" : "0123456789abcdef");
	return (str);
}

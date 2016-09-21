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

#include "format.h"
#include "option.h"
#include "precision.h"
#include "modifier.h"
#include "exec.h"
#include "utils.h"
#include "width.h"

static int		format_do_exec(t_format *f, va_list ap)
{
	t_conversion	*c;
	char			*str;
	int				len;

	len = 0;
	c = f->conversion;
	str = NULL;
	str = c->func_index != -1 ? c->func[c->func_index](f, ap) : exec_bad_char(f);
	str = format_check_zero(f, str);
	str = options_handle(f, str);
	str = precision_handle(f, str);
	str = width_handle(f, str);
	str = format_check_all(f, str);
	if (str)
	{
		len = ft_putstrlen(str);
		if (f->print_zero)
			len += ft_putcharlen(0);
		ft_strdel(&str);
	}
	return (len);
}

int				format_exec(char *str, va_list ap)
{
	t_format	*f;
	int			len;

	f = format_new();
	format_parse(f, str);
	if (DEBUG)
		format_print(f);
	len = format_do_exec(f, ap);
	format_del(&f);
	return (len);
}

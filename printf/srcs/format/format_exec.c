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

static int		format_do_exec(t_format *f, va_list ap)
{
	t_conversion	*c;

	c = f->conversion;
	if (c->func_index != -1)
	{
		c->func[c->func_index](f, ap);
	}
	return (0);
}

int				format_exec(char *str, va_list ap)
{
	t_format	*f;

	f = format_new();
	format_parse(f, str);
	if (DEBUG)
		format_print(f);
	format_do_exec(f, ap);
	format_del(&f);
	return (0);
}

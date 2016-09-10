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
	if (c->func_index != -1 && c->func_index == 0) //TODO: a changer
	{
		c->func[c->func_index](f, ap);
	}
	else
	{
		if (c->conversion == 'd')
			va_arg(ap, int);
	}
	return (0);
}

int				format_exec(char *str, va_list ap)
{
	t_format	*f;

	f = format_new();
	format_parse(f, str);
	// format_print(f);
	format_do_exec(f, ap);
	format_del(&f);
	return (0);
}

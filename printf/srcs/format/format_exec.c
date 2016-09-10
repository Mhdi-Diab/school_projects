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
	char			*ret;
	int				len;

	c = f->conversion;
	len = 0;
	if (c->func_index != -1)
	{
		ret = c->func[c->func_index](f, ap);
		ft_putstr(ret);
		len = ft_strlen(ret);
		ft_strdel(&ret);
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

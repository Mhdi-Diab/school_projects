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
	(void)f;
	(void)ap;
	return (0);
}

int				format_exec(char *str, va_list ap)
{
	t_format	*f;

	f = format_new();
	format_parse(f, str);
	format_do_exec(f, ap);
	format_del(&f);
	return (0);
}

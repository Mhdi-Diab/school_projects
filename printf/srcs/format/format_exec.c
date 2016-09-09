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

int		format_exec(char *str, va_list ap)
{
	t_format	*f;

	f = format_new();
	f->conversion = conversion_new(str);
	options_get(&f->options, str);
	f->modifier = modifier_get(str);
	f->precision = precision_get(str);

	(void)ap;
	format_del(&f);
	return (0);
}

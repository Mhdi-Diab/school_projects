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
#include "token.h"

int				format_handlers(char *str, va_list ap)
{
	t_format	*f;
	int			i;
	int			max;

	f = format_new();
	max = conversion_get_handlers(f);
	i = conversion_get_handler_index(str);
	if (i < max)
		f->conversion[i](str, ap);;
	format_del(&f);
	return (0);
}

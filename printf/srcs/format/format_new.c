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

t_format	*format_new(void)
{
	t_format		*format;
	int				i;

	i = -1;
	format = ft_memalloc(sizeof(*format));
	if (!format)
		return (NULL);
	while (++i < NB_OPTIONS)
		format->options[i] = false;
	format->modifier = NO_MODIFIER;
	format->precision = 0;
	format->width = 0;
	format->print_zero = false;
	return (format);
}

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

void		format_parse(t_format *f, char *str)
{
	f->modifier = modifier_get(str);
	f->conversion = conversion_new(str);
	f->precision = precision_get(str);
	options_get(&f->options, str);
}

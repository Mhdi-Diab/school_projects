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
#include "utils.h"

char	*exec_p(void *ff, va_list ap)
{
	char				*arg;
	// char				*hexa;
	t_format			*f;

	f = (t_format *)ff;
	arg = modifier_handle_oux(ff, ap, "0123456789abcdef");
	arg = ft_strfjoin("0x", arg);
	return (arg);
	// if (f->width >= 2 && f->options[OPT_ZERO]) //TODO: a ameliorer
	// 	f->width -= 2;
	// if (!f->options[OPT_ZERO])
	// 	arg = ft_strfjoin("0x", arg);
	// hexa = width_handle(f, arg);
	// if (f->options[OPT_ZERO])
	// 	hexa = ft_strfjoin("0x", hexa);
	// *len = ft_putstrlen(hexa);
	// // ft_strdel(&arg);
	// ft_strdel(&hexa);
}

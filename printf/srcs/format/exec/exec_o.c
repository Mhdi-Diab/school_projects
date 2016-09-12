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

char	*exec_o(void *ff, va_list ap)
{
	char	*str;
	t_format	*f;

	f = (t_format *)ff;
	str = modifier_handle_oux(ff, ap, "01234567");
	if (f->options[OPT_SHARP] && f->precision < (int)ft_strlen(str))
		f->precision = ft_strlen(str) + 1;
	return (str);
}

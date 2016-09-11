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
#include "utils.h"

void	exec_big_s(void *ff, va_list ap, int *len)
{
	wchar_t		*s;
	int			l;
	t_format	*f;

	f = (t_format *)ff;
	s = va_arg(ap, wchar_t *);
	// P("LEN: %d\n", l);
	// P("WIDTH: %d\n", f->width);
	if (s)
	{
		l = ft_count_binary_array_len(s);
		if (!f->options[OPT_MINUS] && f->width > l)
			*len += ft_print_xtimes(f->options[OPT_ZERO] ?
				'0' : ' ', f->width - l);
		*len += ft_putwstr(s);
		if (f->options[OPT_MINUS] && f->width > l)
			*len += ft_print_xtimes(f->options[OPT_ZERO] ?
				'0' : ' ', f->width - l);
	}
	else
		*len = ft_putstrlen("(null)");

}

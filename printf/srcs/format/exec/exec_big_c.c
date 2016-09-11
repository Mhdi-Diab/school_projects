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

void	exec_big_c(void *ff, va_list ap, int *len)
{
	int			l;
	wint_t		win;
	t_format	*f;

	f = (t_format *)ff;
	win = va_arg(ap, wint_t);
	l = ft_count_binary_len(win) / 7 + 1;
	if (!f->options[OPT_MINUS])
		*len += ft_print_xtimes(f->options[OPT_ZERO] ? '0' : ' ', l < f->width);
	*len = ft_putwchar(win);
	if (f->options[OPT_MINUS])
		*len += ft_print_xtimes(f->options[OPT_ZERO] ? '0' : ' ', l < f->width);
}

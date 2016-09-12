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

char	*exec_big_c(void *ff, va_list ap)
{
	wint_t		win;
	t_format	*f;
	char		*str;

	f = (t_format *)ff;
	win = va_arg(ap, wint_t);
	str = ft_getwchar(win);
	if (*str == 0)
		f->print_zero = true;
	return (str);
}

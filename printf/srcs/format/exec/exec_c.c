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

#include "exec.h"
#include "format.h"
#include "width.h"
#include "utils.h"

void	exec_c(void *ff, va_list ap, int *len)
{
	char		c;
	char		*str;
	t_format	*f;

	f = (t_format *)ff;
	if (f->modifier == L)
		return (exec_big_c(ff, ap, len));
	str = ft_memalloc(sizeof(char) * 2);
	c = (char)va_arg(ap, int);
	if (c == 0 && f->width != 0)
		f->width -= 1;
	str[0] = c;
	str = width_handle(f, str);
	*len = ft_putstrlen(str);
	*len += c == 0  ? ft_putcharlen(c) : 0;
	ft_strdel(&str);
}

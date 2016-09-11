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

void	exec_s(void *ff, va_list ap, int *len)
{
	t_format	*f;
	char		*arg;
	char		*str;

	f = (t_format *)ff;
	if (f->modifier == L)
		return (exec_big_s(ff, ap, len));
	arg = va_arg(ap, char *);
	if (arg)
	{
		str = ft_strdup(arg);
		str = width_handle((t_format *)ff, str);
	}
	else
		str = ft_strdup("(null)");
	*len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}

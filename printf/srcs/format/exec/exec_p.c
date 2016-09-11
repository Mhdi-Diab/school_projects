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

void	exec_p(void *ff, va_list ap, int *len)
{
	char				*arg;
	char				*hexa;

	arg = modifier_handle_oux(ff, ap, "0123456789abcdef");
	hexa = ft_strjoin("0x", arg);
	hexa = width_handle((t_format *)ff, hexa);
	ft_strdel(&arg);
	*len = ft_strlen(hexa);
	ft_putstr(hexa);
	ft_strdel(&hexa);
}

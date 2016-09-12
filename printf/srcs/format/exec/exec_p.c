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
	char			*arg;
	t_format		*f;

	f = (t_format *)ff;
	arg = modifier_handle_oux(ff, ap, "0123456789abcdef");
	arg = ft_strfjoin("0x", arg);
	return (arg);
}

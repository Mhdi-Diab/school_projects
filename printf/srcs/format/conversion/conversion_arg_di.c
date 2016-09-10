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

char	*conversion_arg_di(void *ff, va_list ap)
{
	t_format			*f;
	char				*arg;

	f = (t_format *)ff;
	if (ft_isupper(f->conversion->conversion)|| f->modifier == L)
		arg = ft_lltoa(va_arg(ap, long));
	else if (f->modifier == LL)
		arg = ft_lltoa(va_arg(ap, long long));
	else if (f->modifier == HH)
		arg = ft_lltoa((signed char)va_arg(ap, int));
	else if (f->modifier == H)
		arg = ft_lltoa((short)va_arg(ap, int));
	else if (f->modifier == J)
		arg = ft_lltoa(va_arg(ap, intmax_t));
	else if (f->modifier == Z)
		arg = ft_lltoa(va_arg(ap, size_t));
	else
		arg = ft_lltoa(va_arg(ap, int));
	if (!arg)
		return (ft_strdup("(null)"));
	return (arg);
}

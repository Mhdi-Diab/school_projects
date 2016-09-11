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

char	*modifier_handle_oux(void *ff, va_list ap, char *base)
{
	t_format			*f;
	char				*arg;

	f = (t_format *)ff;
	if ((ft_isupper(f->conversion->c) || f->modifier == L) &&
		f->conversion->c != 'X')
		arg = ft_llbtoa(va_arg(ap, unsigned long), base);
	else if (f->modifier == LL)
		arg = ft_llbtoa(va_arg(ap, unsigned long long), base);
	else if (f->modifier == HH)
		arg = ft_llbtoa((unsigned char)va_arg(ap, int), base);
	else if (f->modifier == H)
		arg = ft_llbtoa((unsigned short)va_arg(ap, int), base);
	else if (f->modifier == J)
		arg = ft_llbtoa(va_arg(ap, uintmax_t), base);
	else if (f->modifier == Z)
		arg = ft_llbtoa(va_arg(ap, size_t), base);
	else if (f->conversion->c == 'p' || f->conversion->c == 'X')
		arg = ft_llbtoa(va_arg(ap, unsigned long), base);
	else
		arg = ft_llbtoa(va_arg(ap, unsigned int), base);
	return (arg ? arg : ft_strdup("(null)"));
}

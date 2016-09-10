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

void	conversion_handle_s(void *ff, va_list ap)
{
	t_format	*f;
	char		*arg;

	f = (t_format *)ff;
	if (f->modifier == L)
		return (conversion_handle_big_s(ff, ap));
	arg = ft_strdup(va_arg(ap, char *));
	ft_putstr(arg);
	free(arg);
}

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

char	*conversion_handle_x(void *ff, va_list ap)
{
	t_format			*f;
	char				*arg;

	f = (t_format *)ff;
	(void)f;
	arg = ft_llbtoa(va_arg(ap, unsigned long int), "0123456789ABCDEF");
	return (arg);
}

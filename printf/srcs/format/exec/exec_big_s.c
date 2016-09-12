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

char	*exec_big_s(void *ff, va_list ap)
{
	wchar_t		*s;
	t_format	*f;

	f = (t_format *)ff;
	s = va_arg(ap, wchar_t *);
	return(s ? conversion_getwstr(f->conversion, s) : ft_strdup("(null)"));

}

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

#include "width.h"
#include "option.h"

char			*precision_handle_sS(t_format *f, char *str)
{
	int		len;
	char	*new_str;

	len = ft_strlen(str);
	if (f->precision < len && f->precision > 0)
	{
		new_str = ft_strsub(str, 0, f->precision);
		ft_strdel(&str);
		return (new_str);
	}
	return (str);
}

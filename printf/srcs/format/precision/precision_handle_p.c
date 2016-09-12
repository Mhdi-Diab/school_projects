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

char			*precision_handle_p(t_format *f, char *str)
{
	int		len;
	char	*new_str;
	char	*tmp;

	len = ft_strlen(str) - 2;
	if (f->precision > len)
	{
		new_str = ft_strnew(f->precision - len + 1);
		ft_memset(new_str, '0', f->precision - len);
		tmp = &str[2];
		str = ft_strjoin(new_str, tmp);
		str = ft_strfjoin("0x", str);
		ft_strdel(&new_str);
	}
	return (str);
}

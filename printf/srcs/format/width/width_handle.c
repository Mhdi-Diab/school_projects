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

char	*width_handle(t_format *f, char *str)
{
	char	c;
	int		len;
	char	*new_str;

	len = ft_strlen(str);
	if (f->width != 0 && f->width > len)
	{
		c = f->options[OPT_ZERO] ? '0' : ' ';
		new_str = ft_memalloc(sizeof(char) * (f->width - len + 1));
		ft_memset(new_str, c, f->width - len);
		new_str = f->options[OPT_MINUS] ?
			ft_strfjoin(str, new_str) : ft_strjoin(new_str, str);
		return (new_str);
	}
	return (str);
}

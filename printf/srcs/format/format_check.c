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

#include "format.h"
#include "option.h"
#include "precision.h"
#include "modifier.h"
#include "exec.h"
#include "utils.h"
#include "width.h"

char		*format_check_zero(t_format *f, char *str)
{
	if (str && f->precision == -1)
	{
		if ((ft_strchr("diouxpOUX", f->conversion->c) && ft_atoi(str) == 0) ||
			ft_strchr("sS", f->conversion->c))
		{
			ft_strdel(&str);
			return (f->conversion->c != 'p' ? ft_strdup("") : ft_strdup("0x"));
		}
	}
	return (str);
}

char		*format_check_d(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (str[i] && str[i] == ' ')
		i++;
	c = str[i];
	while (str[i])
	{
		if (str[i] == '-' && c == '0')
		{
			str[i] = c;
			str[0] = '-';
		}
		i++;
	}
	return (str);
}

char		*format_check_p(char *str)
{
	int i;
	int d;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	d = i;
	str[i] = '0';
	while (str[d])
	{
		if (d == i + 1)
			str[d] = 'x';
		else if (str[d] == 'x')
			str[d] = '0';
		d++;
	}
	return (str);
}

char		*format_check_all(t_format *f, char *str)
{
	if (f->conversion->c == 'p' || (f->conversion->c == 'x' &&
		f->options[OPT_SHARP] && !f->print_zero))
	{
		return (format_check_p(str));
	}
	else if (f->conversion->c == 'd')
		return (format_check_d(str));
	return (str);
}

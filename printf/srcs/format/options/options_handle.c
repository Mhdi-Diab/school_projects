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

static char		*options_handle_p(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 1)
			str[i] = 'x';
		else if (str[i] == 'x')
			str[i] = '0';
		i++;
	}
	return (str);
}

static char		*options_handle_d(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = str[0];
	while (str[i])
	{
		if (str[i] == '-')
		{
			str[i] = c;
			str[0] = '-';
		}
		i++;
	}
	return (str);
}

char			*options_handle(void *ff, char *str)
{
	t_format	*f;

	f = (t_format *)ff;
	if (f->options[OPT_ZERO])
	{
		if (f->conversion->c == 'p' && f->width > 2)
			return (options_handle_p(str));
		if (f->conversion->c == 'd')
			return (options_handle_d(str));
	}
	return (str);
}

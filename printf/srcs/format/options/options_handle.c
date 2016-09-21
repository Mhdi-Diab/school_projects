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

char			*options_handle(void *ff, char *str)
{
	t_format	*f;
	char		conversion;

	f = (t_format *)ff;
	conversion = f->conversion->c;
	if (f->options[OPT_SHARP])
	{
		if (conversion == 'o' && f->precision < (int)ft_strlen(str) &&
		ft_atoi(str) != 0) //TODO: a ameliorer
			f->precision = ft_strlen(str) + 1;
	}
	return (str);
}

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
#include "width.h"

void	conversion_handle_bad_char(void *ff, int *len)
{
	char	*str;
	t_format	*f;

	f = (t_format *)ff;
	str = ft_memalloc(sizeof(char) * 2);
	str[0] = f->conversion->c;
	str = width_handle(f, str);
	*len = ft_putstrlen(str);
	ft_strdel(&str);
}

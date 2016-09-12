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
#include "precision.h"
#include "option.h"

char			*precision_handle(t_format *f, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (ft_strchr("diouxOUX", f->conversion->c))
		str = precision_handle_diouxX(f, str);
	else if (ft_strchr("sS", f->conversion->c))
		str = precision_handle_sS(f, str);
	else if (f->conversion->c == 'p')
		str = precision_handle_p(f, str);
	return (str);
}

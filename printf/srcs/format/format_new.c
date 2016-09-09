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

t_format	*format_new(void)
{
	t_format		*format;

	P("**** %s\n", "init format");
	format = ft_memalloc(sizeof(t_format *));
	if (!format)
		return (NULL);
	format->token = NULL;
	format->arg = NULL;
	return (format);
}

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

#include "token.h"

void		token_parse(t_ast *ast, char *format)
{
	while (*format)
	{
		if (*format == FORMAT_CHAR)
		{
			format++;
			if (*format)
				format = token_get_format(ast, format);
		}
		else
			format = token_get_simple(ast, format);
	}
}

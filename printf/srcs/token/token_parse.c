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

static char	*check_format(t_ast *ast, char *str)
{
	while (*str)
	{
		if (ft_strchr(CONVERSION_FORMAT, *str))
			return (NULL);
		else if (START_FORMAT == *str)
			return (token_get_simple(ast, str));
		else if (!ft_strchr(FORMAT_ACCEPTED, *str))
			return (str);
		str++;
	}
	return (NULL);
}

void		token_parse(t_ast *ast, char *format)
{
	char	*str;

	while (*format)
	{
		if (*format == START_FORMAT)
		{
			format++;
			if (*format)
			{
				str = check_format(ast, format);
				format = str ? str : token_get_format(ast, format);
			}
		}
		else
			format = token_get_simple(ast, format);
	}
}

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

#include "printf.h"
#include "ast.h"
#include "format.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_ast		*ast;
	int			ret;

	if (!format)
		return (0);
	va_start(ap, format);
	// P("Format:\n%s\n---------\n", format);
	ast = ast_new();
	ast_get_tokens(ast, (char *)format);
	ft_exec(ast, ap);
	va_end(ap);
	ret = ast->total;
	ast_del(&ast);
	return (ret);
}

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

#include "ast.h"
#include "printf.h"

t_ast		*ast_new(void)
{
	t_ast		*ast;

	if (DEBUG)
		P("**** %s\n", "init ast");
	ast = ft_memalloc(sizeof(*ast));
	if (!ast)
		return (NULL);
	ast->token = NULL;
	ast->total = 0;
	return (ast);
}

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
#include "token.h"
#include "utils.h"

static int	simple_exec(char *str)
{
	return (ft_putstrlen(str));
}

void		ft_exec(t_ast *ast, va_list ap)
{
	t_list	*list;
	t_token	*token;

	list = ast->token;
	while (list)
	{
		token = (t_token *)list->content;
		if (token->type == SIMPLE_STRING)
			ast->total += simple_exec(token->content);
		else if (token->type == FORMAT_STRING)
			ast->total += format_exec(token->content, ap);
		list = list->next;
	}
}

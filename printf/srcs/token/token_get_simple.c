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

static int	count_to_end(char *format)
{
	int count;

	count = 0;
	if (format[count] == START_FORMAT)
		count++;
	while (format[count] && format[count] != START_FORMAT)
		count++;
	return (count);
}


char		*token_get_simple(t_ast *ast, char *format)
{
	t_token		*token;
	int			count;

	count = 0;
	token = token_new(SIMPLE_STRING);
	count = count_to_end(format);
	token->content = ft_strsub(format, 0, count);
	P("Simple token content:|%s|\n", token->content);
	ft_lstadd_back(&ast->token, ft_lstnew(token, sizeof(t_token *)));
	return (format + count);
}

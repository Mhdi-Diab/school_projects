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
	while (format[count] && ft_strchr(FORMAT_STR, format[count]) &&
		!ft_strchr(CONVERSION_FORMAT, format[count])) //TODO: a ameliorer
	{
		if (format[count] == FORMAT_CHAR)
			return (count + 1);
		count++;
	}
	return (count + 1);
}

char		*token_get_format(t_ast *ast, char *format)
{
	int			count;
	t_token		*token;

	count = 0;
	token = token_new(FORMAT_STRING);
	count = count_to_end(format);
	token->content = ft_strsub(format, 0, count);
	ft_lstadd_back(&ast->token, ft_lstnew(token, sizeof(t_token)));
	return (format + count);
}

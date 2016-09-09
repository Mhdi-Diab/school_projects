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
	int		i;
	bool	in_format;

	i = 0;
	in_format = false;
	while (format[i])
	{
		if (format[i])
		{
			P("%c", format[i]);
		}
		i++;
	}
	PN("\n");
	(void)ast;
	(void)format;
}

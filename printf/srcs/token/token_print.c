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

void		token_print(t_ast *ast)
{
	t_list	*list;
	t_token	*token;

	list = ast->token;
	while (list)
	{
		token = (t_token *)list->content;
		if (token->type == FORMAT_STRING)
			ft_putstr("Token: FORMAT STRING |");
		else
			ft_putstr("Token: SIMPLE_STRING |");
		ft_putstr(token->content);
		ft_putstr("|\n");
		list = list->next;
	}
}

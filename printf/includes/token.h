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

#ifndef TOKEN_H
# define TOKEN_H

# include "ast.h"
# include "printf.h"
# include "format.h"

typedef enum		s_type
{
	SIMPLE_STRING,
	FORMAT_STRING
}					t_type;

typedef struct		s_token
{
	char			*content;
	t_type			type;
}					t_token;

void				token_parse(t_ast *ast, char *format);
char				*token_get_simple(t_ast *ast, char *format);
char				*token_get_format(t_ast *ast, char *format);
t_token				*token_new(t_type type);
void				token_print(t_ast *ast);

#endif

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

#ifndef AST_H
# define AST_H

# include "libft.h"
# include "printf.h"
# include <stdarg.h>

typedef struct	s_ast
{
	t_list		*token;
}				t_ast;

t_ast			*ast_new(void);
void			ast_get_tokens(t_ast *ast, char *format);
void			ast_get_args(t_ast *ast, va_list ap);
void			ast_print(t_ast *ast);
void			ast_del(t_ast **ast);

#endif

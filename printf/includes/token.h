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
# include <stdarg.h>

# define END_FORMAT "sSpdDioOuUxXcC%"
# define START_FORMAT "%"

typedef enum		s_type
{
	SIMPLE_STRING,
	FORMAT_STRING
}					t_type;

typedef struct		s_token
{
	void			*content;
	t_type			type;
}					t_token;

void				token_parse(t_ast *ast, char *format);

#endif

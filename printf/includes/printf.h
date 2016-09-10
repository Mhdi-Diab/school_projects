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

#ifndef PRINTF_H
# define PRINTF_H

# define P(f_, ...) printf((f_), __VA_ARGS__)
# define PN(f_) printf((f_))
# define DEBUG 0

# include "strings.h"
# include "maths.h"
# include "print.h"
# include "linked_list.h"
# include "ast.h"

typedef enum	e_bool
{
	false,
	true
}				bool;

int		ft_printf(const char *format, ...);
void	ft_exec(t_ast *ast, va_list ap);

#endif

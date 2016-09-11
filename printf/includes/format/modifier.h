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

#ifndef MODIFIER_H
# define MODIFIER_H

# include "printf.h"

# define MODIFIER_STR "hljz"

typedef enum	e_modifier
{
	HH = 0,
	H,
	LL,
	L,
	J,
	Z,
	NO_MODIFIER
}				t_enum_modifier;

t_enum_modifier		modifier_get(char *str);
char				*modifier_handle_oux(void *ff, va_list ap, char *base);
char				*modifier_handle_di(void *ff, va_list ap);

#endif

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

#ifndef FORMAT_H
# define FORMAT_H

# include "printf.h"
# include "modifier.h"
# include "conversion.h"
# include "option.h"

# define START_FORMAT '%'

typedef struct	s_format
{
	t_conversion	*conversion;
	bool			options[NB_OPTIONS];
	t_enum_modifier	modifier;
}				t_format;

t_format		*format_new(void);
void			format_del(t_format **format);
int				format_exec(char *str, va_list ap);
int				format_handlers(char *str, va_list ap);
int				conversion_get_handlers(t_format *f);
char			*conversion_handle_s(char *str, va_list ap);
int				conversion_get_handler_index(char *str);


#endif

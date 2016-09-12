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

#ifndef CONVERSION_H
# define CONVERSION_H

# include "printf.h"

# define CONVERSION_FORMAT "sSpdDioOuUxXcC"
# define NB_CONVERSIONS 14

typedef struct	s_convertion
{
	char		c;
	int			func_index;
	char		*(*func[NB_CONVERSIONS]) (void *f, va_list ap);
	void		*input_length;
}				t_conversion;

t_conversion	*conversion_new(char *str);
void			conversion_del(t_conversion **conversion);
char			conversion_parse(char *str);
int				conversion_parse_func_index(char c);
char			*conversion_getwstr(t_conversion *c, wchar_t *str);
char			*conversion_getwchar(wint_t wchar);

#endif

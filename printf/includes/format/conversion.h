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
	void		(*func[NB_CONVERSIONS]) (void *f, va_list ap, int *len);
}				t_conversion;

t_conversion	*conversion_new(char *str);
void			conversion_del(t_conversion **conversion);
char			conversion_get(char *str);
int				conversion_get_func_index(char c);

char			*modifier_handle_oux(void *ff, va_list ap, char *base);
char			*modifier_handle_di(void *ff, va_list ap);

void			conversion_handle_s(void *f, va_list ap, int *len);
void			conversion_handle_big_s(void *f, va_list ap, int *len);
void			conversion_handle_big_c(void *f, va_list ap, int *len);
void			conversion_handle_p(void *f, va_list ap, int *len);
void			conversion_handle_d(void *f, va_list ap, int *len);
void			conversion_handle_x(void *f, va_list ap, int *len);
void			conversion_handle_o(void *ff, va_list ap, int *len);
void			conversion_handle_u(void *ff, va_list ap, int *len);
void			conversion_handle_c(void *ff, va_list ap, int *len);

#endif

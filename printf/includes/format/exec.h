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

#ifndef EXEC_H
# define EXEC_H

# include "printf.h"

void			exec_s(void *f, va_list ap, int *len);
void			exec_big_s(void *f, va_list ap, int *len);
void			exec_big_c(void *f, va_list ap, int *len);
void			exec_p(void *f, va_list ap, int *len);
void			exec_d(void *f, va_list ap, int *len);
void			exec_x(void *f, va_list ap, int *len);
void			exec_o(void *ff, va_list ap, int *len);
void			exec_u(void *ff, va_list ap, int *len);
void			exec_c(void *ff, va_list ap, int *len);
void			exec_bad_char(void *ff, int *len);

#endif

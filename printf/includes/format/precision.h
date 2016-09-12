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

#ifndef PRECISION_H
# define PRECISION_H

# include "printf.h"
# include "format.h"

# define PRECISION_STR "."

int				precision_parse(char *str);
char			*precision_handle(t_format *ff, char *str);
char			*precision_handle_diouxX(t_format *f, char *str);
char			*precision_handle_sS(t_format *f, char *str);
char			*precision_handle_p(t_format *f, char *str);

#endif

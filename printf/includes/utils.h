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

#ifndef UTILS_H
# define UTILS_H

# include "printf.h"

int			ft_putstrlen(char *str);
int			ft_putcharlen(char c);
int			ft_binary_string_to_decimal(char *grid);
int			ft_count_binary_len(unsigned int i);
int			ft_putwchar(wint_t wchar);
int			ft_putwstr(wchar_t *str);
char		*ft_get_binary_string(unsigned int decimal);
int			ft_print_xtimes(char c, int len);
int			ft_count_binary_array_len(wchar_t *str);

#endif

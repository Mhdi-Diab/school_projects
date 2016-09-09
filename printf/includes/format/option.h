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

#ifndef OPTION_H
# define OPTION_H

# include "printf.h"

# define NB_OPTIONS 5

typedef enum	e_option
{
	SHARP = 0,
	ZERO,
	MINUS,
	PLUS,
	SPACE
}				t_enum_option;

void	options_get(bool (*options)[NB_OPTIONS], char *str);

#endif

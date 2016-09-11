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
# define OPTION_STR "#0-+ "

typedef enum	e_option
{
	OPT_SHARP = 0,
	OPT_ZERO,
	OPT_MINUS,
	OPT_PLUS,
	OPT_SPACE,
	NO_OPTION
}				t_enum_option;

void	options_parse(bool (*options)[NB_OPTIONS], char *str);

#endif

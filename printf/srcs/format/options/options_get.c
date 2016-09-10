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

#include "option.h"
#include "token.h"

void	options_get(bool (*options)[NB_OPTIONS], char *str)
{
	const char			opt[] = {'#', '0', '-', '+', ' '};
	t_enum_option		enum_opt;

	enum_opt = SHARP;
	while (enum_opt < NO_OPTION)
	{
		if (ft_strchr(str, opt[enum_opt]))
			(*options)[enum_opt] = true;
		enum_opt++;
	}
}

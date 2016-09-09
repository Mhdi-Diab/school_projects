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

#include "modifier.h"
#include "token.h"

t_enum_modifier			modifier_get(char *str)
{
	static const char	*modifiers[] = {"hh", "h", "ll", "l", "j", "z"};
	t_enum_modifier		enum_modif;

	enum_modif = HH;
	while (enum_modif < NO_MODIFIER)
	{
		if (ft_strstr(str, modifiers[enum_modif]))
			return (enum_modif);
		enum_modif++;
	}
	return (NO_MODIFIER);
}

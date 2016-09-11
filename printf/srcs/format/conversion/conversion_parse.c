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

#include "conversion.h"
#include "token.h"

char	conversion_parse(char *str)
{
	while (str && *str)
	{
		if (ft_strchr(CONVERSION_FORMAT, *str) || !ft_strchr(FORMAT_STR, *str)
			|| *str == START_FORMAT)
			return (*str);
		str++;
	}
	return ('\0');
}

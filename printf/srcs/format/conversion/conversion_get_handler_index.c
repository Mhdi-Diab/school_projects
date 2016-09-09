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

#include "format.h"
#include "token.h"

int		conversion_get_handler_index(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (str && *str)
	{
		if (ft_strchr(CONVERSION_FORMAT, *str))
		{
			while (tmp && *tmp && CONVERSION_FORMAT[i] != *str) //TODO: to improve
				i++;
			return (i);
		}
		str++;
	}
	return (i);
}

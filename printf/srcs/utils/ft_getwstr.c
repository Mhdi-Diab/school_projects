/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 13:54:56 by atamano           #+#    #+#             */
/*   Updated: 2014/12/20 13:55:19 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*ft_getwstr(wchar_t *str)
{
	int		total;
	char	*new_str;

	total = 0;
	new_str = ft_strnew(1);
	while (*str)
	{
		new_str = ft_strfjoin(new_str, ft_getwchar(*str));
		str++;
	}
	return (new_str);
}

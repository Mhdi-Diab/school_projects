/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:02:21 by atamano           #+#    #+#             */
/*   Updated: 2015/03/24 16:10:16 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

unsigned long dict_hash(const char *s)
{
	unsigned const char	*us;
	unsigned long		h;

	h = 0;
	us = (unsigned const char *)s;
	while (*us) {
		h = h * MULTIPLIER + *us;
		us++;
	}
	return (h);
}

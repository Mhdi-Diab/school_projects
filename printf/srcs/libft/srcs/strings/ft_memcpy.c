/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:55:44 by atamano           #+#    #+#             */
/*   Updated: 2014/11/03 17:06:01 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ds;
	const char	*sr;
	size_t		i;

	ds = (char *)dst;
	sr = (const char *)src;
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dst);
}

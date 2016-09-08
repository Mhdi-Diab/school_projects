/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 08:34:08 by atamano           #+#    #+#             */
/*   Updated: 2014/11/06 10:22:01 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	n;
	size_t	i;
	size_t	initial;

	length = ft_strlen(dst);
	initial = length;
	if (length >= size)
		return (size + ft_strlen(src));
	n = size - length;
	i = 0;
	while (src[i])
	{
		if (n > i + 1)
			dst[length++] = src[i];
		i++;
	}
	dst[length] = '\0';
	return (initial + i);
}

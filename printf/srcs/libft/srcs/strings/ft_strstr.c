/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:38:03 by atamano           #+#    #+#             */
/*   Updated: 2015/02/05 18:38:04 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strstr(const char *strstack, const char *srcdle)
{
	int		i;
	char	*str;
	char	*src;

	if (!strstack || !srcdle)
		return (NULL);
	str = (char *)strstack;
	src = (char *)srcdle;
	i = ft_strlen(src);
	if (*src == 0)
		return (str);
	while (*str != 0)
	{
		if (!ft_strncmp(str, src, i))
			return (str);
		str++;
	}
	return (NULL);
}

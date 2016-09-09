/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:36:44 by atamano           #+#    #+#             */
/*   Updated: 2015/02/05 18:36:47 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (i < n && s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			temp = i;
			while (i < n && s2[j] == s1[i])
			{
				if (s2[j + 1] == '\0')
					return ((char *)&s1[temp]);
				j++;
				i++;
			}
			i = temp;
		}
		i++;
	}
	return (NULL);
}

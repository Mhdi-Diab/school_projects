/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:22:32 by atamano           #+#    #+#             */
/*   Updated: 2014/12/29 12:28:47 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

char	*ft_strfjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	tab = (char *)malloc(sizeof(char) * length);
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j])
		tab[i++] = s2[j++];
	tab[i] = '\0';
	if (*s2)
		ft_strdel((char **)&s2);
	return (tab);
}

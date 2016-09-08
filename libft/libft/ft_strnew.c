/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:03:46 by atamano           #+#    #+#             */
/*   Updated: 2014/11/04 19:08:09 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = (char *)malloc(sizeof(char) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}

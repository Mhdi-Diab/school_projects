/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:28:18 by atamano           #+#    #+#             */
/*   Updated: 2014/11/05 16:54:20 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*tab;
	char	*temp;
	size_t	count;

	count = 0;
	tab = malloc(size);
	if (!tab)
		return (NULL);
	temp = (char *)tab;
	while (count < size)
	{
		temp[count] = '\0';
		count++;
	}
	return (tab);
}

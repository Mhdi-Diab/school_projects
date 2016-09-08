/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:07:12 by atamano           #+#    #+#             */
/*   Updated: 2014/11/25 13:21:00 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char			*ft_itoa2(int n, unsigned int i, int count, int j)
{
	char			*tab;
	unsigned int	k;

	k = i;
	while ((i = i / 10) != 0)
		count++;
	if (!(tab = ft_strnew(count + 1)))
		return (NULL);
	if (n < 0)
	{
		tab[0] = '-';
		j++;
	}
	while (--count >= 0)
	{
		tab[j] = '0' + k / ft_power(10, count);
		k = k % ft_power(10, count);
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

char				*ft_itoa(int n)
{
	unsigned int i;

	if (n >= 0)
	{
		i = n;
		return (ft_itoa2(n, i, 1, 0));
	}
	else
	{
		i = -n;
		return (ft_itoa2(n, i, 1, 0));
	}
}

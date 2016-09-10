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

size_t	ft_nblen(long long n)
{
	size_t	nb_char;

	nb_char = 0;
	if (n < 0)
		nb_char++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		nb_char++;
		n /= 10;
	}
	return (nb_char);
}

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
#include "maths.h"

char	*ft_lltoa(intmax_t n)
{
	char	*str;
	size_t	len;
	int		sign;

	sign = 1;
	len = ft_nblen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (n != 0)
	{
		str[len--] = n % 10 * sign + '0';
		n /= 10;
	}
	return (str);
}

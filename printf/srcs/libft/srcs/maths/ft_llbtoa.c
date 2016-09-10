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

#include "libft.h"
#include "maths.h"

static size_t	ft_nbblen(uintmax_t n, size_t base)
{
	size_t	nb_char;

	nb_char = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		nb_char++;
		n /= base;
	}
	return (nb_char);
}

char			*ft_llbtoa(uintmax_t n, char *base)
{
	char	*str;
	size_t	len;
	size_t	len_base;

	len_base = ft_strlen(base);
	len = ft_nbblen(n, len_base);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (n != 0)
	{
		str[len--] = base[n % len_base];
		n /= len_base;
	}
	return (str);
}

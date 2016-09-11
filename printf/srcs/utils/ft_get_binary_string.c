/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 13:54:56 by atamano           #+#    #+#             */
/*   Updated: 2014/12/20 13:55:19 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_get_binary_string(unsigned int decimal)
{
	char	*bin;
	int		bin_len;

	bin_len = ft_count_binary_len(decimal);
	bin = ft_memalloc(sizeof(char) * bin_len + 1);
	if (bin)
	{
		while (--bin_len >= 0)
		{
			bin[bin_len] = '0' + decimal % 2;
			decimal /= 2;
		}
	}
	return (bin);
}

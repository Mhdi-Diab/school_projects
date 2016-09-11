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

int		ft_binary_string_to_decimal(char *grid)
{
	int i;
	int j;
	int count;
	int total;

	i = 0;
	count = 7;
	total = 0;
	while (grid[i])
	{
		j = ft_power(2, count);
		total = total + j * (grid[i] - '0');
		count--;
		i++;
	}
	return (total);
}

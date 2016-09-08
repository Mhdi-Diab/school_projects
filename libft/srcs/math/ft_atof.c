/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 10:14:25 by atamano           #+#    #+#             */
/*   Updated: 2015/03/19 10:14:27 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_split_atof(char *str, t_atof *a)
{
	while (*str != 0)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (a->in_fraction)
			{
				a->fraction = a->fraction * 10 + (*str - '0');
				a->divisor *= 10;
			}
			else
				a->integer = a->integer * 10 + (*str - '0');
		}
		else if (*str == '.')
		{
			if (a->in_fraction)
				return (a->sign * (a->integer + a->fraction / a->divisor));
			else
				a->in_fraction = 1;
		}
		else
			return ((float)a->sign * (a->integer + a->fraction / a->divisor));
		str++;
	}
	return (a->sign * (a->integer + a->fraction / a->divisor));
}

double	ft_atof(char *str)
{
	t_atof a;

	if (!str || !*str)
		return (0);
	a.integer = 0;
	a.fraction = 0;
	a.divisor = 1;
	a.sign = 1;
	a.in_fraction = 0;
	if (*str == '-')
	{
		str++;
		a.sign = -1;
	}
	if (*str == '+')
		str++;
	return (ft_split_atof(str, &a));
}

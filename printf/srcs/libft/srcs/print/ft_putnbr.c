/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:40:00 by atamano           #+#    #+#             */
/*   Updated: 2014/11/10 08:45:46 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_putnbr(int n)
{
	unsigned int	i;

	if (n < 0)
	{
		ft_putchar('-');
		i = -n;
	}
	else
		i = n;
	if (i < 10)
		ft_putchar('0' + i);
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:38:27 by atamano           #+#    #+#             */
/*   Updated: 2014/11/06 14:39:52 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void		ft_print_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

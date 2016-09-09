/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_circ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 10:30:20 by atamano           #+#    #+#             */
/*   Updated: 2015/01/27 13:01:42 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_circadd(t_circ **begin, t_circ *new)
{
	t_circ	*tmp;
	t_circ	*prev;

	tmp = *begin;
	if (tmp)
	{
		prev = tmp->prev;
		tmp = new;
		tmp->next = *begin;
		tmp->prev = prev;
		if (prev)
			prev->next = tmp;
		(*begin)->prev = tmp;
		*begin = tmp;
	}
	else
		*begin = new;
}

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

void	ft_circadd_back(t_circ **begin, t_circ *new)
{
	t_circ	*tmp;

	tmp = *begin;
	if (tmp)
	{
		tmp = (*begin)->prev;
		new->prev = tmp;
		tmp->next = new;
		new->next = *begin;
		(*begin)->prev = new;
	}
	else
	{
		*begin = new;
		(*begin)->prev = NULL;
		(*begin)->next = NULL;
	}
}

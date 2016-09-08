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

void	ft_circular_push_back(t_circ **begin, void *data)
{
	t_circ	*tmp;
	t_circ	*new;

	tmp = *begin;
	if (tmp)
	{
		tmp = (*begin)->prev;
		new = ft_circ_new(data);
		new->prev = tmp;
		tmp->next = new;
		new->next = *begin;
		(*begin)->prev = new;
	}
	else
	{
		*begin = ft_circ_new(data);
		(*begin)->prev = NULL;
		(*begin)->next = NULL;
	}
}

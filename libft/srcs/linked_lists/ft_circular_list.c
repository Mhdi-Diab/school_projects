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

t_circ	*circ_create(char *data)
{
	t_circ	*new;

	new = (t_circ *)malloc(sizeof(t_circ));
	if (!new)
		return (NULL);
	new->data = ft_strdup(data);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	circ_push_back(t_circ **begin, char *data)
{
	t_circ	*tmp;
	t_circ	*new;

	tmp = *begin;
	if (tmp)
	{
		tmp = (*begin)->prev;
		new = circ_create(data);
		new->prev = tmp;
		tmp->next = new;
		new->next = *begin;
		(*begin)->prev = new;
	}
	else
	{
		*begin = circ_create(data);
		(*begin)->prev = NULL;
		(*begin)->next = NULL;
	}
}

void	circ_push_front(t_circ **begin, char *data)
{
	t_circ	*tmp;
	t_circ	*prev;

	tmp = *begin;
	if (tmp)
	{
		prev = tmp->prev;
		tmp = circ_create(data);
		tmp->next = *begin;
		tmp->prev = prev;
		if (prev)
			prev->next = tmp;
		(*begin)->prev = tmp;
		*begin = tmp;
	}
	else
		*begin = circ_create(data);
}

t_circ	*circ_get_arg(char **arg)
{
	int		i;
	t_circ	*circ;

	circ = NULL;
	i = 0;
	while (arg[i])
	{
		circ_push_back(&circ, arg[i]);
		i++;
	}
	return (circ);
}

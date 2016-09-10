/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:40:36 by atamano           #+#    #+#             */
/*   Updated: 2015/02/05 18:40:45 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new != NULL)
	{
		if (*alst != NULL)
			new->next = *alst;
		*alst = new;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:11:37 by atamano           #+#    #+#             */
/*   Updated: 2015/03/20 17:34:02 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	*graph_search(t_btree *r, void *k, int (*cmp)(void *, void *))
{
	if (r)
	{
		if ((*cmp)(r->item, k) == 0)
			return(r->item);
		graph_search(r->left, k, cmp);
		graph_search(r->right, k, cmp);
	}
	return (NULL);
}

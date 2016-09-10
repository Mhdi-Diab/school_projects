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

void	graph_del(t_btree *r, void (*del)(void **))
{
	if (r)
	{
		graph_del(r->left, del);
		graph_del(r->right, del);
		(*del)(&r->item);
		free(r);
	}
}

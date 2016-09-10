/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:09:28 by atamano           #+#    #+#             */
/*   Updated: 2015/02/03 16:09:30 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_btree	*graph_create_node(void *item, size_t n)
{
   t_btree *new;

   new = (t_btree *)malloc(sizeof(t_btree));
   if (new)
   {
	   new->item = ft_memalloc(n);
	   if (new->item)
		   new->item = ft_memcpy(new->item, item, n);
	   new->color = RB_RED;
	   new->parent = NULL;
	   new->left = NULL;
	   new->right = NULL;
   }
   return (new);
}

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

static void		tree_insert(t_btree **r, t_btree *x, int (*cmp)(void *, void *))
{
	if (!*r)
		*r = x;
	else if ((*cmp)((*r)->item, x->item) > 0)
	{
		if (!(*r)->left)
		{
			(*r)->left = x;
			(*r)->left->parent = *r;
		}
		else
			tree_insert(&((*r)->left), x, cmp);
	}
	else
	{
		if (!(*r)->right)
		{
			(*r)->right = x;
			(*r)->right->parent = *r;
		}
		else
			tree_insert(&((*r)->right), x, cmp);
	}
}

void			graph_insert(t_btree **r, t_btree *n, int (*c)(void *, void *))
{
	tree_insert(r, n, c);
	graph_balance_rb(r, n);
	(*r)->color = RB_BLACK;
}

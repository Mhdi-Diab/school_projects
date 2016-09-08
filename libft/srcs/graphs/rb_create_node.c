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

t_btree	*rb_create_node(char *index, char *data)
{
	t_btree *new;

	(void)data;
	new = (t_btree *)malloc(sizeof(t_btree));
	if (new)
	{
		new->index = ft_strdup(index);
		new->color = RB_RED;
		new->content = NULL;
		new->parent = NULL;
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}

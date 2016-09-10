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

int		graph_depth(t_btree *node)
{
	int left_depth;
	int right_depth;

	if (node == NULL)
		return (0);
	left_depth = graph_depth(node->left);
	right_depth = graph_depth(node->right);
	return (left_depth > right_depth ? left_depth + 1 : right_depth + 1);
}

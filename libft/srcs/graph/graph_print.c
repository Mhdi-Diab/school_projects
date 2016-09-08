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

void	graph_print(t_btree *r, void (*print)(t_btree *, int level))
{
	static int level = 0;
	if (r)
	{
		print(r, level++);
		graph_print(r->left, print);
		graph_print(r->right, print);
		level--;
	}
}

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

void	graph_print_infix(t_btree *r, void (*print)(t_btree *, int level))
{
	static int level = 0;

	if (r)
	{
		level++;
		graph_print_prefix(r->left, print);
		print(r, level -1);
		graph_print_prefix(r->right, print);
		level--;
	}
}

void	graph_print_postfix(t_btree *r, void (*print)(t_btree *, int level))
{
	static int level = 0;

	if (r)
	{
		level++;
		graph_print_prefix(r->left, print);
		graph_print_prefix(r->right, print);
		print(r, --level);
	}
}

void	graph_print_prefix(t_btree *r, void (*print)(t_btree *, int level))
{
	static int level = 0;

	if (r)
	{
		print(r, level++);
		graph_print_prefix(r->left, print);
		graph_print_prefix(r->right, print);
		level--;
	}
}

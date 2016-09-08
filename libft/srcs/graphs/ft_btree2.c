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

void	btree_search(t_btree *r, char *k,
	int (*cmp)(char *, char *), t_list **list)
{
	char *str;

	if (r)
	{
		if ((*cmp)(r->index, k) == 0)
		{
			str = ft_strtrim(r->index);
			ft_lstadd_back(list, ft_lstnew(str, ft_strlen(str) + 1));
			free(str);
		}
		btree_search(r->left, k, cmp, list);
		btree_search(r->right, k, cmp, list);
	}
}

t_btree	*btree_create_node(char *index, char *data)
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

void	tree_insert(t_btree **root, t_btree *x, int (*cmp)(char *, char *))
{
	if (!*root)
		*root = x;
	else if ((*cmp)((*root)->index, x->index) > 0)
	{
		if (!(*root)->left)
		{
			(*root)->left = x;
			(*root)->left->parent = *root;
		}
		else
			tree_insert(&((*root)->left), x, cmp);
	}
	else
	{
		if (!(*root)->right)
		{
			(*root)->right = x;
			(*root)->right->parent = *root;
		}
		else
			tree_insert(&((*root)->right), x, cmp);
	}
}

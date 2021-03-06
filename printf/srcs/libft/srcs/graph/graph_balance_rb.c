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

static void		left_rotate(t_btree **root, t_btree *x)
{
	t_btree *y;

	y = x->right;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		*root = y;
	else
	{
		if (x == (x->parent)->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

static void		right_rotate(t_btree **root, t_btree *y)
{
	t_btree *x;

	x = y->left;
	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;
	x->parent = y->parent;
	if (y->parent == NULL)
		*root = x;
	else
	{
		if (y == (y->parent)->right)
			y->parent->right = x;
		else
			y->parent->left = x;
	}
	x->right = y;
	y->parent = x;
}

static void		rb_first_balance(t_btree **root, t_btree **x, t_btree **y)
{
	if (*y && (*y)->color == RB_RED)
	{
		(*x)->parent->color = RB_BLACK;
		(*y)->color = RB_BLACK;
		(*x)->parent->parent->color = RB_RED;
		*x = (*x)->parent->parent;
	}
	else
	{
		if (*x == (*x)->parent->right)
		{
			*x = (*x)->parent;
			left_rotate(root, *x);
		}
		(*x)->parent->color = RB_BLACK;
		(*x)->parent->parent->color = RB_RED;
		right_rotate(root, (*x)->parent->parent);
	}
}

static void		rb_second_balance(t_btree **root, t_btree **x, t_btree **y)
{
	if (*y && (*y)->color == RB_RED)
	{
		(*x)->parent->color = RB_BLACK;
		(*y)->color = RB_BLACK;
		(*x)->parent->parent->color = RB_RED;
		*x = (*x)->parent->parent;
	}
	else
	{
		if (*x == (*x)->parent->left)
		{
			*x = (*x)->parent;
			right_rotate(root, *x);
		}
		(*x)->parent->color = RB_BLACK;
		(*x)->parent->parent->color = RB_RED;
		left_rotate(root, (*x)->parent->parent);
	}
}


void			graph_balance_rb(t_btree **r, t_btree *x)
{
	t_btree *y;

	while ((x != *r) && (x->parent->color == RB_RED))
	{
		if (x->parent->parent && x->parent == x->parent->parent->left)
		{
			y = x->parent->parent->right;
			if (!y)
				break ;
			rb_first_balance(r, &x, &y);
		}
		else if (x && x->parent->parent)
		{
			y = x->parent->parent->left;
			rb_second_balance(r, &x, &y);
		}
	}
	(*r)->color = RB_BLACK;
}

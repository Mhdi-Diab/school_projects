/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamano <atamano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:02:21 by atamano           #+#    #+#             */
/*   Updated: 2015/03/24 16:10:16 by atamano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "linked_list.h"
# include "print.h"
# include "string.h"

typedef enum		e_rb_color
{
	RB_BLACK,
	RB_RED
}					t_rb_color;

typedef struct		s_btree
{
	struct s_btree	*parent;
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
	size_t			item_size;
	enum e_rb_color	color;
}					t_btree;

void				graph_insert(t_btree **r, t_btree *n,
	int (*cmp)(void *, void *));
void				*graph_search(t_btree *r, void *item,
	int (*cmp)(void *, void *));
t_btree				*graph_create_node(void *item, size_t item_size);
void				graph_balance_rb(t_btree **r, t_btree *x);
void				graph_print(t_btree *r, void (*print)(t_btree *, int level));
int					graph_depth(t_btree *node);

#endif

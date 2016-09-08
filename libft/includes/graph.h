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
	char			*index;
	char			*content;
	enum e_rb_color	color;
}					t_btree;

void				rb_insert(t_btree **r, char *index, char *str,
	int (*cmp)(char *, char *));
void				btree_search(t_btree *r, char *k,
	int (*cmp)(char *, char *), t_list **list);
t_btree				*btree_create_node(char *index, char *data);
void				tree_insert(t_btree **root, t_btree *x,
	int (*cmp)(char *, char *));

#endif

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

void	rb_search(t_btree *r, char *k,
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
		rb_search(r->left, k, cmp, list);
		rb_search(r->right, k, cmp, list);
	}
}

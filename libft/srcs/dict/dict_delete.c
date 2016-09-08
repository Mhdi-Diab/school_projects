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

#include "dict.h"

void dict_delete(t_dict *d, const char *key)
{
	t_elt	**prev;
	t_elt	*e;

	prev = &(d->table[dict_hash(key) % d->size]);
	while (*prev != 0)
	{
		if (!ft_strcmp((*prev)->key, key))
		{
			e = *prev;
			*prev = e->next;
			free(e->key);
			free(e->value);
			free(e);
			return ;
		}
		prev = &((*prev)->next);
	}
}

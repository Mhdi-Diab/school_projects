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

const char *dict_search(t_dict *d, const char *key)
{
	t_elt	*e;

	e = d->table[dict_hash(key) % d->size];
	while (e != 0)
	{
		if (!ft_strcmp(e->key, key))
			return e->value;
		e = e->next;
	}
	return (0);
}

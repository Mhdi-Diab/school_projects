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

static void grow(t_dict *d)
{
	t_dict	*d2;
	t_dict	swap;
	int		i;
	t_elt	*e;

	d2 = dict_create(d->size * GROWTH_FACTOR);
	i = 0;
	while (i < d->size)
	{
		e = d->table[i];
		while (e != 0)
		{
			dict_insert(d2, e->key, e->value);
			e = e->next;
		}
		i++;
	}
	swap = *d;
	*d = *d2;
	*d2 = swap;
	dict_destroy(d2);
}

void dict_insert(t_dict *d, const char *key, const char *value)
{
	t_elt			*e;
	unsigned long	h;

	e = malloc(sizeof(*e));
	if (e)
	{
		e->key = ft_strdup(key);
		e->value = ft_strdup(value);
		h = dict_hash(key) % d->size;
		e->next = d->table[h];
		d->table[h] = e;
		d->n++;
		if (d->n >= d->size * MAX_LOAD_FACTOR) {
			grow(d);
		}
	}
}

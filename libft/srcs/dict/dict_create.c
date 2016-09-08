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

t_dict *dict_create(int size)
{
	t_dict	*d;
	int		i;

	d = (t_dict *)malloc(sizeof(*d));
	if (d)
	{
		d->size = size;
		d->n = 0;
		d->table = (t_elt **)malloc(sizeof(t_elt *) * d->size);
		if (d->table)
		{
			i = 0;
			while (i < d->size)
				d->table[i++] = 0;
		}
	}
	return (d);
}

t_dict *dict_init(void)
{
	return dict_create(INITIAL_SIZE);
}

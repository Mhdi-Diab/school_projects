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

void dict_destroy(t_dict *d)
{
	int		i;
	t_elt	*e;
	t_elt	*next;

	i = 0;
	while (i < d->size)
	{
		e = d->table[i];
		while (e != 0) {
			next = e->next;
			free(e->key);
			free(e->content);
			free(e);
			e = next;
		}
		i++;
	}
	free(d->table);
	free(d);
}

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

#ifndef DICT_H
# define DICT_H

# define INITIAL_SIZE (1024)
# define GROWTH_FACTOR (2)
# define MAX_LOAD_FACTOR (1)
# define MULTIPLIER (97)

# include "strings.h"
# include <stdlib.h>
# include <assert.h>
# include <string.h>
# include <stdio.h>

typedef struct		s_elt {
	struct s_elt	*next;
	char			*key;
	void			*content;
	size_t			content_size;
}					t_elt;

typedef struct		s_dict {
	int				size;
	int				n;
	struct s_elt	**table;
}					t_dict;

t_dict				*dict_init(void);
t_dict				*dict_create(int size);
void				dict_destroy(t_dict *d);
void				dict_insert(t_dict *d, const char *key, void *v, size_t t);
void				*dict_search(t_dict *d, const char *key);
void				dict_delete(t_dict *d, const char *key);
unsigned long		dict_hash(const char *s);

#endif

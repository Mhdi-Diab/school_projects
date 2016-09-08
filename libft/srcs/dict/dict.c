#include "dict.h"

t_dict *internal_dict_create(int size)
{
	t_dict *d;
	int i;

	d = malloc(sizeof(*d));
	if (d)
	{
		d->size = size;
		d->n = 0;
		d->table = (t_elt **)malloc(sizeof(t_elt *) * d->size);
		if (d->table)
		{
			for (i = 0; i < d->size; i++)
				d->table[i] = 0;
		}
	}
	return d;
}

t_dict *dict_create(void)
{
	return internal_dict_create(INITIAL_SIZE);
}

void dict_destroy(t_dict *d)
{
	int		i;
	t_elt	*e;
	t_elt	*next;

	for (i = 0; i < d->size; i++) {
		for(e = d->table[i]; e != 0; e = next) {
			next = e->next;
			free(e->key);
			free(e->value);
			free(e);
		}
	}
	free(d->table);
	free(d);
}

static unsigned long hash_function(const char *s)
{
	unsigned const char *us;
	unsigned long h;

	h = 0;

	for (us = (unsigned const char *)s; *us; us++) {
		h = h * MULTIPLIER + *us;
	}

	return h;
}

static void grow(t_dict *d)
{
	t_dict *d2;
	t_dict swap;
	int i;
	t_elt *e;

	d2 = internal_dict_create(d->size * GROWTH_FACTOR);

	for(i = 0; i < d->size; i++) {
		for(e = d->table[i]; e != 0; e = e->next) {
			dict_insert(d2, e->key, e->value);
		}
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

	assert(key);
	assert(value);
	e = malloc(sizeof(*e));
	e->key = ft_strdup(key);
	e->value = ft_strdup(value);
	h = hash_function(key) % d->size;
	e->next = d->table[h];
	d->table[h] = e;
	d->n++;
	if (d->n >= d->size * MAX_LOAD_FACTOR) {
		grow(d);
	}
}

const char *dict_search(t_dict *d, const char *key)
{
	t_elt	*e;

	for (e = d->table[hash_function(key) % d->size]; e != 0; e = e->next) {
		if (!ft_strcmp(e->key, key)) {
			return e->value;
		}
	}

	return 0;
}

void dict_delete(t_dict *d, const char *key)
{
	t_elt	**prev;
	t_elt	*e;

	for (prev = &(d->table[hash_function(key) % d->size]);
		*prev != 0;
		prev = &((*prev)->next)) {
		if (!ft_strcmp((*prev)->key, key)) {
			e = *prev;
			*prev = e->next;
			free(e->key);
			free(e->value);
			free(e);
			return;
		}
	}
}

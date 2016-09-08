#include "dict.h"
#include <stdio.h>

void dict_test(void)
{
	t_dict *d;
	char buf[512];
	int i;

	d = dict_init();

	dict_insert(d, "foo", "hello world");
	puts(dict_search(d, "foo"));
	dict_insert(d, "foo", "hello world2");
	puts(dict_search(d, "foo"));
	dict_delete(d, "foo");
	puts(dict_search(d, "foo"));
	dict_delete(d, "foo");
	assert(dict_search(d, "foo") == 0);
	dict_delete(d, "foo");

	for(i = 0; i < 10000; i++) {
		sprintf(buf, "%d", i);
		dict_insert(d, buf, buf);
	}

	dict_destroy(d);
}

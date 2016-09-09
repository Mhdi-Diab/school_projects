#include "graph.h"
#include <stdio.h>

static int cmp(void *a, void *b)
{
	int *aa = (int *)a;
	int *bb = (int *)b;
	return(*aa > *bb);
}

static void print(t_btree *tree, int level)
{
	int *item = (int *)tree->item;
	printf("%*d\n", level * 10, *item);
}

void 		test_int(int integers[], int len)
{
	t_btree *tree;
	tree = NULL;

	printf("---- RED BLACK BINARY TREE ---\n---- WITH INPUT: ---\n\n{ ");
	for (int i = 0; i < len; i++) {
		printf("%d ", integers[i]);
		graph_insert(&tree, graph_create_node(&integers[i], sizeof(int *)), cmp);
	}
	printf("}\n\n");
	graph_print_prefix(tree, print);
	graph_del(tree, ft_memdel);

}

void 		graph_int_test(void)
{
	int t1[] = {13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
	int t2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	test_int(t1, 10);
	test_int(t2, 10);
}

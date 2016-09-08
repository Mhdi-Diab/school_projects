#include "graph.h"
#include <stdio.h>

static int cmp(void *a, void *b)
{
	return (ft_strcmp((char *)a, (char *)b));
}

static void print(t_btree *tree, int level)
{
	printf("%*s\n", level * 10, (char *)tree->item);
}

static void 		test_str(char *strings[], int len)
{
	t_btree *tree;
	tree = NULL;

	printf("---- RED BLACK BINARY TREE ---\n---- WITH INPUT: ---\n\n{ ");
	for (int i = 0; i < len; i++) {
		printf("%s ", strings[i]);
		graph_insert(&tree, graph_create_node(strings[i], ft_strlen(strings[i]) + 1), cmp);
	}
	printf("}\n\n");
	graph_print(tree, print);
}

void 		graph_str_test(void)
{
	char *t1[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"};
	char *t2[] = {"hello", "World", "mickey", "donald duck", "picsou", "asterix"};

	test_str(t1, 11);
	test_str(t2, 6);
}

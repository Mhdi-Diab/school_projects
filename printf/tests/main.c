#include "printf.h"
#include <limits.h>

int main()
{
	int i = 0;

	// printf("%p\n", &i);
	// ft_printf("%");
	printf("%p\n", &i);
	ft_printf("%p\n", &i);
	// ft_printf("coucou: %3ss hello: %.3hd %%%% j'aime les %s%% ", "coucou", (short)42, "fleurs");
	// PN("\n---REAL---\n");
	// printf("coucou: %3ss hello: %.3hd %%%% j'aime les %s%% ", "coucou", (short)42, "fleurs");
	// PN("\n");
	// printf("%ls", (wchar_t *)"test");
	return (0);
}

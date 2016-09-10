#include "printf.h"

int main()
{
	ft_printf("coucou: %3ss hello: %.3hd %%%% j'aime les %s%% ", "coucou", (short)42, "fleurs");
	PN("\n---REAL---\n");
	printf("coucou: %3ss hello: %.3hd %%%% j'aime les %s%% ", "coucou", (short)42, "fleurs");
	PN("\n");
	// printf("%ls", (wchar_t *)"test");
	return (0);
}

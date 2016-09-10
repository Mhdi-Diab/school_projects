#include "printf.h"

int main()
{
	printf("%D\n", 12312313);
	ft_printf("%p\n", (void *)4242);
	printf("%p\n", (void *)4242);
	printf("%x\n", (unsigned int)4242);
	ft_printf("coucou: %3ss hello: %.3hd %%%% j'aime les %s%% ", "coucou", (short)42, "fleurs");
	PN("\n---REAL---\n");
	printf("coucou: %3ss hello: %.3hd %%%% j'aime les %s%% ", "coucou", (short)42, "fleurs");
	PN("\n");
	// printf("%ls", (wchar_t *)"test");
	return (0);
}

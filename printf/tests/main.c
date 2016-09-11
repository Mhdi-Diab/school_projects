#include "printf.h"
#include <limits.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	int i;
	char c = 42;

	i = printf("%hhO, %hhO", 0, USHRT_MAX);
	P("\n%d\n", i);
	i = ft_printf("%hhO, %hhO", 0, USHRT_MAX);
	P("\n%d\n", i);
	return (0);
}

#include "printf.h"
#include <limits.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	int i;
	int c = 42121;

	i = printf("%#.o, %#.0o", 0, 0);
	P("\n%d\n", i);
	i = ft_printf("%#.o, %#.0o", 0, 0);
	P("\n%d\n", i);
	return (0);
}

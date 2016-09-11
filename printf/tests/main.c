#include "printf.h"
#include <limits.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	int i;

	i = printf("\nlui: %S", L"Α α");
	P("\n%d\n", i);
	i = ft_printf("\nmoi: %S", L"Α α");
	P("\n%d\n", i);
	return (0);
}

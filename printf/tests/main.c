#include "printf.h"
#include <limits.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");

	printf("%C\n", 945);
	ft_printf("%C\n", 945);
	return (0);
}

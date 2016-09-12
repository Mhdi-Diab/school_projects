#include "printf.h"
#include <limits.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	int i;
	int c = 42121;

	i = printf("%.4S", L"我是一只猫。");
	P("\n%d\n", i);
	i = ft_printf("%.4S", L"我是一只猫。");
	P("\n%d\n", i);
	return (0);
}

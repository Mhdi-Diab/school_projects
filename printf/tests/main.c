#include "printf.h"
#include <limits.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	int i;
	char c = 42;

	i = printf("%s|%d|%X|%%|%S|%D|%i|%o|%O|%u|%U|%x|%X|%c|%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	P("\n%d\n", i);
	i = ft_printf("%s|%d|%X|%%|%S|%D|%i|%o|%O|%u|%U|%x|%X|%c|%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	P("\n%d\n", i);
	return (0);
}

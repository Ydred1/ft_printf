#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	char 	*p = {"bonsoir"};
	unsigned int i = 4000000000;
	char	string[] = "%test %e";
	string[1] = -100;

	ft_printf("%%c option ↴\n\t\\0\t→\t%c\n\talpha\t→\t%c\n", '\0', 'A');
	ft_printf("------------------------------------------\n");
	ft_printf("%%s option ↴\n\ttext\t→\t%s\n\tnull\t→\t%s\n\tempty\t→%s\n", "Bonsoir je suis une chaine de charactere", NULL, "");
	ft_printf("------------------------------------------\n");
	ft_printf("%%p option ↴\n\tpointer\t→\t%p\n\tnull\t→\t%p\n", p, NULL);
	ft_printf("------------------------------------------\n");
	ft_printf("%%d option ↴\n\tdecimal\t→\t%d\n\tMAX\t→\t%d\n\tMIN\t→\t%d\n\tZERO\t→\t%d\n", 1102934, INT_MAX, INT_MIN, 0);
	ft_printf("------------------------------------------\n");
	ft_printf("%%i option ↴\n\tinteger\t→\t%d\n\tMAX\t→\t%d\n\tMIN\t→\t%d\n\tZERO\t→\t%d\n", 228357, INT_MAX, INT_MIN, 0);
	ft_printf("------------------------------------------\n");
	ft_printf("%%u option ↴\n\tuint\t→\t%u\n\tMAX\t→\t%u\n\tZERO\t→\t%u\n", 3222039281, UINT_MAX, 0);
	ft_printf("------------------------------------------\n");
	ft_printf("%%x option ↴\n\thexa\t→\t%x\n\tMAX\t→\t%x\n\tMIN\t→\t%x\n\tZERO\t→\t%x\n", 2320981, INT_MAX, INT_MIN, 0);
	ft_printf("------------------------------------------\n");
	ft_printf("%%X option ↴\n\thexa\t→\t%X\n\tMAX\t→\t%X\n\tMIN\t→\t%X\n\tZERO\t→\t%X\n", 2320981, INT_MAX, INT_MIN, 0);
	ft_printf("------------------------------------------\n");
	ft_printf("%%%% option ↴\n\tmany\t→\t%%%%%%%%%%\n");
	ft_printf("------------------------------------------\n");
	ft_printf(string);
	return (0);
}
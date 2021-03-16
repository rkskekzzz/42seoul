/*
** charmstr@student.42.fr
*/

#include "../includes/printf_lover_test_func.h"
#include "../includes/ft_printf.h"
#include "../includes/printf_lover_test_func.h"
#include "../includes/ft_printf.h"
#include "../includes/printf_lover_test_func.h"
#include "../includes/ft_printf.h"
#include "../includes/printf_lover_test_func.h"
#include "../includes/ft_printf.h"
#include "../includes/printf_lover_test_func.h"
#include "../includes/ft_printf.h"
#include "../includes/printf_lover_test_func.h"
#include "../includes/ft_printf.h"
#include <stdio.h>
#include <assert.h>
#include "../includes/printf_lover_test_func.h"

int	test_func_n(int n)
{
setbuf(stdout, NULL);
assert(printf("-->|%%-4.%n|<--", &n) == ft_printf("-->|%%-4.%n|<--", &n));
assert(printf("-->|%%-4%n|<--", &n) == ft_printf("-->|%%-4%n|<--", &n));
assert(printf("-->|%%-3.%n|<--", &n) == ft_printf("-->|%%-3.%n|<--", &n));
assert(printf("-->|%%-3%n|<--", &n) == ft_printf("-->|%%-3%n|<--", &n));
assert(printf("-->|%%-2.%n|<--", &n) == ft_printf("-->|%%-2.%n|<--", &n));
assert(printf("-->|%%-2%n|<--", &n) == ft_printf("-->|%%-2%n|<--", &n));
assert(printf("-->|%%-1.%n|<--", &n) == ft_printf("-->|%%-1.%n|<--", &n));
assert(printf("-->|%%-1%n|<--", &n) == ft_printf("-->|%%-1%n|<--", &n));
assert(printf("-->|%%.%n|<--", &n) == ft_printf("-->|%%.%n|<--", &n));
assert(printf("-->|%%%n|<--", &n) == ft_printf("-->|%%%n|<--", &n));
assert(printf("-->|%%*.%n|<--", &n) == ft_printf("-->|%%*.%n|<--", &n));
assert(printf("-->|%%*%n|<--", &n) == ft_printf("-->|%%*%n|<--", &n));
assert(printf("-->|%%1.%n|<--", &n) == ft_printf("-->|%%1.%n|<--", &n));
assert(printf("-->|%%1%n|<--", &n) == ft_printf("-->|%%1%n|<--", &n));
assert(printf("-->|%%2.%n|<--", &n) == ft_printf("-->|%%2.%n|<--", &n));
assert(printf("-->|%%2%n|<--", &n) == ft_printf("-->|%%2%n|<--", &n));
assert(printf("-->|%%3.%n|<--", &n) == ft_printf("-->|%%3.%n|<--", &n));
assert(printf("-->|%%3%n|<--", &n) == ft_printf("-->|%%3%n|<--", &n));
assert(printf("-->|%%4.%n|<--", &n) == ft_printf("-->|%%4.%n|<--", &n));
assert(printf("-->|%%4%n|<--", &n) == ft_printf("-->|%%4%n|<--", &n));
	return(0);
}
/*
** charmstr@student.42.fr
**
** 40 different calls generated automatically according to your options
*/

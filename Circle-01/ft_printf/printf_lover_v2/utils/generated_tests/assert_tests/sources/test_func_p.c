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

int	test_func_p(void *p)
{
setbuf(stdout, NULL);
assert(printf("-->|%-16.p|<--\n", p) == ft_printf("-->|%-16.p|<--\n", p));
assert(printf("-->|%-16p|<--\n", p) == ft_printf("-->|%-16p|<--\n", p));
assert(printf("-->|%-15.p|<--\n", p) == ft_printf("-->|%-15.p|<--\n", p));
assert(printf("-->|%-15p|<--\n", p) == ft_printf("-->|%-15p|<--\n", p));
assert(printf("-->|%-14.p|<--\n", p) == ft_printf("-->|%-14.p|<--\n", p));
assert(printf("-->|%-14p|<--\n", p) == ft_printf("-->|%-14p|<--\n", p));
assert(printf("-->|%-13.p|<--\n", p) == ft_printf("-->|%-13.p|<--\n", p));
assert(printf("-->|%-13p|<--\n", p) == ft_printf("-->|%-13p|<--\n", p));
assert(printf("-->|%-12.p|<--\n", p) == ft_printf("-->|%-12.p|<--\n", p));
assert(printf("-->|%-12p|<--\n", p) == ft_printf("-->|%-12p|<--\n", p));
assert(printf("-->|%-11.p|<--\n", p) == ft_printf("-->|%-11.p|<--\n", p));
assert(printf("-->|%-11p|<--\n", p) == ft_printf("-->|%-11p|<--\n", p));
assert(printf("-->|%-9.p|<--\n", p) == ft_printf("-->|%-9.p|<--\n", p));
assert(printf("-->|%-9p|<--\n", p) == ft_printf("-->|%-9p|<--\n", p));
assert(printf("-->|%-8.p|<--\n", p) == ft_printf("-->|%-8.p|<--\n", p));
assert(printf("-->|%-8p|<--\n", p) == ft_printf("-->|%-8p|<--\n", p));
assert(printf("-->|%-7.p|<--\n", p) == ft_printf("-->|%-7.p|<--\n", p));
assert(printf("-->|%-7p|<--\n", p) == ft_printf("-->|%-7p|<--\n", p));
assert(printf("-->|%-6.p|<--\n", p) == ft_printf("-->|%-6.p|<--\n", p));
assert(printf("-->|%-6p|<--\n", p) == ft_printf("-->|%-6p|<--\n", p));
assert(printf("-->|%-5.p|<--\n", p) == ft_printf("-->|%-5.p|<--\n", p));
assert(printf("-->|%-5p|<--\n", p) == ft_printf("-->|%-5p|<--\n", p));
assert(printf("-->|%-4.p|<--\n", p) == ft_printf("-->|%-4.p|<--\n", p));
assert(printf("-->|%-4p|<--\n", p) == ft_printf("-->|%-4p|<--\n", p));
assert(printf("-->|%-3.p|<--\n", p) == ft_printf("-->|%-3.p|<--\n", p));
assert(printf("-->|%-3p|<--\n", p) == ft_printf("-->|%-3p|<--\n", p));
assert(printf("-->|%-2.p|<--\n", p) == ft_printf("-->|%-2.p|<--\n", p));
assert(printf("-->|%-2p|<--\n", p) == ft_printf("-->|%-2p|<--\n", p));
assert(printf("-->|%-1.p|<--\n", p) == ft_printf("-->|%-1.p|<--\n", p));
assert(printf("-->|%-1p|<--\n", p) == ft_printf("-->|%-1p|<--\n", p));
assert(printf("-->|%.p|<--\n", p) == ft_printf("-->|%.p|<--\n", p));
assert(printf("-->|%p|<--\n", p) == ft_printf("-->|%p|<--\n", p));
assert(printf("-->|%*.p|<--\n", -16, p) == ft_printf("-->|%*.p|<--\n", -16, p));
assert(printf("-->|%*.p|<--\n", -15, p) == ft_printf("-->|%*.p|<--\n", -15, p));
assert(printf("-->|%*.p|<--\n", -14, p) == ft_printf("-->|%*.p|<--\n", -14, p));
assert(printf("-->|%*.p|<--\n", -13, p) == ft_printf("-->|%*.p|<--\n", -13, p));
assert(printf("-->|%*.p|<--\n", -12, p) == ft_printf("-->|%*.p|<--\n", -12, p));
assert(printf("-->|%*.p|<--\n", -11, p) == ft_printf("-->|%*.p|<--\n", -11, p));
assert(printf("-->|%*.p|<--\n", -10, p) == ft_printf("-->|%*.p|<--\n", -10, p));
assert(printf("-->|%*.p|<--\n", -9, p) == ft_printf("-->|%*.p|<--\n", -9, p));
assert(printf("-->|%*.p|<--\n", -8, p) == ft_printf("-->|%*.p|<--\n", -8, p));
assert(printf("-->|%*.p|<--\n", -7, p) == ft_printf("-->|%*.p|<--\n", -7, p));
assert(printf("-->|%*.p|<--\n", -6, p) == ft_printf("-->|%*.p|<--\n", -6, p));
assert(printf("-->|%*.p|<--\n", -5, p) == ft_printf("-->|%*.p|<--\n", -5, p));
assert(printf("-->|%*.p|<--\n", -4, p) == ft_printf("-->|%*.p|<--\n", -4, p));
assert(printf("-->|%*.p|<--\n", -3, p) == ft_printf("-->|%*.p|<--\n", -3, p));
assert(printf("-->|%*.p|<--\n", -2, p) == ft_printf("-->|%*.p|<--\n", -2, p));
assert(printf("-->|%*.p|<--\n", -1, p) == ft_printf("-->|%*.p|<--\n", -1, p));
assert(printf("-->|%*.p|<--\n", 0, p) == ft_printf("-->|%*.p|<--\n", 0, p));
assert(printf("-->|%*.p|<--\n", 1, p) == ft_printf("-->|%*.p|<--\n", 1, p));
assert(printf("-->|%*.p|<--\n", 2, p) == ft_printf("-->|%*.p|<--\n", 2, p));
assert(printf("-->|%*.p|<--\n", 3, p) == ft_printf("-->|%*.p|<--\n", 3, p));
assert(printf("-->|%*.p|<--\n", 4, p) == ft_printf("-->|%*.p|<--\n", 4, p));
assert(printf("-->|%*.p|<--\n", 5, p) == ft_printf("-->|%*.p|<--\n", 5, p));
assert(printf("-->|%*.p|<--\n", 6, p) == ft_printf("-->|%*.p|<--\n", 6, p));
assert(printf("-->|%*.p|<--\n", 7, p) == ft_printf("-->|%*.p|<--\n", 7, p));
assert(printf("-->|%*.p|<--\n", 8, p) == ft_printf("-->|%*.p|<--\n", 8, p));
assert(printf("-->|%*.p|<--\n", 9, p) == ft_printf("-->|%*.p|<--\n", 9, p));
assert(printf("-->|%*.p|<--\n", 10, p) == ft_printf("-->|%*.p|<--\n", 10, p));
assert(printf("-->|%*.p|<--\n", 11, p) == ft_printf("-->|%*.p|<--\n", 11, p));
assert(printf("-->|%*.p|<--\n", 12, p) == ft_printf("-->|%*.p|<--\n", 12, p));
assert(printf("-->|%*.p|<--\n", 13, p) == ft_printf("-->|%*.p|<--\n", 13, p));
assert(printf("-->|%*.p|<--\n", 14, p) == ft_printf("-->|%*.p|<--\n", 14, p));
assert(printf("-->|%*.p|<--\n", 15, p) == ft_printf("-->|%*.p|<--\n", 15, p));
assert(printf("-->|%*.p|<--\n", 16, p) == ft_printf("-->|%*.p|<--\n", 16, p));
assert(printf("-->|%*p|<--\n", -16, p) == ft_printf("-->|%*p|<--\n", -16, p));
assert(printf("-->|%*p|<--\n", -15, p) == ft_printf("-->|%*p|<--\n", -15, p));
assert(printf("-->|%*p|<--\n", -14, p) == ft_printf("-->|%*p|<--\n", -14, p));
assert(printf("-->|%*p|<--\n", -13, p) == ft_printf("-->|%*p|<--\n", -13, p));
assert(printf("-->|%*p|<--\n", -12, p) == ft_printf("-->|%*p|<--\n", -12, p));
assert(printf("-->|%*p|<--\n", -11, p) == ft_printf("-->|%*p|<--\n", -11, p));
assert(printf("-->|%*p|<--\n", -10, p) == ft_printf("-->|%*p|<--\n", -10, p));
assert(printf("-->|%*p|<--\n", -9, p) == ft_printf("-->|%*p|<--\n", -9, p));
assert(printf("-->|%*p|<--\n", -8, p) == ft_printf("-->|%*p|<--\n", -8, p));
assert(printf("-->|%*p|<--\n", -7, p) == ft_printf("-->|%*p|<--\n", -7, p));
assert(printf("-->|%*p|<--\n", -6, p) == ft_printf("-->|%*p|<--\n", -6, p));
assert(printf("-->|%*p|<--\n", -5, p) == ft_printf("-->|%*p|<--\n", -5, p));
assert(printf("-->|%*p|<--\n", -4, p) == ft_printf("-->|%*p|<--\n", -4, p));
assert(printf("-->|%*p|<--\n", -3, p) == ft_printf("-->|%*p|<--\n", -3, p));
assert(printf("-->|%*p|<--\n", -2, p) == ft_printf("-->|%*p|<--\n", -2, p));
assert(printf("-->|%*p|<--\n", -1, p) == ft_printf("-->|%*p|<--\n", -1, p));
assert(printf("-->|%*p|<--\n", 0, p) == ft_printf("-->|%*p|<--\n", 0, p));
assert(printf("-->|%*p|<--\n", 1, p) == ft_printf("-->|%*p|<--\n", 1, p));
assert(printf("-->|%*p|<--\n", 2, p) == ft_printf("-->|%*p|<--\n", 2, p));
assert(printf("-->|%*p|<--\n", 3, p) == ft_printf("-->|%*p|<--\n", 3, p));
assert(printf("-->|%*p|<--\n", 4, p) == ft_printf("-->|%*p|<--\n", 4, p));
assert(printf("-->|%*p|<--\n", 5, p) == ft_printf("-->|%*p|<--\n", 5, p));
assert(printf("-->|%*p|<--\n", 6, p) == ft_printf("-->|%*p|<--\n", 6, p));
assert(printf("-->|%*p|<--\n", 7, p) == ft_printf("-->|%*p|<--\n", 7, p));
assert(printf("-->|%*p|<--\n", 8, p) == ft_printf("-->|%*p|<--\n", 8, p));
assert(printf("-->|%*p|<--\n", 9, p) == ft_printf("-->|%*p|<--\n", 9, p));
assert(printf("-->|%*p|<--\n", 10, p) == ft_printf("-->|%*p|<--\n", 10, p));
assert(printf("-->|%*p|<--\n", 11, p) == ft_printf("-->|%*p|<--\n", 11, p));
assert(printf("-->|%*p|<--\n", 12, p) == ft_printf("-->|%*p|<--\n", 12, p));
assert(printf("-->|%*p|<--\n", 13, p) == ft_printf("-->|%*p|<--\n", 13, p));
assert(printf("-->|%*p|<--\n", 14, p) == ft_printf("-->|%*p|<--\n", 14, p));
assert(printf("-->|%*p|<--\n", 15, p) == ft_printf("-->|%*p|<--\n", 15, p));
assert(printf("-->|%*p|<--\n", 16, p) == ft_printf("-->|%*p|<--\n", 16, p));
assert(printf("-->|%1.p|<--\n", p) == ft_printf("-->|%1.p|<--\n", p));
assert(printf("-->|%1p|<--\n", p) == ft_printf("-->|%1p|<--\n", p));
assert(printf("-->|%2.p|<--\n", p) == ft_printf("-->|%2.p|<--\n", p));
assert(printf("-->|%2p|<--\n", p) == ft_printf("-->|%2p|<--\n", p));
assert(printf("-->|%3.p|<--\n", p) == ft_printf("-->|%3.p|<--\n", p));
assert(printf("-->|%3p|<--\n", p) == ft_printf("-->|%3p|<--\n", p));
assert(printf("-->|%4.p|<--\n", p) == ft_printf("-->|%4.p|<--\n", p));
assert(printf("-->|%4p|<--\n", p) == ft_printf("-->|%4p|<--\n", p));
assert(printf("-->|%5.p|<--\n", p) == ft_printf("-->|%5.p|<--\n", p));
assert(printf("-->|%5p|<--\n", p) == ft_printf("-->|%5p|<--\n", p));
assert(printf("-->|%6.p|<--\n", p) == ft_printf("-->|%6.p|<--\n", p));
assert(printf("-->|%6p|<--\n", p) == ft_printf("-->|%6p|<--\n", p));
assert(printf("-->|%7.p|<--\n", p) == ft_printf("-->|%7.p|<--\n", p));
assert(printf("-->|%7p|<--\n", p) == ft_printf("-->|%7p|<--\n", p));
assert(printf("-->|%8.p|<--\n", p) == ft_printf("-->|%8.p|<--\n", p));
assert(printf("-->|%8p|<--\n", p) == ft_printf("-->|%8p|<--\n", p));
assert(printf("-->|%9.p|<--\n", p) == ft_printf("-->|%9.p|<--\n", p));
assert(printf("-->|%9p|<--\n", p) == ft_printf("-->|%9p|<--\n", p));
assert(printf("-->|%11.p|<--\n", p) == ft_printf("-->|%11.p|<--\n", p));
assert(printf("-->|%11p|<--\n", p) == ft_printf("-->|%11p|<--\n", p));
assert(printf("-->|%12.p|<--\n", p) == ft_printf("-->|%12.p|<--\n", p));
assert(printf("-->|%12p|<--\n", p) == ft_printf("-->|%12p|<--\n", p));
assert(printf("-->|%13.p|<--\n", p) == ft_printf("-->|%13.p|<--\n", p));
assert(printf("-->|%13p|<--\n", p) == ft_printf("-->|%13p|<--\n", p));
assert(printf("-->|%14.p|<--\n", p) == ft_printf("-->|%14.p|<--\n", p));
assert(printf("-->|%14p|<--\n", p) == ft_printf("-->|%14p|<--\n", p));
assert(printf("-->|%15.p|<--\n", p) == ft_printf("-->|%15.p|<--\n", p));
assert(printf("-->|%15p|<--\n", p) == ft_printf("-->|%15p|<--\n", p));
assert(printf("-->|%16.p|<--\n", p) == ft_printf("-->|%16.p|<--\n", p));
assert(printf("-->|%16p|<--\n", p) == ft_printf("-->|%16p|<--\n", p));
assert(printf("-->|%--16.p|<--\n", p) == ft_printf("-->|%--16.p|<--\n", p));
assert(printf("-->|%--16p|<--\n", p) == ft_printf("-->|%--16p|<--\n", p));
assert(printf("-->|%--15.p|<--\n", p) == ft_printf("-->|%--15.p|<--\n", p));
assert(printf("-->|%--15p|<--\n", p) == ft_printf("-->|%--15p|<--\n", p));
assert(printf("-->|%--14.p|<--\n", p) == ft_printf("-->|%--14.p|<--\n", p));
assert(printf("-->|%--14p|<--\n", p) == ft_printf("-->|%--14p|<--\n", p));
assert(printf("-->|%--13.p|<--\n", p) == ft_printf("-->|%--13.p|<--\n", p));
assert(printf("-->|%--13p|<--\n", p) == ft_printf("-->|%--13p|<--\n", p));
assert(printf("-->|%--12.p|<--\n", p) == ft_printf("-->|%--12.p|<--\n", p));
assert(printf("-->|%--12p|<--\n", p) == ft_printf("-->|%--12p|<--\n", p));
assert(printf("-->|%--11.p|<--\n", p) == ft_printf("-->|%--11.p|<--\n", p));
assert(printf("-->|%--11p|<--\n", p) == ft_printf("-->|%--11p|<--\n", p));
assert(printf("-->|%--9.p|<--\n", p) == ft_printf("-->|%--9.p|<--\n", p));
assert(printf("-->|%--9p|<--\n", p) == ft_printf("-->|%--9p|<--\n", p));
assert(printf("-->|%--8.p|<--\n", p) == ft_printf("-->|%--8.p|<--\n", p));
assert(printf("-->|%--8p|<--\n", p) == ft_printf("-->|%--8p|<--\n", p));
assert(printf("-->|%--7.p|<--\n", p) == ft_printf("-->|%--7.p|<--\n", p));
assert(printf("-->|%--7p|<--\n", p) == ft_printf("-->|%--7p|<--\n", p));
assert(printf("-->|%--6.p|<--\n", p) == ft_printf("-->|%--6.p|<--\n", p));
assert(printf("-->|%--6p|<--\n", p) == ft_printf("-->|%--6p|<--\n", p));
assert(printf("-->|%--5.p|<--\n", p) == ft_printf("-->|%--5.p|<--\n", p));
assert(printf("-->|%--5p|<--\n", p) == ft_printf("-->|%--5p|<--\n", p));
assert(printf("-->|%--4.p|<--\n", p) == ft_printf("-->|%--4.p|<--\n", p));
assert(printf("-->|%--4p|<--\n", p) == ft_printf("-->|%--4p|<--\n", p));
assert(printf("-->|%--3.p|<--\n", p) == ft_printf("-->|%--3.p|<--\n", p));
assert(printf("-->|%--3p|<--\n", p) == ft_printf("-->|%--3p|<--\n", p));
assert(printf("-->|%--2.p|<--\n", p) == ft_printf("-->|%--2.p|<--\n", p));
assert(printf("-->|%--2p|<--\n", p) == ft_printf("-->|%--2p|<--\n", p));
assert(printf("-->|%--1.p|<--\n", p) == ft_printf("-->|%--1.p|<--\n", p));
assert(printf("-->|%--1p|<--\n", p) == ft_printf("-->|%--1p|<--\n", p));
assert(printf("-->|%-.p|<--\n", p) == ft_printf("-->|%-.p|<--\n", p));
assert(printf("-->|%-p|<--\n", p) == ft_printf("-->|%-p|<--\n", p));
assert(printf("-->|%-*.p|<--\n", -16, p) == ft_printf("-->|%-*.p|<--\n", -16, p));
assert(printf("-->|%-*.p|<--\n", -15, p) == ft_printf("-->|%-*.p|<--\n", -15, p));
assert(printf("-->|%-*.p|<--\n", -14, p) == ft_printf("-->|%-*.p|<--\n", -14, p));
assert(printf("-->|%-*.p|<--\n", -13, p) == ft_printf("-->|%-*.p|<--\n", -13, p));
assert(printf("-->|%-*.p|<--\n", -12, p) == ft_printf("-->|%-*.p|<--\n", -12, p));
assert(printf("-->|%-*.p|<--\n", -11, p) == ft_printf("-->|%-*.p|<--\n", -11, p));
assert(printf("-->|%-*.p|<--\n", -10, p) == ft_printf("-->|%-*.p|<--\n", -10, p));
assert(printf("-->|%-*.p|<--\n", -9, p) == ft_printf("-->|%-*.p|<--\n", -9, p));
assert(printf("-->|%-*.p|<--\n", -8, p) == ft_printf("-->|%-*.p|<--\n", -8, p));
assert(printf("-->|%-*.p|<--\n", -7, p) == ft_printf("-->|%-*.p|<--\n", -7, p));
assert(printf("-->|%-*.p|<--\n", -6, p) == ft_printf("-->|%-*.p|<--\n", -6, p));
assert(printf("-->|%-*.p|<--\n", -5, p) == ft_printf("-->|%-*.p|<--\n", -5, p));
assert(printf("-->|%-*.p|<--\n", -4, p) == ft_printf("-->|%-*.p|<--\n", -4, p));
assert(printf("-->|%-*.p|<--\n", -3, p) == ft_printf("-->|%-*.p|<--\n", -3, p));
assert(printf("-->|%-*.p|<--\n", -2, p) == ft_printf("-->|%-*.p|<--\n", -2, p));
assert(printf("-->|%-*.p|<--\n", -1, p) == ft_printf("-->|%-*.p|<--\n", -1, p));
assert(printf("-->|%-*.p|<--\n", 0, p) == ft_printf("-->|%-*.p|<--\n", 0, p));
assert(printf("-->|%-*.p|<--\n", 1, p) == ft_printf("-->|%-*.p|<--\n", 1, p));
assert(printf("-->|%-*.p|<--\n", 2, p) == ft_printf("-->|%-*.p|<--\n", 2, p));
assert(printf("-->|%-*.p|<--\n", 3, p) == ft_printf("-->|%-*.p|<--\n", 3, p));
assert(printf("-->|%-*.p|<--\n", 4, p) == ft_printf("-->|%-*.p|<--\n", 4, p));
assert(printf("-->|%-*.p|<--\n", 5, p) == ft_printf("-->|%-*.p|<--\n", 5, p));
assert(printf("-->|%-*.p|<--\n", 6, p) == ft_printf("-->|%-*.p|<--\n", 6, p));
assert(printf("-->|%-*.p|<--\n", 7, p) == ft_printf("-->|%-*.p|<--\n", 7, p));
assert(printf("-->|%-*.p|<--\n", 8, p) == ft_printf("-->|%-*.p|<--\n", 8, p));
assert(printf("-->|%-*.p|<--\n", 9, p) == ft_printf("-->|%-*.p|<--\n", 9, p));
assert(printf("-->|%-*.p|<--\n", 10, p) == ft_printf("-->|%-*.p|<--\n", 10, p));
assert(printf("-->|%-*.p|<--\n", 11, p) == ft_printf("-->|%-*.p|<--\n", 11, p));
assert(printf("-->|%-*.p|<--\n", 12, p) == ft_printf("-->|%-*.p|<--\n", 12, p));
assert(printf("-->|%-*.p|<--\n", 13, p) == ft_printf("-->|%-*.p|<--\n", 13, p));
assert(printf("-->|%-*.p|<--\n", 14, p) == ft_printf("-->|%-*.p|<--\n", 14, p));
assert(printf("-->|%-*.p|<--\n", 15, p) == ft_printf("-->|%-*.p|<--\n", 15, p));
assert(printf("-->|%-*.p|<--\n", 16, p) == ft_printf("-->|%-*.p|<--\n", 16, p));
assert(printf("-->|%-*p|<--\n", -16, p) == ft_printf("-->|%-*p|<--\n", -16, p));
assert(printf("-->|%-*p|<--\n", -15, p) == ft_printf("-->|%-*p|<--\n", -15, p));
assert(printf("-->|%-*p|<--\n", -14, p) == ft_printf("-->|%-*p|<--\n", -14, p));
assert(printf("-->|%-*p|<--\n", -13, p) == ft_printf("-->|%-*p|<--\n", -13, p));
assert(printf("-->|%-*p|<--\n", -12, p) == ft_printf("-->|%-*p|<--\n", -12, p));
assert(printf("-->|%-*p|<--\n", -11, p) == ft_printf("-->|%-*p|<--\n", -11, p));
assert(printf("-->|%-*p|<--\n", -10, p) == ft_printf("-->|%-*p|<--\n", -10, p));
assert(printf("-->|%-*p|<--\n", -9, p) == ft_printf("-->|%-*p|<--\n", -9, p));
assert(printf("-->|%-*p|<--\n", -8, p) == ft_printf("-->|%-*p|<--\n", -8, p));
assert(printf("-->|%-*p|<--\n", -7, p) == ft_printf("-->|%-*p|<--\n", -7, p));
assert(printf("-->|%-*p|<--\n", -6, p) == ft_printf("-->|%-*p|<--\n", -6, p));
assert(printf("-->|%-*p|<--\n", -5, p) == ft_printf("-->|%-*p|<--\n", -5, p));
assert(printf("-->|%-*p|<--\n", -4, p) == ft_printf("-->|%-*p|<--\n", -4, p));
assert(printf("-->|%-*p|<--\n", -3, p) == ft_printf("-->|%-*p|<--\n", -3, p));
assert(printf("-->|%-*p|<--\n", -2, p) == ft_printf("-->|%-*p|<--\n", -2, p));
assert(printf("-->|%-*p|<--\n", -1, p) == ft_printf("-->|%-*p|<--\n", -1, p));
assert(printf("-->|%-*p|<--\n", 0, p) == ft_printf("-->|%-*p|<--\n", 0, p));
assert(printf("-->|%-*p|<--\n", 1, p) == ft_printf("-->|%-*p|<--\n", 1, p));
assert(printf("-->|%-*p|<--\n", 2, p) == ft_printf("-->|%-*p|<--\n", 2, p));
assert(printf("-->|%-*p|<--\n", 3, p) == ft_printf("-->|%-*p|<--\n", 3, p));
assert(printf("-->|%-*p|<--\n", 4, p) == ft_printf("-->|%-*p|<--\n", 4, p));
assert(printf("-->|%-*p|<--\n", 5, p) == ft_printf("-->|%-*p|<--\n", 5, p));
assert(printf("-->|%-*p|<--\n", 6, p) == ft_printf("-->|%-*p|<--\n", 6, p));
assert(printf("-->|%-*p|<--\n", 7, p) == ft_printf("-->|%-*p|<--\n", 7, p));
assert(printf("-->|%-*p|<--\n", 8, p) == ft_printf("-->|%-*p|<--\n", 8, p));
assert(printf("-->|%-*p|<--\n", 9, p) == ft_printf("-->|%-*p|<--\n", 9, p));
assert(printf("-->|%-*p|<--\n", 10, p) == ft_printf("-->|%-*p|<--\n", 10, p));
assert(printf("-->|%-*p|<--\n", 11, p) == ft_printf("-->|%-*p|<--\n", 11, p));
assert(printf("-->|%-*p|<--\n", 12, p) == ft_printf("-->|%-*p|<--\n", 12, p));
assert(printf("-->|%-*p|<--\n", 13, p) == ft_printf("-->|%-*p|<--\n", 13, p));
assert(printf("-->|%-*p|<--\n", 14, p) == ft_printf("-->|%-*p|<--\n", 14, p));
assert(printf("-->|%-*p|<--\n", 15, p) == ft_printf("-->|%-*p|<--\n", 15, p));
assert(printf("-->|%-*p|<--\n", 16, p) == ft_printf("-->|%-*p|<--\n", 16, p));
assert(printf("-->|%-1.p|<--\n", p) == ft_printf("-->|%-1.p|<--\n", p));
assert(printf("-->|%-1p|<--\n", p) == ft_printf("-->|%-1p|<--\n", p));
assert(printf("-->|%-2.p|<--\n", p) == ft_printf("-->|%-2.p|<--\n", p));
assert(printf("-->|%-2p|<--\n", p) == ft_printf("-->|%-2p|<--\n", p));
assert(printf("-->|%-3.p|<--\n", p) == ft_printf("-->|%-3.p|<--\n", p));
assert(printf("-->|%-3p|<--\n", p) == ft_printf("-->|%-3p|<--\n", p));
assert(printf("-->|%-4.p|<--\n", p) == ft_printf("-->|%-4.p|<--\n", p));
assert(printf("-->|%-4p|<--\n", p) == ft_printf("-->|%-4p|<--\n", p));
assert(printf("-->|%-5.p|<--\n", p) == ft_printf("-->|%-5.p|<--\n", p));
assert(printf("-->|%-5p|<--\n", p) == ft_printf("-->|%-5p|<--\n", p));
assert(printf("-->|%-6.p|<--\n", p) == ft_printf("-->|%-6.p|<--\n", p));
assert(printf("-->|%-6p|<--\n", p) == ft_printf("-->|%-6p|<--\n", p));
assert(printf("-->|%-7.p|<--\n", p) == ft_printf("-->|%-7.p|<--\n", p));
assert(printf("-->|%-7p|<--\n", p) == ft_printf("-->|%-7p|<--\n", p));
assert(printf("-->|%-8.p|<--\n", p) == ft_printf("-->|%-8.p|<--\n", p));
assert(printf("-->|%-8p|<--\n", p) == ft_printf("-->|%-8p|<--\n", p));
assert(printf("-->|%-9.p|<--\n", p) == ft_printf("-->|%-9.p|<--\n", p));
assert(printf("-->|%-9p|<--\n", p) == ft_printf("-->|%-9p|<--\n", p));
assert(printf("-->|%-11.p|<--\n", p) == ft_printf("-->|%-11.p|<--\n", p));
assert(printf("-->|%-11p|<--\n", p) == ft_printf("-->|%-11p|<--\n", p));
assert(printf("-->|%-12.p|<--\n", p) == ft_printf("-->|%-12.p|<--\n", p));
assert(printf("-->|%-12p|<--\n", p) == ft_printf("-->|%-12p|<--\n", p));
assert(printf("-->|%-13.p|<--\n", p) == ft_printf("-->|%-13.p|<--\n", p));
assert(printf("-->|%-13p|<--\n", p) == ft_printf("-->|%-13p|<--\n", p));
assert(printf("-->|%-14.p|<--\n", p) == ft_printf("-->|%-14.p|<--\n", p));
assert(printf("-->|%-14p|<--\n", p) == ft_printf("-->|%-14p|<--\n", p));
assert(printf("-->|%-15.p|<--\n", p) == ft_printf("-->|%-15.p|<--\n", p));
assert(printf("-->|%-15p|<--\n", p) == ft_printf("-->|%-15p|<--\n", p));
assert(printf("-->|%-16.p|<--\n", p) == ft_printf("-->|%-16.p|<--\n", p));
assert(printf("-->|%-16p|<--\n", p) == ft_printf("-->|%-16p|<--\n", p));
	return(0);
}
/*
** charmstr@student.42.fr
**
** 512 different calls generated automatically according to your options
*/

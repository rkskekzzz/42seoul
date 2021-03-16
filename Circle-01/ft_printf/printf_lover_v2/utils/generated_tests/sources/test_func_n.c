/*
** charmstr@student.42.fr
*/

#include <stdio.h>
#include "../includes/printf_lover_test_func.h"

int	test_func_n(int n)
{
setbuf(stdout, NULL);
	my_ft_putstr_fd("Printf(\"-->|%%-4.%n|<--\", &n);	==>	", 1);
	printf("-->|%%-4.%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%-4%n|<--\", &n);	==>	", 1);
	printf("-->|%%-4%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%-3.%n|<--\", &n);	==>	", 1);
	printf("-->|%%-3.%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%-3%n|<--\", &n);	==>	", 1);
	printf("-->|%%-3%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%-2.%n|<--\", &n);	==>	", 1);
	printf("-->|%%-2.%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%-2%n|<--\", &n);	==>	", 1);
	printf("-->|%%-2%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%-1.%n|<--\", &n);	==>	", 1);
	printf("-->|%%-1.%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%-1%n|<--\", &n);	==>	", 1);
	printf("-->|%%-1%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%.%n|<--\", &n);	==>	", 1);
	printf("-->|%%.%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%%n|<--\", &n);	==>	", 1);
	printf("-->|%%%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%*.%n|<--\", &n);	==>	", 1);
	printf("-->|%%*.%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%*%n|<--\", &n);	==>	", 1);
	printf("-->|%%*%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%1.%n|<--\", &n);	==>	", 1);
	printf("-->|%%1.%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%1%n|<--\", &n);	==>	", 1);
	printf("-->|%%1%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%2.%n|<--\", &n);	==>	", 1);
	printf("-->|%%2.%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%2%n|<--\", &n);	==>	", 1);
	printf("-->|%%2%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%3.%n|<--\", &n);	==>	", 1);
	printf("-->|%%3.%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%3%n|<--\", &n);	==>	", 1);
	printf("-->|%%3%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%4.%n|<--\", &n);	==>	", 1);
	printf("-->|%%4.%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	my_ft_putstr_fd("Printf(\"-->|%%4%n|<--\", &n);	==>	", 1);
	printf("-->|%%4%n|<--", &n);
	my_ft_putnbr_fd(n, 1);
my_ft_putstr_fd("\n", 1);
	return(0);
}
/*
** charmstr@student.42.fr
**
** 40 different calls generated automatically according to your options
*/

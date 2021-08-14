#include "library.h"

int	ph_atoi(char *str)
{
	int	ret;

	ret = 0;
	if (*str == '-')
	{
		exit(1);
	}
	while (*str)
	{
		ret = ret * 10 + (*str - '0');
		++str;
	}
	if ((*str) != 0)
		ph_exit("not num");
	return (ret);
}

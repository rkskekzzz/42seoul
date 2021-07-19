#include "library.h"

int	ph_atoi(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		ret = ret * 10 + (*str - '0');
		++str;
	}
	return (ret);
}

#include "library.h"

t_bool	ph_isnum(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
	}
	return (TRUE);
}

t_bool	ph_exit(char *s)
{
	printf("%s\n", s);
	exit(1);
}

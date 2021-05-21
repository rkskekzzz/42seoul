#include "minirt.h"

double	rand_num(int anti, int min, int max)
{
	if (anti == 0)
		return (0);
	if (min < max)
		return ((double)(min + (max - min)) *rand_num(1, 0, 0));
	else
		return ((double)rand() / ((double)RAND_MAX));
}

int		ft_atoi(char *line)
{
	int num;
	int sign;

	sign = 1;
	num = 0;
	if (*line == '-')
	{
		sign = -1;
		++(line);
	}
	while (ft_isdigit(*line))
	{
		num = num * 10 + (*line - '0');
		++(line);
	}
	return num * sign;
}

double ft_atod(double *f, char *line)
{
	double	num;
	int		sign;
	char* 	pos;

	if (!ft_isnum(line))
		return (ERROR);
	sign = 1;
	pos = 0;
	num = 0;
	if(*line == '-')
	{
		sign = -1;
		++(line);
	}
	while (ft_isdigit(*line) || *line == '.')
	{
		if (*line == '.')
			pos = line + 1;
		else
			num = num * 10 + (*line - '0');
		++(line);
	}
	*f = num * sign;
	if (pos)
		*f = num / pow(10, line - pos) * sign;
	return (OK);
}

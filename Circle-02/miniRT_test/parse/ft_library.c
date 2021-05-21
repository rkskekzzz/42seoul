#include "main.h"

int ft_arrsize(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
		++i;
	return (i);
}

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

int		ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	while(s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

void	*ft_memset(void *dest, int value, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		*((char *)dest + i) = value;
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int ft_isspace(char c)
{
	return (c == 32);
}

int ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int ft_isnum(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		++i;
	while(str[i])
	{
		if(!ft_isdigit(str[i]) && str[i] != '.')
			return (ERROR);
		++i;
	}
	return (OK);
}

int ft_atoi(char *line)
{
	int num;
	int sign;

	sign = 1;
	num = 0;
	if(*line == '-')
	{
		sign = -1;
		++(line);
	}
	while(ft_isdigit(*line))
	{
		num = num * 10 + (*line - '0');
		++(line);
	}
	return num * sign;
}

double ft_atod(char *line)
{
	double num;
	int sign;
	char** pos;

	pos = &line;
	sign = 1;
	num = 0;
	if(*line == '-')
	{
		sign = -1;
		++(line);
	}
	while(ft_isdigit(*line) || *line == '.')
	{
		if (*line == '.')
			pos = &line - 1;
		else
			num = num * 10 + (*line - '0');
		++(line);
	}
	return (num / pow(10, &line - pos) * sign) ;
}

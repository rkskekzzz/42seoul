#include "push_swap.h"

void	*ps_memset(void *dest, int value, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		*((char *)dest + i) = value;
	return (dest);
}

t_bool	prt_error(char *message)
{
	return (printf("%s\n", message) >= 0);
}

void 	ps_freend(void **ptr)
{
	free(*ptr);
	*ptr = 0;
}

int	ps_isnum_atoi(char *s)
{
	int			sign;
	long long	ret;

	sign = 1;
	ret = 0;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s >= '0' && *s <= '9')
	{
		ret = ret * 10 + (*s++ - '0');
		if (ret > INTMAX)
			exit(prt_error("Numsize Error!"));
	}
	if (*s != 0)
		exit(prt_error("Not Number Error!"));
	return ((int)ret * sign);
}

t_list	*new_list(int val)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->link[0] = NULL;
	new_node->link[1] = NULL;
	return (new_node);
}

void	free_list(int t)
{
	while (ht()->size[t >> 1])
		del_list(t);
	ps_freend((void *)&ht()->stack[t & 2]);
	ps_freend((void *)&ht()->stack[(t & 2) + 1]);
}

void	ps_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ps_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

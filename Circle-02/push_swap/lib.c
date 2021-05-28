#include "push_swap.h"

void	*ft_memset(void *dest, int value, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		*((char *)dest + i) = value;
	return (dest);
}

t_bool	print_error(char *message)
{
	return (printf("%s\n", message) >= 0);
}

void 	freend(void **ptr)
{
	free(*ptr);
	*ptr = 0;
}

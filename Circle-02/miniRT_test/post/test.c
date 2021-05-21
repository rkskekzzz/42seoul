#include <stdio.h>
#include <stdlib.h>

int	fnc(void)
{
	printf("hello\n");
	return (1);
}

int	main(void)
{
	char	*str;

	if (!(str = malloc(2)))
		printf("wow\n");
	return (0);
}

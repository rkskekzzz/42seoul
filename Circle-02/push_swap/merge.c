#include "push_swap.h"

void merge()
{
	static int i;

	if (!i)
		i = 1;
	else
		i = i << 1;
	printf("%d", i);
}

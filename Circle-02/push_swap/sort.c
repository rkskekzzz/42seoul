#include "push_swap.h"

void quick_sort(int **list, int left, int right)
{
	int key;
	int i;
	int j;

	if (left >= right)
		return ;
	key = left;
	i = left + 1;
	j = right;
	while (i <= j)
	{
		while (i <= right && (*list)[i] <= (*list)[key])
			++i;
		while (j > left && (*list)[j] >= (*list)[key])
			--j;
		if (i > j)
			ps_swap(&((*list)[key]), &((*list)[j]));
		else
			ps_swap(&((*list)[i]), &((*list)[j]));
	}
	quick_sort(list, left, j - 1);
	quick_sort(list, j + 1, right);
}

int *init_arr(int argc, char **argv)
{
	int	*arr;
	int	idx;
	int	pv[2];

	arr = malloc(sizeof(int) * (argc - 1));
	idx = -1;
	while (++idx < argc - 1)
	{
		arr[idx] = ps_isnum_atoi(argv[idx + 1]);
	}
	quick_sort(&arr, 0, argc - 2);
	pv[0] = arr[(argc - 2) / 3];
	pv[1] = arr[(argc - 2) - ((argc - 1) / 3)];
	ps_freend((void *)&arr);
	return ((int [2]){pv[0], pv[1]});
}

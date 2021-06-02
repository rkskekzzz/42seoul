#include "push_swap.h"

void	init(int argc, char **argv)
{
	int idx;
	int *arr[2];
	int *pivot;

	init_stack(&(ht()->stack[ATAIL]), &(ht()->stack[AHEAD]));
	init_stack(&(ht()->stack[BTAIL]), &(ht()->stack[BHEAD]));
	ht()->size[a] = 0;
	ht()->size[b] = 0;
	pivot = init_arr(argc, argv);
	idx = -1;
	printf("%d, %d\n", pivot[0], pivot[1]);
	while (argv[++idx])
	{
		add_list(AHEAD, ps_isnum_atoi(argv[idx]));
	}
}

void	push_swap(int argc, char **argv)
{
	init(argc, argv);
	prt_list(ATAIL);
	del_list(ATAIL);
	prt_list(ATAIL);
	swp_list(AHEAD);
	cmd(sa);
	prt_list(ATAIL);
	merge();
	merge();
	merge();
	merge();
	if (srh_list(a, 3))
		printf("find!\n");
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argc, argv);
	else
		prt_error("Arguments Error!");
	return (0);
}

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
	idx = 0;
	while (argv[++idx])
		add_list(AHEAD, ps_isnum_atoi(argv[idx]));
	pivot = init_arr(AHEAD, ht()->size[a]);
	printf("%d, %d\n", pivot[0], pivot[1]);
}

void	push_swap(int argc, char **argv)
{
	init(argc, argv);
	// prt_list(ATAIL);
	// del_list(ATAIL);
	// prt_list(ATAIL);
	// swp_list(AHEAD);
	// cmd(sa);
	// prt_list(ATAIL);
	// if (srh_list(a, 3))
	// 	printf("find!\n");
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argc, argv);
	else
		prt_error("Arguments Error!");
	return (0);
}

#include "push_swap.h"

void	init(int argc, char **argv)
{
	init_stack(&(ht()->stack[ATAIL]), &(ht()->stack[AHEAD]));
	init_stack(&(ht()->stack[BTAIL]), &(ht()->stack[BHEAD]));
	ht()->size[a] = 0;
	ht()->size[b] = 0;
	while (*(++argv))
	{
		add_list(AHEAD, ps_isnum_atoi(*argv));
	}
}

void	push_swap(int argc, char **argv)
{
	init(argc, argv);
	prt_list(ATAIL);
	del_list(ATAIL);
	prt_list(ATAIL);
	swp_list(ATAIL);
	cmd(sa);
	prt_list(ATAIL);
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

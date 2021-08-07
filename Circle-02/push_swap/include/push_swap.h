#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "func.h"
# include "lib.h"

# define DEBUG 1

# define INTMAX 2147483647
# define BUFFER_SIZE 200000

# define FALSE		0
# define TRUE		1

# define A			0
# define B			1

# define HEAD		1
# define TAIL		0

# define SMALL		0
# define BIG		1

# define AHEAD		0
# define ATAIL		1
# define BHEAD		2
# define BTAIL		3
# define FUNCL		4
# define LIST_SIZE	5

// 확정
void				init_stack(t_list **head, t_list **tail);
int					add_list(int t, int val);
void				prt_list(int t);
int					swp_list(int t);
int					del_list(int t);
int					srh_list(int t, int find);

void a_to_b(int size);
void b_to_a(int size);

void under_3_a(int size);
void under_3_b(int size);

// int *find_pivot(int argc, char **argv);
int *find_pivot(int t, int size);
void quick_sort(int **list, int left, int right);
int partition(int **list, int left, int right);

// func

#endif

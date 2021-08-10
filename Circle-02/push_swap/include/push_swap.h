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
# define F			2

# define HEAD		1
# define TAIL		0

# define SMALL		0
# define BIG		1

# define AHEAD		0
# define ATAIL		1
# define BHEAD		2
# define BTAIL		3
# define FHEAD		4
# define FTAIL		5
# define LIST_SIZE	6

// 확정
void				init_stack(t_list **head, t_list **tail);
int					add_list(int t, int val);
void				prt_list(int t);
int					swp_list(int t);
int					del_list(int t);
int					srh_list(int t, int find);

void a_to_b(int size);
void b_to_a(int size);

void under_2_a(int size);
void under_2_b(int size);

void	size_3_a(void);
void	size_5_a(void);

// int *find_pivot(int argc, char **argv);
int *find_pivot(int t, int size);
void quick_sort(int **list, int left, int right);
int partition(int **list, int left, int right);

// func

#endif

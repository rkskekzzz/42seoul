#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "func.h"
# include "library.h"

# define INTMAX 		2147483647
# define BUFFER_SIZE 	200000

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

int		a_to_b(int size);
int		b_to_a(int size);

void	under_2_a(int size);
void	under_2_b(int size);

void	size_3_a(void);
void	size_5_a(void);

int		*find_pivot(int t, int size);
int		find_border(void);
void	quick_sort(int **list, int left, int right);
int		partition(int **list, int left, int right);
t_bool	already_sort(int type, int size);
int		ps_strncmp(const char *s1, const char *s2, size_t n);

#endif

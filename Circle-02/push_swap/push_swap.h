#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>

# define INTMAX 2147483647
# define ERROR 0
# define OK 1

# define AB 0
# define HT 1

# define AHEAD 0
# define ATAIL 1
# define BHEAD 2
# define BTAIL 3

typedef int		t_bool;

typedef enum	e_type
{
	HEAD = 0,
	TAIL
}				t_type;

typedef enum	e_stack
{
	a = 0,
	b
}				t_stack;

typedef enum	e_func
{
	sa = 0,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}				t_func;

typedef struct	s_list
{
	int				val;
	struct s_list	*link[2]; // 0 : left,  1 : right
}				t_list;

typedef struct		s_ht
{
	int				size[2];
	struct s_list	*stack[4];
}					t_ht;
// 확정
void				init_stack(t_list **head, t_list **tail);
int					add_list(int t, int val);
void				prt_list(int t);
int					swp_list(int t);
int					del_list(int t);
int					srh_list(int t, int find);
//lib
t_bool				prt_error(char *message);
void 				ps_freend(void **ptr);
int					ps_isnum_atoi(char *s);
void				*ps_memset(void *dest, int value, size_t size);
void				ps_swap(int *a, int *b);
t_list				*new_list(int val);
void				free_list(int t);

int 				cmd(t_func f);

t_ht				*ht(void);

int *init_arr(int argc, char **argv);
void quick_sort(int **list, int left, int right);
int partition(int **list, int left, int right);


void	merge();
#endif

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdlib.h>
# include <stdio.h>

typedef int		t_bool;

typedef struct s_list
{
	int				val;
	struct s_list	*link[2];
}				t_list;

typedef enum e_case
{
	case_123 = 0,
	case_132,
	case_213,
	case_231,
	case_312,
	case_321
}			t_case;

typedef enum e_func
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_func;

// list1.c
void				init_stack(t_list **head, t_list **tail);
int					add_list(int t, int val);
int					del_list(int t);
int					swp_list(int t);
int					srh_list(int t, int find);

// list2.c
void				prt_list(int t);
t_list				*new_list(int val);
void				free_list(int t);

// library.c
void				*ps_memset(void *dest, int value, size_t size);
int					ps_isnum_atoi(char *s);
void				ps_swap(int *a, int *b);
int					ps_strlen(char *str);
char				*ps_strchr(const char *s, int c);

// split.c
char				**ps_split(char *s, char *delim);
char				**ps_free_split(char **s);

// utils.c
t_bool				prt_error(char *message);
t_bool				prt_func(int val);
void				ps_free(void **ptr);
char				*join_argv(char **argv);

#endif

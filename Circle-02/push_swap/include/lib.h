#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <stdio.h>

/*
** 0 left 1 right
*/
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

int					ps_isnum_atoi(char *s);
void				ps_swap(int *a, int *b);
void				*ps_memset(void *dest, int value, size_t size);
t_bool				prt_error(char *message);

t_list				*new_list(int val);
void				free_list(int t);

void				ps_freend(void **ptr);

int					ps_strlen(char *str);
char				**ps_split(char *s, char *delim);
char				**ps_free_split(char **s);

#endif

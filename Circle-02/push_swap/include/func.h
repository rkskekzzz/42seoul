#ifndef FUNC_H
# define FUNC_H

typedef int		t_bool;

typedef struct s_ht
{
	int				size[3];
	struct s_list	*stack[6];
}					t_ht;

t_ht	*ht(void);
t_bool	sa(void);
t_bool	sb(void);
t_bool	ss(void);
t_bool	pa(void);
t_bool	pb(void);
t_bool	ra(void);
t_bool	rb(void);
t_bool	rr(void);
t_bool	rra(void);
t_bool	rrb(void);
t_bool	rrr(void);

void	start_sort(char **split);
int		func(char *str);

#endif

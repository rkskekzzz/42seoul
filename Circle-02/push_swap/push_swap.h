#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>

# define ERROR 0
# define OK 1

typedef int		t_bool;
typedef enum	e_type
{
	HEAD = 0,
	TAIL
}				t_type;

typedef struct	s_list
{
	int				val;
	struct s_list	*link[2]; // 0 : left,  1 : right
}				t_list;

typedef struct		s_ht
{
	int				a_size;
	int				b_size;
	struct s_list	*a_head;
	struct s_list	*a_tail;
	struct s_list	*b_head;
	struct s_list	*b_tail;
}					t_ht;
// 확정
int					init_stack(t_list **head, t_list **tail);
int					add_list(t_list *pos, int val);
void				print_list(t_list *tail, t_list *head);
void				swap_list(t_list *list);
t_bool				print_error(char *message);
//
void				*ft_memset(void *dest, int value, size_t size);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int val);

#endif

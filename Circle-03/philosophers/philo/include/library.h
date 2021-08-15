#ifndef LIBRARY_H
# define LIBRARY_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef int	t_bool;

# define TRUE	1
# define FALSE	0

int			ph_atoi(char *str);
t_bool		ph_isnum(char *str);
t_bool		ph_exit(char *s);

#endif

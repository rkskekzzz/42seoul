#ifndef LIBRARY_H
# define LIBRARY_H

typedef int	t_bool;

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE	1
# define FALSE	0

int			ph_atoi(char *str);
t_bool		ph_isnum(char *str);

#endif

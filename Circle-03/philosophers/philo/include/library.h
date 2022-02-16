#ifndef LIBRARY_H
# define LIBRARY_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>

int		ph_atoi(char *str);
int		ph_isnum(char *str);
int		timestamp(void);
char	*message(int type);

#endif

#ifndef PARSE_H
# define PARSE_H

# include "main.h"

int	parse_r(char **line, t_box *box);
int	parse_a(char **line, t_box *box);
int	parse_c(char **line, t_box *box);
int	parse_l(char **line, t_box *box);
int	parse_pl(char **line, t_box *box);
int	parse_sp(char **line, t_box *box);
int	parse_sq(char **line, t_box *box);
int	parse_cy(char **line, t_box *box);
int	parse_tr(char **line, t_box *box);

#endif

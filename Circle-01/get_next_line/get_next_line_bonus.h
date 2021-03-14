/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:59:59 by suhshin           #+#    #+#             */
/*   Updated: 2021/02/12 21:59:44 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int		gnl_return_check(ssize_t read_size, char **backup, char **line);
int		get_next_line(int fd, char **line);
char	*gnl_strappend(char *str1, char *str2);
int		gnl_check_new_line(char *line);
int		gnl_strslice(char **backup, ssize_t i, char **line);
char	*gnl_strdup(char *src);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	gnl_strlen(char *str);
void	gnl_free(char **str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:02:12 by suhshin           #+#    #+#             */
/*   Updated: 2021/03/01 16:46:03 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*backup[OPEN_MAX];
	ssize_t		read_size;
	ssize_t		i;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1 || !line ||
		!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup[fd] = gnl_strappend(backup[fd], buf);
		if ((i = gnl_check_new_line(backup[fd])) >= 0)
		{
			gnl_free(&buf);
			return (gnl_strslice(&backup[fd], i, line));
		}
	}
	gnl_free(&buf);
	return (gnl_return_check(read_size, &backup[fd], line));
}

int		gnl_return_check(ssize_t read_size, char **backup, char **line)
{
	ssize_t	i;

	if (read_size == -1)
		return (-1);
	if (!*backup)
	{
		gnl_free(backup);
		*line = gnl_strdup("");
		return (0);
	}
	if ((i = gnl_check_new_line(*backup)) >= 0)
		return (gnl_strslice(backup, i, line));
	*line = gnl_strdup(*backup);
	gnl_free(backup);
	return (0);
}

int		gnl_strslice(char **backup, ssize_t i, char **line)
{
	char	*tmp_line;

	(*backup)[i] = '\0';
	tmp_line = gnl_strdup(*backup);
	*line = tmp_line;
	tmp_line = gnl_strdup(*backup + i + 1);
	gnl_free(backup);
	*backup = tmp_line;
	return (1);
}

char	*gnl_strappend(char *str1, char *str2)
{
	char	*dest;
	size_t	s1;
	size_t	s2;

	if (!str1 && !str2)
		return (NULL);
	if (!str2 || !str1)
		return (!str2 ? str1 : gnl_strdup(str2));
	s1 = gnl_strlen(str1);
	s2 = gnl_strlen(str2);
	if (!(dest = (char *)malloc(s1 + s2 + 1)))
		return (NULL);
	gnl_strlcpy(dest, str1, s1 + 1);
	gnl_strlcpy(dest + s1, str2, s2 + 1);
	free(str1);
	return (dest);
}

int		gnl_check_new_line(char *backup)
{
	size_t	len;
	size_t	i;

	i = -1;
	if (!backup)
		return (-1);
	len = gnl_strlen(backup);
	while (++i < len)
		if (backup[i] == '\n')
			return (i);
	return (-1);
}

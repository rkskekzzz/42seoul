#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, s++, 1);
}

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char *str;

	str = NULL;
	if (argc < 2)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Error, cannot open file\n");
			return (1);
		}
		ft_putstr("File:\n\n");
		while ((ret = get_next_line(fd, &str)) != 0)
		{
			//printf("[%s]\n", str);
			free(str);
			printf("\nret : %d\n",ret);
		}
		printf("[%s]\n", str);
		//free(str);
		ft_putstr("\n\n:End of File\n");
		if (ret == -1)
		{
			ft_putstr("Error, cannot close file\n");
			return (1);
		}
	}
	return (0);
}

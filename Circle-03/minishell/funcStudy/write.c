#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd;

    if ((fd = open("stdout", O_WRONLY | O_CREAT)) == -1)
        printf("wow\n");
    write(fd, "hello", 5);
}

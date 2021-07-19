#include <stdio.h>
#include <unistd.h>

int main(void)
{
	unsigned int useconds;

	useconds = 1000000;
	usleep(useconds);
	printf("done!\n");
	return (0);
}

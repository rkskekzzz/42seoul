#include "builtin.h"

int functions();

int main(void)
{
	echo(NULL, "hello");
	pwd();
	cd(NULL, "/Users/suhshin/Desktop/42seoul/minishell");
	pwd();
	return (0);
}

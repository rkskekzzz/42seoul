#include "library.h"

char	*message(int type)
{
	if (type == 0)
		return ("has taken a fork");
	else if (type == 1)
		return ("is eating");
	else if (type == 2)
		return ("is sleeping");
	else if (type == 3)
		return ("is thinking");
	else if (type == 4)
		return ("is full");	
	else
		return ("died");
}

#include "library.h"
#include "type.h"

long long	timestamp(void)
{
	struct timeval	tv;

	if (!gettimeofday(&tv, NULL))
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (FALSE);
}

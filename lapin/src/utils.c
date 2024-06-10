#include "../include/lapin.h"

size_t	size_of(Lapin **list)
{
	size_t	n;

	n = 0;
	while (list[n])
		n++;
	return (n);
}
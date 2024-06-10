#include "../include/genetic.h"

void	aff(t_equa *list, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		printf("%d -> %d + %d = %d\n", i, list[i].elem1, list[i].elem2, list[i].elem1 + list[i].elem2);
}
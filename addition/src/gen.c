#include "../include/genetic.h"

void	trier(t_equa **gen, int n, int target)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (ft_abs(gen[0][i].elem1 + gen[0][i].elem2 - target) > ft_abs(gen[0][j].elem1 + gen[0][j].elem2 - target) && i < j)
			{
				tmp = gen[0][i].elem1;
				gen[0][i].elem1 = gen[0][j].elem1;
				gen[0][j].elem1 = tmp;
				tmp = gen[0][i].elem2;
				gen[0][i].elem2 = gen[0][j].elem2;
				gen[0][j].elem2 = tmp;
			}
			else if (ft_abs(gen[0][i].elem1 + gen[0][i].elem2 - target) < ft_abs(gen[0][j].elem1 + gen[0][j].elem2 - target) && i > j)
			{
				tmp = gen[0][i].elem1;
				gen[0][i].elem1 = gen[0][j].elem1;
				gen[0][j].elem1 = tmp;
				tmp = gen[0][i].elem2;
				gen[0][i].elem2 = gen[0][j].elem2;
				gen[0][j].elem2 = tmp;
			}
			j++;
		}
		i++;
	}
}

void	reproduction(t_equa **gen, int n)
{
	int	child;
	int	parents;

	child = n / 2;
	parents = 0;
	while (child < n)
	{
		if (child % 2)
		{
			gen[0][child].elem1 = gen[0][parents].elem1;
			gen[0][child].elem2 = rand() % 1000;
		}
		else
		{
			gen[0][child].elem2 = gen[0][parents].elem2;
			gen[0][child].elem1 = rand() % 1000;
		}
		child++;
		parents++;
	}	
}
#include "../include/genetic.h"

t_equa	*first_gen(int n)
{
	t_equa	*list;
	int	i;

	srand(time(NULL));
	list = (t_equa *)malloc(sizeof(t_equa) * n);
	if (!list)
		return (NULL);
	i = 0;
	while (i < n)
	{
		list[i].elem1 = rand() % 1000;
		list[i].elem2 = rand() % 1000;
		i++;
	}
	return (list);
}

int	main(int argc, char **argv)
{
	t_equa	*gen;
	int	n;
	int	i;
	int	nbr_gen;

	if (argc < 3 || argc > 4)
		return (1);
	n = atoi(argv[1]);
	gen = first_gen(n);
	if (!gen)
		return (1);
	i = 0;
	nbr_gen = 10;
	if (argc == 4)
		nbr_gen = atoi(argv[3]);
	while (i < nbr_gen)
	{
		aff(gen, n);
		trier(&gen, n, atoi(argv[2]));
		printf("\nGeneration %d:\n", i);
		aff(gen, n);
		printf("\nReproduction et mutation : \n");
		reproduction(&gen, n);
		aff(gen, n);
		printf("\nNEXT GEN\n");
		i++;
	}
	return (0);
}

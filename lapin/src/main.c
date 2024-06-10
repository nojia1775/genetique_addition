#include "../include/lapin.h"

LIST	*first_gen(int n, int carottes)
{
	LIST	*first;
	int	i;

	if (n < 0)
		return (NULL);
	srand(time(NULL));
	first = (LIST *)malloc(sizeof(LIST));
	if (!first)
		return (NULL);
	first->list = (Lapin *)malloc(sizeof(Lapin) * n);
	if (!first->list)
		return (free(first), NULL);
	i = 0;
	while (i < n)
	{
		first->list[i].taille = rand() % 10;
		first->list[i].vitesse = rand() % 10;
		first->list[i].vue = rand() % 10;
		if (first->list[i].taille > 6)
			first->list[i].vitesse -= first[i].taille - 5;
		if (first->list[i].vitesse < 0)
			first->list[i].vitesse = 0;
		if (first->list[i].vitesse > 9)
			first->list[i].vitesse = 9;
		i++;
	}
	first->carottes = carottes;
	first->taille = n;
	return (first);
}

int	main(int argc, char **argv)
{
	LIST	*first_list;

	if (argc != 3)
		return (1);
	first_list = first_gen(atoi(argv[1]), atoi(argv[2]));
	if (!first_list)
		return (2);
	aff(first_list);
	chasse(first_list, first_list->list);
	printf("\n");
	aff(first_list);
	first_list = next_gen(first_list, atoi(argv[2]));
	if (!first_list)
		return (4);
	printf("\n");
	aff(first_list);
	free(first_list->list);
	free(first_list);
	return (0);
}
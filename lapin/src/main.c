#include "../include/lapin.h"

t_list	*first_gen(int n)
{
	t_list	*first;
	int	i;

	if (n < 0)
		return (NULL);
	srand(time(NULL));
	first = (t_list *)malloc(sizeof(t_list));
	if (!first)
		return (NULL);
	first->list = (Lapin *)malloc(sizeof(Lapin) * n);
	if (!first->list)
		return (NULL);
	i = 0;
	while (i < n)
	{
		first->list[i].sexe = rand() % 2;
		first->list[i].taille = rand() % 10;
		first->list[i].vitesse = rand() % 10;
		first->list[i].vue = rand() % 10;
		if (first->list[i].taille > 6)
			first->list[i].vitesse -= first[i].taille - 5;
		i++;
	}
	first->taille = n;
	return (first);
}

int	main(int argc, char **argv)
{
	t_list	*first_list;

	if (argc != 2)
		return (1);
	first_list = first_gen(atoi(argv[1]));
	if (!first_list)
		return (2);
	aff(first_list);
	chasse(first_list);
	return (0);
}
#include "../include/lapin.h"

void	aff(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->taille)
	{
		printf("%d Lapin :\tsexe = %d\tvitesse = %d\ttaille = %d\tvue = %d\n", i, list->list[i].sexe, list->list[i].vitesse, list->list[i].taille, list->list[i].vue);
		i++;
	}
}
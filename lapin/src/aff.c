#include "../include/lapin.h"

void	aff(LIST *list)
{
	int	i;

	i = 0;
	while (i < list->taille)
	{
		printf("%d Lapin :\tvitesse = %d\ttaille = %d\tvue = %d\tcarottes = %d\tparent = %d\n", i, list->list[i].vitesse, list->list[i].taille, list->list[i].vue, list->list[i].carrotes_manges, list->list[i].parent);
		i++;
	}
}
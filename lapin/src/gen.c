#include "../include/lapin.h"

LIST	*next_gen(LIST *list, int carottes)
{
	int	i;
	int	nbr_next;
	LIST	*new;

	i = 0;
	nbr_next = 0;
	while (i < list->taille)
	{
		if (list->list[i].carrotes_manges < 2)
			list->list[i].mort = 1;
		else if (list->list[i].carrotes_manges > 2)
			list->list[i].parent = 1;
		i++;
	}
	i = 0;
	while (i < list->taille)
		if (list->list[i++].mort == 0)
			nbr_next++;
	new = (LIST *)malloc(sizeof(LIST));
	if (!new)
		return (NULL);
	new->list = (Lapin *)malloc(sizeof(Lapin) * nbr_next);
	if (!new->list)
		return (free(new), free(list), NULL);
	i = 0;
	int k = 0;
	while (i < list->taille)
	{
		if (list->list[i].mort == 0)
			new->list[k++] = list->list[i];
		i++;
	}
	free(list->list);
	free(list);
	new->taille = nbr_next;
	new->carottes = carottes;
	return (new);
}

void	chasse(LIST *list, Lapin *lapins)
{
	int	i;
	int	vit;
	int	pos;

	vit = 9;
	pos = 0;
	while (vit >= 0)
	{
		i = 0;
		while (i < list->taille)
		{
			if (list->list[i].vitesse == vit)
				list->list[i].position = pos++;
			i++;
		}
		vit--;
	}
	pos = 0;
	while (pos < 10)
	{
		i = 0;
		while (i < list->taille)
		{
			if (lapins[i].position == pos)
			{
				if (list->carottes < 1)
					break;
				if (lapins[i].vue >= 0 && lapins[i].vue < 3)
				{
					for (int k = 0; k < 3; k++)
						lapins[i].carrotes_manges += rand() % 4;
				}
				else if (lapins[i].vue >= 3 && lapins[i].vue < 5)
				{
					for (int k = 0; k < 4; k++)
						lapins[i].carrotes_manges += rand() % 4;
				}
				else if (lapins[i].vue >= 5 && lapins[i].vue < 8)
				{
					for (int k = 0; k < 5; k++)
						lapins[i].carrotes_manges += rand() % 4;
				}
				else if (lapins[i].vue >= 8 && lapins[i].vue < 9)
				{
					for (int k = 0; k < 9; k++)
						lapins[i].carrotes_manges += rand() % 4;
				}
				lapins[i].carrotes_manges /= 3;
				if (lapins[i].carrotes_manges > list->carottes)
					lapins[i].carrotes_manges = list->carottes;
				list->carottes -= lapins[i].carrotes_manges;
				break;
			}
			i++;
		}
		pos++;
	}
}
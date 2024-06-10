#include "../include/lapin.h"

void	chasse(t_list *list)
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
			if (list->list[i].position == pos)
			{
				if (list->carottes < 1)
					break;
				if (list->list[i].vue >= 0 && list->list[i].vue < 3)
				{
					for (int k = 0; k < 3; k++)
						list->list[i].carrotes_manges += rand() % 4;
				}
				else if (list->list[i].vue >= 3 && list->list[i].vue < 5)
				{
					for (int k = 0; k < 4; k++)
						list->list[i].carrotes_manges += rand() % 4;
				}
				else if (list->list[i].vue >= 5 && list->list[i].vue < 8)
				{
					for (int k = 0; k < 5; k++)
						list->list[i].carrotes_manges += rand() % 4;
				}
				else if (list->list[i].vue >= 8 && list->list[i].vue < 9)
				{
					for (int k = 0; k < 9; k++)
						list->list[i].carrotes_manges += rand() % 4;
				}
				list->list[i].carrotes_manges = list->list[i].carrotes_manges / 3;
			}
			if (list->list[i].carrotes_manges > list->carottes)
				list->list[i].carrotes_manges = list->carottes;
			list->carottes -= list->list[i].carrotes_manges;
			i++;
		}
		pos++;
	}
}
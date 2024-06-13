#include "../include/header.hpp"

static void	order(std::list<Lapin>& lapins)
{
	Lapin tmp;
	std::list<Lapin>::iterator i, j;
	int	index_i, index_j = 0;

	i = lapins.begin();
	while (i != lapins.end())
	{
		j = lapins.begin();
		while (j != lapins.end())
		{
			if (i->get_vitesse() < j->get_vitesse() && index_i < index_j)
			{
				tmp = *i;
				i->set_index(j->get_index());
				i->set_taille(j->get_taille());
				i->set_vitesse(j->get_vitesse());
				i->set_vue(j->get_vue());
				j->set_index(tmp.get_index());
				j->set_taille(tmp.get_taille());
				j->set_vitesse(tmp.get_vitesse());
				j->set_vue(tmp.get_vue());
			}
			index_j++;
		}
		index_i++;
	}
}

void	chasse(std::list<Lapin>& lapins)
{
	order(lapins);
}
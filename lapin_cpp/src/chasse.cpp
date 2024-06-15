#include "../include/header.hpp"

static void	order(std::list<Lapin>& lapins)
{
	Lapin tmp;
	std::list<Lapin>::iterator i, j;

	i = lapins.begin();
	j = lapins.begin();
	j++;
	while (j != lapins.end())
	{
		if (i->get_vitesse() < j->get_vitesse())
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
			i = lapins.begin();
			j = lapins.begin();
			j++;
		}
		else
		{
			i++;
			j++;
		}
	}
}

static void	vol(int index, std::list<Lapin>& lapins)
{
	int vol = std::rand() % 4;
	std::list<Lapin>::iterator it = lapins.begin();
	static int i = 0;
	printf("vol %d\n", i++);
	aff_lapins(lapins);
	std::list<Lapin>::iterator voleur = lapins.begin();
	while (voleur != lapins.end())
	{
		if (voleur->get_index() == index)
			break;
		voleur++;
	}
	while (it != lapins.end())
	{
		if (voleur->get_taille() - it->get_taille() > 2)
		{
			printf("ok %d vol %d a %d\n", voleur->get_index(), vol, it->get_index());
			if (vol > it->carottes_manges)
				vol = it->carottes_manges;
			printf("--- %d\n", vol);
			voleur->carottes_manges = vol;
			it->carottes_manges -= vol;
			return ;
		}
		it++;
	}
}

static void	manger(std::list<Lapin>& lapins, int ressources)
{
	std::list<Lapin>::iterator it = lapins.begin();
	while (it != lapins.end())
	{
		if (ressources < 1)
			vol(it->get_index(), lapins);
		if (it->get_vue() < 3)
		{
			for (int i = 0; i < 3; i++)
				it->carottes_manges += std::rand() % 4;
		}
		else if (it->get_vue() < 5)
		{
			for (int i = 0; i < 4; i++)
				it->carottes_manges += std::rand() % 4;
		}
		else if (it->get_vue() < 8)
		{
			for (int i = 0; i < 5; i++)
				it->carottes_manges += std::rand() % 4;
		}
		else if (it->get_vue() < 10)
		{
			for (int i = 0; i < 9; i++)
				it->carottes_manges += std::rand() % 4;
		}
		it->carottes_manges /= 3;
		if (it->carottes_manges > ressources)
		{
			it->carottes_manges = ressources;
			ressources = 0;
		}
		else
			ressources -= it->carottes_manges;
		it++;
	}
}

void	chasse(std::list<Lapin>& lapins, int ressources)
{
	order(lapins);
	manger(lapins, ressources);
}
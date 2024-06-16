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

static int	vol(Lapin &voleur, std::list<Lapin>& lapins)
{
	int vol = std::rand() % 4;
	std::list<Lapin>::iterator it = lapins.begin();
	while (it != lapins.end())
	{
		if (voleur.get_taille() - it->get_taille() > 2 && it->get_reserve())
		{
			if (vol > it->get_reserve())
				vol = it->get_reserve();
			if (COLOR)
				printf("%sLapin %d vole %d carottes à Lapin %d%s\n", HMAG, voleur.get_index(), vol, it->get_index(), RESET);
			else
				printf("Lapin %d vole %d carottes à Lapin %d\n", voleur.get_index(), vol, it->get_index());
			it->set_reserve(it->get_reserve() - vol);
			return (vol);
		}
		it++;
	}
	return (0);
}

static void	manger(std::list<Lapin>& lapins, int& ressources)
{
	std::list<Lapin>::iterator it = lapins.begin();
	int	carottes = 0;
	while (it != lapins.end())
	{
		if (ressources < 1)
		{
			it->set_reserve(vol(*it, lapins));
		}
		else
		{
			if (it->get_vue() < 3)
			{
				for (int i = 0; i < 3; i++)
					carottes += std::rand() % 4;
			}
			else if (it->get_vue() < 5)
			{
				for (int i = 0; i < 4; i++)
					carottes += std::rand() % 4;
			}
			else if (it->get_vue() < 8)
			{
				for (int i = 0; i < 5; i++)
					carottes += std::rand() % 4;
			}
			else if (it->get_vue() < 10)
			{
				for (int i = 0; i < 9; i++)
					carottes += std::rand() % 4;
			}
			carottes /= 3;
			if (carottes > ressources)
			{
				it->set_reserve(ressources);
				ressources = 0;
			}
			else
			{
				ressources -= carottes;
				it->set_reserve(it->get_reserve() + carottes);
			}
		}
		it++;
	}
}

void	vie(std::list<Lapin>& lapins, int& ressources, int survivre, int reproduction)
{
	order(lapins);
	manger(lapins, ressources);
	printf("\n");
	aff_lapins(lapins, ressources, 0, 0);
	destin(lapins, survivre, reproduction);
}
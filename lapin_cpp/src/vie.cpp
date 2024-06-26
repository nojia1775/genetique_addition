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
			i->set_reserve(j->get_reserve());
			j->set_index(tmp.get_index());
			j->set_taille(tmp.get_taille());
			j->set_vitesse(tmp.get_vitesse());
			j->set_vue(tmp.get_vue());
			j->set_reserve(tmp.get_reserve());
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
	int	i = 0;
	int random = voleur.get_index();
	std::list<Lapin>::iterator it;
	while (i++ < 10)
	{
		it = lapins.begin();
		while (random == voleur.get_index())
			random = std::rand() % lapins.size();
		int n = 0;
		while (n++ < random)
			it++;
		if (it->get_reserve())
		{
			int chance = std::rand() % 100;
			if (chance < 50 + (voleur.get_taille() - it->get_taille()) * 5)
			{
				int vol = std::rand() % (it->get_reserve() + 1);
				if (COLOR)
					printf("%sLapin %d vole %d carottes a Lapin %d%s\n", HMAG, voleur.get_index(), vol, it->get_index(), RESET);
				else
					printf("Lapin %d vole %d carottes a Lapin %d\n", voleur.get_index(), vol, it->get_index());
				it->set_reserve(it->get_reserve() - vol);
				return (vol);
			}
		}
	}
	return (0);
}

static void	manger(std::list<Lapin>& lapins, int& ressources, int survivre)
{
	std::list<Lapin>::iterator it = lapins.begin();
	int	carottes = 0;
	while (it != lapins.end())
	{
		if (it->get_reserve() < survivre && !ressources)
		{
			it->set_reserve(it->get_reserve() + vol(*it, lapins));
		}
		else
		{
			if (it->get_vue() < 3)
			{
				for (int i = 0; i < survivre / 2; i++)
					carottes += std::rand() % survivre;
			}
			else if (it->get_vue() < 5)
			{
				for (int i = 0; i < (survivre / 2) + survivre / 4; i++)
					carottes += std::rand() % survivre;
			}
			else if (it->get_vue() < 8)
			{
				for (int i = 0; i < survivre; i++)
					carottes += std::rand() % survivre;
			}
			else if (it->get_vue() < survivre * 2)
			{
				for (int i = 0; i < 9; i++)
					carottes += std::rand() % survivre;
			}
			carottes /= survivre / 3;
			if (carottes > ressources)
			{
				it->set_reserve(it->get_reserve() + ressources);
				if (COLOR)
					printf("%sLapin %d a pris %d carottes%s\n", HBLUE, it->get_index(), ressources, RESET);
				else
					printf("Lapin %d a pris %d carottes\n", it->get_index(), ressources);
				ressources = 0;
			}
			else
			{
				ressources -= carottes;
				if (COLOR)
					printf("%sLapin %d a pris %d carottes%s\n", HBLUE, it->get_index(), carottes, RESET);
				else
					printf("Lapin %d a pris %d carottes\n", it->get_index(), carottes);
				it->set_reserve(it->get_reserve() + carottes);
			}
		}
		it++;
	}
	printf("\n");
}

void	vie(std::list<Lapin>& lapins, int& ressources, int survivre, int reproduction)
{
	order(lapins);
	manger(lapins, ressources, survivre);
	printf("\n");
	aff_lapins(lapins, ressources, 0, 0);
	destin(lapins, survivre, reproduction);
}
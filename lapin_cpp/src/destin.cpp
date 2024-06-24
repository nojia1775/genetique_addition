#include "../include/header.hpp"

static void	mort(std::list<Lapin>& lapins, int survivre)
{
	std::list<Lapin>::iterator it = lapins.begin();
	while (it != lapins.end())
	{
		if (it->get_reserve() < survivre)
		{
			if (COLOR)
				printf("%sLapin %d est mort de faim%s\n", HRED, it->get_index(), RESET);
			else
				printf("Lapin %d est mort de faim\n", it->get_index());
			it = lapins.erase(it);
		}
		else
			it++;	
	}
	printf("\n");
}

static void	mutation(Lapin& enfant, int n)
{
	if (n == 2)
		enfant.set_vitesse(std::rand() % 10);
	else if (n == 3)
		enfant.set_taille(std::rand() % 10);
	else if (n == 1)
		enfant.set_vue(std::rand() % 10);
}

static void	random_attr(Lapin& enfant, Lapin parent, int random)
{
	if (random == 0)
		enfant.set_taille(parent.get_taille());
	else if (random == 1)
		enfant.set_vitesse(parent.get_vitesse());
	else if (random == 2)
		enfant.set_vue(parent.get_vue());
}

static void	enfant(std::list<Lapin>& lapins, int reproduction)
{
	int parent1, parent2;
	std::list<Lapin>::iterator b = lapins.begin();
	std::list<Lapin>::iterator a = lapins.begin();
	std::list<Lapin>::iterator enfant;
	while (a != lapins.end() && b != lapins.end())
	{
		while ((a->get_reserve() < reproduction || a == b || a->parent) && a != lapins.end())
			a++;
		while ((b->get_reserve() < reproduction || a == b || b->parent) && b != lapins.end())
			b++;
		if (a == lapins.end() || b == lapins.end())
			return ((void)printf("\n\n"));
		a->parent = 1;
		b->parent = 1;
		lapins.push_back(Lapin());
		enfant = lapins.end();
		enfant--;
		if (COLOR)
			printf("%sLapin %d est né de Lapin %d et Lapin %d%s\n", HGREEN, enfant->get_index(), a->get_index(), b->get_index(), RESET);
		else
			printf("Lapin %d est né de Lapin %d et Lapin %d\n", enfant->get_index(), a->get_index(), b->get_index());
		parent1 = std::rand() % 3;
		parent2 = std::rand() % 3;
		while (parent2 == parent1)
			parent2 = std::rand() % 3;
		random_attr(*enfant, *a, parent1);
		random_attr(*enfant, *b, parent2);
		mutation(*enfant, parent1 + parent2);
	}
	printf("\n\n");
}

void	destin(std::list<Lapin>& lapins, int survivre, int reproduction)
{
	printf("\n");
	mort(lapins, survivre);
	enfant(lapins, reproduction);
	famine(lapins, survivre, reproduction);
	sterelisation(lapins);
}
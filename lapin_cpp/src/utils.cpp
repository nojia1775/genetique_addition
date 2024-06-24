#include "../include/header.hpp"

void	aff_lapins(std::list<Lapin> lapins, int ressources, int flag, int ajout)
{
	static int gen = 0;
	std::list<Lapin>::iterator it = lapins.begin();
	it = lapins.begin();
	if (flag)
	{
		printf("GENERATION : %d\n", gen / 2);
		if (gen == 0)
			(void)ajout;
		else
			printf("AJOUT : %d\n", ajout);
	}
	else
		printf("APRES MANGE : \n");
	printf("CAROTTES : %d\n", ressources);
	gen++;
	printf("POPULATION : %ld\n", lapins.size());
	while (it != lapins.end())
	{
		it->aff();
		it++;
	}
	std::cout << std::endl;
}

void	help(void)
{
	printf("Le programme se lance comme suit :\n./lapin <nombre de lapins> <nombres de carottes> <nbr carottes survie> <nbr carottes reproduction>  <nbr apport carottes> <nbr gen>\n");
}

void	sterelisation(std::list<Lapin>& lapins)
{
	std::list<Lapin>::iterator it = lapins.begin();
	while (it != lapins.end())
	{
		if (it->parent == 1)
			it->parent = 0;
		it++;
	}
}

void	famine(std::list<Lapin>& lapins, int survivre, int reproduction)
{
	std::list<Lapin>::iterator it = lapins.begin();
	while (it != lapins.end())
	{
		if (it->get_reserve() == 0)
			;
		else if (it->parent)
			it->set_reserve(it->get_reserve() - reproduction);
		else
			it->set_reserve(it->get_reserve() - survivre);
		it++;
	}
}
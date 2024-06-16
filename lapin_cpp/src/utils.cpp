#include "../include/header.hpp"

void	aff_lapins(std::list<Lapin> lapins, int ressources, int flag)
{
	static int gen = 0;
	int pop;
	std::list<Lapin>::iterator it = lapins.begin();
	while (it != lapins.end())
	{
		if (!it->mort)
			pop++;
		it++;
	}
	it = lapins.begin();
	if (flag)
		printf("GENERATION : %d\n", gen / 2);
	else
		printf("APRES MANGE : \n");
	printf("CAROTTES : %d\n", ressources);
	gen++;
	printf("POPULATION : %d\n", pop);
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

void	famine(std::list<Lapin>& lapins)
{
	std::list<Lapin>::iterator it = lapins.begin();
	while (it != lapins.end())
	{
		it->carottes_manges = 0;
		it++;
	}
}
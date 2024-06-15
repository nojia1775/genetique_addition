#include "../include/header.hpp"

void	aff_lapins(std::list<Lapin> lapins)
{
	int pop;
	std::list<Lapin>::iterator it = lapins.begin();
	while (it != lapins.end())
	{
		if (!it->mort)
			pop++;
		it++;
	}
	it = lapins.begin();
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
	printf("Le programme se lance comme suit :\n./lapin <nombre de lapins> <nombres de carottes> <nbr carottes survie> <nbr carottes reproduction>\n");
}
#include "../include/header.hpp"

void	aff_lapins(std::list<Lapin> lapins)
{
	std::list<Lapin>::iterator it = lapins.begin();
	while (it != lapins.end())
	{
		it->aff();
		it++;
	}
	std::cout << std::endl;
}

void	help(void)
{
	printf("Le programme se lance comme suit :\n./lapin <nombre de lapins> <nombres de carottes>\n");
}
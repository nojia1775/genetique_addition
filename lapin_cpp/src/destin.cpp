#include "../include/header.hpp"

void	destin(std::list<Lapin>& lapins, int survivre, int reproduction)
{
	std::list<Lapin>::iterator it = lapins.begin();
	while (it != lapins.end())
	{
		if (it->carottes_manges < survivre)
			it->mort = 1;
		else if (it->carottes_manges >= reproduction)
			it->parent = 1;
		it++;
	}
}
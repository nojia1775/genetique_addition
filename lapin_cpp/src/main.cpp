#include "../include/header.hpp"

int	main(int argc, char **argv)
{
	std::list<Lapin>	lapins;
	int			i;
	int			ressources;
	int			ajout;
	std::srand(std::time(0));
	if (argc < 2 || argc > 7)
		return (1);
	if (argc == 2 && !strcmp(argv[1], "-h"))
		return (help(), 0);
	if (argc != 7)
		return (1);
	i = 0;
	while (i++ < std::atoi(argv[1]))
		lapins.push_back(Lapin());
	i = 0;
	ressources = std::atoi(argv[2]);
	while (i++ < std::atoi(argv[6]) && !lapins.empty())
	{
		aff_lapins(lapins, ressources, 1, ajout);
		if (lapins.size() == 1)
		{
			std::list<Lapin>::iterator l = lapins.begin();
			if (COLOR)
				return (printf("\n\t%sLapin %d est mort de solitude%s\n\n", BHRED, l->get_index(), RESET));
			else
				return (printf("\t\tLapin %d est mort de solitude\n\n", l->get_index()));
		}
		vie(lapins, ressources, std::atoi(argv[3]), std::atoi(argv[4]));
		ajout = std::rand() % (std::atoi(argv[5]));
		ressources += ajout;
	}
	if (lapins.empty())
	{
		if (COLOR)
			printf("\t%sLES LAPINS ONT PERI%s\n\n", BHRED, RESET);
		else
			printf("\tLES LAPINS ONT PERI\n\n");
	}
	return (0);
}

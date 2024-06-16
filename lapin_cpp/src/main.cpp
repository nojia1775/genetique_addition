#include "../include/header.hpp"

int	main(int argc, char **argv)
{
	std::list<Lapin>	lapins;
	int			i;
	int			ressources;
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
		aff_lapins(lapins, ressources, 1);
		vie(lapins, ressources, std::atoi(argv[3]), std::atoi(argv[4]));
		ressources += std::atoi(argv[5]);
	}
	if (lapins.empty())
		printf("\tLES LAPINS ONT PERI\n\n");
	return (0);
}

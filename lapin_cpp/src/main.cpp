#include "../include/header.hpp"

int	main(int argc, char **argv)
{
	std::list<Lapin>	lapins;
	int			i;
	std::srand(std::time(0));
	if (argc < 2 || argc > 5)
		return (1);
	if (argc == 2 && !strcmp(argv[1], "-h"))
		return (help(), 0);
	if (argc != 5)
		return (1);
	i = 0;
	while (i++ < std::atoi(argv[1]))
		lapins.push_back(Lapin());
	printf("GENERATION INTITIALE : \n");
	aff_lapins(lapins);
	vie(lapins, std::atoi(argv[2]), std::atoi(argv[3]), std::atoi(argv[4]));
	printf("APRES VOL :\n");
	aff_lapins(lapins);
	return (0);
}
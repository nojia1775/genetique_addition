#include "../include/header.hpp"

int	main(int argc, char **argv)
{
	std::list<Lapin>	lapins;
	int			i;
	std::srand(std::time(0));
	if (argc < 2 || argc > 3)
		return (1);
	if (argc == 2 && !strcmp(argv[1], "-h"))
		return (help(), 0);
	if (argc != 3)
		return (1);
	i = 0;
	while (i++ < std::atoi(argv[1]))
		lapins.push_back(Lapin());
	aff_lapins(lapins);
	chasse(lapins, std::atoi(argv[2]));
	aff_lapins(lapins);
	return (0);
}
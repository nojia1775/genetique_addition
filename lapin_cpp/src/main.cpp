#include "../include/header.hpp"

int	main(int argc, char **argv)
{
	std::list<Lapin>	lapins;
	int			i;

	if (argc != 2)
		return (1);
	i = 0;
	while (i++ < std::atoi(argv[1]))
		lapins.push_back(Lapin());
	chasse(lapins);
	return (0);
}
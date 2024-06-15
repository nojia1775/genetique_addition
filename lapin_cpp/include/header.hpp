#ifndef HEADER_HPP

# define HEADER_HPP

# include <iostream>
# include <list>
# include <cstdio>
# include <cstdlib>
# include <ctime>
# include <cstring>
# include "Lapin.hpp"

class Lapin;

void	chasse(std::list<Lapin>& lapins, int ressources);
void	aff_lapins(std::list<Lapin> lapins);
void	help(void);

#endif
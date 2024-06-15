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

void	vie(std::list<Lapin>& lapins, int ressources, int survivre, int reproduction);
void	aff_lapins(std::list<Lapin> lapins);
void	help(void);
void	destin(std::list<Lapin>& lapins, int survivre, int reproduction);

#endif
#ifndef HEADER_HPP

# define HEADER_HPP
# define COLOR 0

# include <iostream>
# include <list>
# include <cstdio>
# include <cstdlib>
# include <ctime>
# include <cstring>
# include "Lapin.hpp"
# include "colors.hpp"

class Lapin;

void	vie(std::list<Lapin>& lapins, int& ressources, int survivre, int reproduction);
void	aff_lapins(std::list<Lapin> lapins, int ressources, int flag, int ajout);
void	help(void);
void	destin(std::list<Lapin>& lapins, int survivre, int reproduction);
void	sterelisation(std::list<Lapin>& lapins);
void	famine(std::list<Lapin>& lapins, int survivre, int reproduction);

#endif
#ifndef LAPIN_H

# define LAPIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include "../include/libft.h"

typedef struct  s_lapin
{
        int     vitesse;
        int     taille;
        int     vue;
        int     mort;
        int     parent;
        int     position;
        int     carrotes_manges;
}               Lapin;

typedef struct  list
{
        int     taille;
        int     carottes;
        Lapin   *list;
}               LIST;

void	aff(LIST *list);
void	chasse(LIST *list, Lapin *lapins);
LIST	*next_gen(LIST *list, int carottes);
size_t	size_of(Lapin **list);

#endif
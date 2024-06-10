#ifndef LAPIN_H

# define LAPIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef struct  s_lapin
{
        int     vitesse;
        int     taille;
        int     vue;
        int     sexe;
        int     mort;
        int     parent;
        int     position;
        int     carrotes_manges;
}               Lapin;

typedef struct  s_list
{
        int     taille;
        int     carottes;
        Lapin   *list;
}               t_list;

void	aff(t_list *list);
void	chasse(t_list *list);

#endif
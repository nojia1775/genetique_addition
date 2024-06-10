#ifndef GENETIC_H

# define GENETIC_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct	s_equa
{
	int	elem1;
	int	elem2;
}		t_equa;

t_equa	*first_gen(int n);
void	aff(t_equa *list, int n);
void	trier(t_equa **gen, int n, int target);
void	reproduction(t_equa **gen, int n);
int	ft_abs(int n);

#endif
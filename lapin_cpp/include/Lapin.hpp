#ifndef LAPIN_HPP

# define LAPIN_HPP

# include "header.hpp"

class	Lapin
{
	private:
		int	vitesse;
		int	vue;
		int	taille;
		int	index;

	public:
		int	mort;
		int	parent;
		int	carottes_manges;

		Lapin(void);
		Lapin(int vitesse, int vue, int taille);
		~Lapin(void);
		int	get_vitesse(void);
		int	get_vue(void);
		int	get_taille(void);
		int	get_index(void);
		void	set_vitesse(int vitesse);
		void	set_vue(int vue);
		void	set_index(int index);
		void	set_taille(int taille);
		void	aff(void);
};

#endif
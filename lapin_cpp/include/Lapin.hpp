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
		int	reserve;

	public:
		int	mort;
		int	parent;

		Lapin(void);
		~Lapin(void);
		int	get_vitesse(void);
		int	get_vue(void);
		int	get_taille(void);
		int	get_index(void);
		int	get_reserve(void);
		void	set_vitesse(int vitesse);
		void	set_vue(int vue);
		void	set_index(int index);
		void	set_taille(int taille);
		void	set_reserve(int reserve);
		void	aff(void);
};

#endif
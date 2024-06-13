#ifndef LAPIN_HPP

# define LAPIN_HPP

class	Lapin
{
	private:
		int	vitesse;
		int	vue;
		int	taille;

	public:
		int	index;
		int	mort;
		int	parent;

		Lapin(void);
		~Lapin(void);
		int	get_vitesse(void);
		int	get_vue(void);
		int	get_taille(void);
		void	aff(void);
};

#endif
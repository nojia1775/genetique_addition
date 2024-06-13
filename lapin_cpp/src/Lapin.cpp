#include "../include/Lapin.hpp"

Lapin::Lapin(void)
{
	static int	index;

	index = 0;
	std::srand(time(0));
	this->index = index++;
	this->mort = 0;
	this->parent = 0;
	this->vitesse = std::rand() % 10;
	this->vue = std::rand() % 10;
	this->taille = std::rand() % 10;
	if (this->taille > 7)
	{
		this->vitesse -= this->taille - 5;
		if (this->vitesse < 0)
			this->vitesse = 0;
	}
}

Lapin::~Lapin(void)
{
	return ;
}

int	Lapin::get_taille(void)
{
	return (this->taille);
}

int	Lapin::get_vitesse(void)
{
	return (this->vitesse);
}

int	Lapin::get_vue(void)
{
	return (this->vue);
}

void	Lapin::aff(void)
{
	printf("Lapin %d : Vitesse = %d\tVue = %d\tTaille = %d\n", this->index, this->vitesse, this->vue, this->taille);
}
#include "../include/Lapin.hpp"


Lapin::Lapin(void)
{
	static int n = 0;
	this->index = n++;
	this->mort = 0;
	this->parent = 0;
	this->vitesse = std::rand() % 10;
	this->vue = std::rand() % 10;
	this->taille = std::rand() % 10;
	this->carottes_manges = 0;
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

int	Lapin::get_index(void)
{
	return (this->index);
}

void	Lapin::aff(void)
{
	printf("Lapin %d :\tVitesse = %d\tVision = %d\tTaille = %d\tCarottes = %d\n", this->index, this->vitesse, this->vue, this->taille, this->carottes_manges);
}

void	Lapin::set_vitesse(int vitesse)
{
	this->vitesse = vitesse;
}

void	Lapin::set_vue(int vue)
{
	this->vue = vue;
}

void	Lapin::set_taille(int taille)
{
	this->taille = taille;
}

void	Lapin::set_index(int index)
{
	this->index = index;
}
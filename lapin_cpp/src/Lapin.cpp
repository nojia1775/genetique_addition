#include "../include/header.hpp"

Lapin::Lapin(void)
{
	static int n = 0;
	this->index = n++;
	this->mort = 0;
	this->parent = 0;
	this->vitesse = std::rand() % 10;
	this->vue = std::rand() % 10;
	this->taille = std::rand() % 10;
	this->set_reserve(0);
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

int	Lapin::get_reserve(void)
{
	return (this->reserve);
}

void	Lapin::aff(void)
{
	if (COLOR)
		printf("Lapin %d :\t%sVitesse%s = %d\t%sVision%s = %d\t%sTaille%s = %d\t%sReserve%s = %d\n", this->index, BLUE, RESET, this->vitesse, UWHITE, RESET, this->vue, RED, RESET, this->taille, YELLOW, RESET, this->get_reserve());
	else
		printf("Lapin %d :\tVitesse = %d\tVision = %d\tTaille = %d\tReserve = %d\n", this->index, this->vitesse, this->vue, this->taille, this->get_reserve());
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

void	Lapin::set_reserve(int reserve)
{
	this->reserve = reserve;
}
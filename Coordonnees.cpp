#include<SFML/Graphics.hpp>
#include<iostream>

#include "Coordonnees.h"

int Coordonnees::grilleX = 0;
int Coordonnees::grilleY = 0;


Coordonnees::Coordonnees()
{
	/*if (spaceX == 0 || spaceY == 0)
	{
		std::cerr << "une coordonnee a ete creee avant l'initialisation de l'espace" << std::endl;
	}*/
}


Coordonnees::Coordonnees(float px, float py) : x(px), y(py)
{
	//leDroitChemin();
}

void Coordonnees::operator+=(Vecteur const& pos)
{
	x += pos.x;
	y += pos.y;
	//leDroitChemin();

}

void Coordonnees::initialiserGrille(int lx, int ly)
{
	if (grilleX != 0 || grilleY != 0)
	{
		std::cerr << "espace deja initialise" << std::endl;
	}
	grilleX = lx;
	grilleY = ly;
}

void Coordonnees::setX(int ix = 0)
{
	if (ix == 40)
		x += ix;
	else {
		x = ix;
	}
}

void Coordonnees::setY(int iy) 
{ 
	if (iy == 40)
		y += iy;
	else
	{
		y = iy;
	}
}

float Coordonnees::calculerDistance(Coordonnees const& autre) const
{
	auto delta = Vecteur
	{
		std::min({abs(x - autre.x)}), std::min({abs(y - autre.y)})
	};
	return sqrt(delta.x * delta.x + delta.y * delta.y);
};


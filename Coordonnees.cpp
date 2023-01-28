#include<SFML/Graphics.hpp>
#include<iostream>

#include "Coordonnees.h"

int Coordonnees::grilleX = 0;
int Coordonnees::grilleY = 0;


Coordonnees::Coordonnees()
{
}


Coordonnees::Coordonnees(float px, float py) : x(px), y(py)
{
	limiteGrille();
}

void Coordonnees::operator+=(Vecteur const& pos)
{
	x += pos.x;
	y += pos.y;

}

bool Coordonnees::operator!=(Coordonnees const& pos)
{
	if (x != pos.x && y != pos.y)
		return true;
	return false;
}

void Coordonnees::initialiserGrille(int lx, int ly)
{
	grilleX = lx;
	grilleY = ly;
}

void Coordonnees::setX(int ix = 0)
{
	if (ix == 40 || ix == 80 || ix == -80)
		x += ix;
	else {
		x = ix;
	}
}

void Coordonnees::setY(int iy) 
{ 
	if (iy == 40 || iy == 80 || iy == -80)
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

bool Coordonnees::limiteGrille()
{
	if (x < grilleX - 10 || x > finGrilleX + 10 || y < grilleY - 10 || y > finGrilleY + 10)
		return true;
	else
		return false;
}

void Coordonnees::setFinGrilleX(int longueurGrille)
{
	finGrilleX = longueurGrille;
}

void Coordonnees::setFinGrilleY(int hauteurGrille)
{
	finGrilleY = hauteurGrille;
}

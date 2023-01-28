#define _USE_MATH_DEFINES

#include <cmath>

#include "Vecteur.h"

Vecteur Vecteur::creerDepuisAngle(float angleEnDegre) //vecteur qui va faire avancer le vaisseau en fonction de son angle de rotation
{
	return { 150.f * cos(angleEnDegre / 180.f * static_cast<float>(M_PI)), 150.f * sin(angleEnDegre / 180.f * static_cast<float>(M_PI)) };
}

void Vecteur::operator+=(Vecteur const& autre)
{
	x += autre.x;
	y += autre.y;
}

void Vecteur::operator-=(Vecteur const& autre)
{
	x -= autre.x;
	y -= autre.y;
}

Vecteur Vecteur::operator*(float coefficient) const
{
	return Vecteur{ x * coefficient, y * coefficient };
}
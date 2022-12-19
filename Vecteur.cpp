#define _USE_MATH_DEFINES

#include <cmath>

#include "Vecteur.h"

Vecteur Vecteur::creerDepuisAngle(float taille, float angleEnDegre) //vecteur qui va faire avancer le vaisseau en fonction de son angle de rotation
{
	float regulateurVitesse = 100;
	Vecteur vitesseMax;
	if (taille > regulateurVitesse)
		return vitesseMax;
	else
	{
		vitesseMax = { taille * cos(angleEnDegre / 180.f * static_cast<float>(M_PI)), taille * sin(angleEnDegre / 180.f * static_cast<float>(M_PI)) };
		return vitesseMax;
	}
	// corriger vitesse, retirer acceleration et garder vitesse constante
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
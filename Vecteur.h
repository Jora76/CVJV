#pragma once
struct Vecteur
{
	static Vecteur creerDepuisAngle(float taille, float angleEnDegre);
	void operator+=(Vecteur const& autre);
	void operator-=(Vecteur const& autre);
	Vecteur operator*(float coefficient) const;
	float x{ 0.f };
	float y{ 0.f };
};
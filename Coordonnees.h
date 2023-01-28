#pragma once

#include "Vecteur.h"

class Coordonnees
{
public:
	void operator+= (Vecteur const& pos);
	bool operator != (Coordonnees const& pos);
	void setX(int ix);
	void setY(int iy);
	inline float getX() const { return x; };
	inline float getY() const { return y; };
	static inline int getgrilleX() { return grilleX; };
	static inline int getgrilleY() { return grilleY; };
	static void initialiserGrille(int lx, int ly);
	Coordonnees();
	Coordonnees(float px, float py);
	float calculerDistance(Coordonnees const& autre) const;
	void setFinGrilleX(int longueurGrille);
	void setFinGrilleY(int hauteurGrille);
	bool limiteGrille();

private:
	float x{};
	float y{};

	static int grilleX;
	static int grilleY;
	int finGrilleX = 0;
	int finGrilleY = 0;

};


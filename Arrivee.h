#pragma once

#include "Interface.h"
//#include "Jeu.h" // cause de l'erreur à la con t'as encore fait la connerie de la boucle d'include

class Arrivee :
	public ElementInterface
{
public:
	explicit Arrivee(Interface& interface_ptr, Coordonnees const& position_ptr);
	//void compterCheckpoint();
private:
	Interface& interface;
	/*short int checkPointsRecuperes = 0;
	short int nbCheckPoints = 0;*/

	virtual void reagirCollision(TypeElement typeAutre, float angle = 0) override;
};


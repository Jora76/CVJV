#pragma once

#include "Interface.h"

class Arrivee :
	public ElementInterface
{
public:
	explicit Arrivee(Interface& interface_ptr, Coordonnees const& position_ptr);
	Interface& interface;
	//virtual void reagirCollision(TypeElement typeAutre) override;
private:
};


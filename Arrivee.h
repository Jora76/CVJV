#pragma once

#include "Interface.h"

class Arrivee :
	public ElementInterface
{
public:
	explicit Arrivee(Interface& interface_ptr, Coordonnees const& position_ptr);
private:
	Interface& interface;

	virtual void reagirCollision(TypeElement typeAutre, float angle = 0) override;
};


#pragma once

#include "ElementInterface.h"
#include "Interface.h"

class Interrupteur :
	public ElementInterface
{
public:
	explicit Interrupteur(Interface& interface_ptr, Coordonnees const& position_ptr);
	Interface& interface;
	//inline bool getOuvert() { return ouvert; };
	/*
private:
	virtual void reagirCollision(TypeElement typeAutre) override;
	static bool ouvert;*/
};


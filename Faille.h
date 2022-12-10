#pragma once

#include "ElementInterface.h"
#include "Interface.h"
#include "Interrupteur.h"

class Faille :
	public ElementInterface
{
public:
	explicit Faille(Interface& interface_ptr, Coordonnees const& position_ptr);

private:/*
	virtual void reagirCollision(TypeElement typeAutre) override;*/
	Interface& interface;
};


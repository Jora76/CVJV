#pragma once

#include "ElementInterface.h"
#include "Interface.h"
#include "Interrupteur.h"

class Faille :
	public ElementInterface
{
public:
	explicit Faille(Interface& interface_ptr, Coordonnees const& position_ptr);

private:
	Interface& interface;
	virtual void actualiser() override;
};


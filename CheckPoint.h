#pragma once

#include "Interface.h"

class CheckPoint :
	public ElementInterface
{
public:
	explicit CheckPoint(Interface& interface_ptr, Coordonnees const& position_ptr);
	Interface& interface;

private:
	virtual void reagirCollision(TypeElement typeAutre, float angle = 0) override;
};


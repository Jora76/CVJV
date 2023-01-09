#pragma once

#include "ElementInterface.h"
#include "Interface.h"

class Interrupteur :
	public ElementInterface
{
public:
	explicit Interrupteur(Interface& interface_ptr, Coordonnees const& position_ptr);
	Interface& interface;
	static inline bool getOuvert() { return ouvert; }
	static inline void setOuvert() { ouvert = true; }
private:
	virtual void reagirCollision(TypeElement typeAutre, float angle = 0) override;
	static inline bool ouvert{ true };
	sf::Clock dernierPassage;
};


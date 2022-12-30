#pragma once

#include <SFML/Graphics.hpp>
#include "Coordonnees.h"
//#include "Curseur.h" à ne pas décommenter sinon erreur

enum class TypeElement { 
	CURSEUR, 
	OBSTACLE, 
	INTERRUPTEUR, 
	PANNEAU, 
	PANNEAU_TOUCHE, 
	PANNEAU_DRAG,
	PANNEAU_BASE,
	CHECKPOINT, 
	CHECKPOINT_RECUPERE, 
	TP, 
	TP_TOUCHE,
	BOUTON_GRILLE,
	AUTRE
};

class ElementInterface
{
public:
	virtual ~ElementInterface() = default;
	explicit ElementInterface(std::string_view const&);
	ElementInterface(ElementInterface const& autre) = delete;
	void operator= (ElementInterface const& autre) = delete;
	void afficher(sf::RenderWindow& window) const;
	virtual void positionner();
	virtual void testerCollision(ElementInterface& autre);
	virtual void reagirCollision(TypeElement typeAutre, float angle = 0);
	float getRayon() const;
	static inline bool aSupprimer(std::unique_ptr<ElementInterface>& element) { return element->supprimer; };
	virtual void actualiser();
	TypeElement getType() const;
	void setType(TypeElement changementType);
protected:
	float getAngle() const;
	bool supprimer{ false };
	bool reactionDejaAppelee{ false };
	sf::Sprite sprite{};
	TypeElement type{ TypeElement::AUTRE };
	Coordonnees position{};
};


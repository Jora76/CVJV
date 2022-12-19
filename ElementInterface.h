#pragma once

#include <SFML/Graphics.hpp>
#include "Coordonnees.h"
//#include "Curseur.h" � ne pas d�commenter sinon erreur

enum class TypeElement { CURSEUR, OBSTACLE, INTERRUPTEUR, PANNEAU, PANNEAU_TOUCHE, CHECKPOINT, CHECKPOINT_RECUPERE, AUTRE, TP, TP_TOUCHE };

class ElementInterface
{
public:
	virtual ~ElementInterface() = default;
	explicit ElementInterface(std::string_view const&);
	ElementInterface(ElementInterface const& autre) = delete;
	void operator= (ElementInterface const& autre) = delete;
	virtual void afficher(sf::RenderWindow& window) const;
	virtual void positionner();
	virtual void testerCollision(ElementInterface& autre);
	virtual void reagirCollision(TypeElement typeAutre, float angle = 0);
	float getRayon() const;
	static inline bool aSupprimer(std::unique_ptr<ElementInterface>& element) { return element->supprimer; };
	virtual void actualiser();
	bool estCheckpoint();
	bool estCheckPointRecupere();
	void setType(TypeElement changementType);
protected:
	float getAngle() const;
	bool supprimer{ false };
	bool reactionDejaAppelee{ false };
	sf::Sprite sprite{};
	TypeElement type{ TypeElement::AUTRE };
	Coordonnees position{};
};

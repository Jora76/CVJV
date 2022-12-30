#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Vecteur.h"
#include "Interface.h"
#include "Panneau.h"

class Curseur : public Bouton
{
public:
	explicit Curseur(Interface& interface_ptr, Coordonnees const& position_ptr);
	//virtual void testerCollision(ElementInterface& autre) override;
	virtual void reagirCollision(TypeElement typeAutre, float angle = 0) override;
private:
	//Méthodes
	void mettreAJour(float temps);
	virtual void reagirClic(sf::Event& event) override;
	virtual void actualiser() override;
	virtual void setCouleur(bool sourisDessus) override;
	void resetPosition();

	//Attributs
	Vecteur vitesse{ 0.0f, 0.0f };
	Interface& interface;
	Coordonnees posInit{};
	sf::Clock chrono;
	sf::Clock dernierClic;
	//float test;

	static constexpr float ACCELERATION{ 250.f };
};


#pragma once
#include <SFML/Graphics.hpp>
#include "Interface.h"
#include "BoutonGrille.h"

class BoutonSupprimer :
    public Bouton
{
public:
    BoutonSupprimer(Interface& interface_ptr);
    virtual void reagirClic(sf::Event& event) override;
private:
    Interface& interface;
    virtual void reagirSouris(bool sourisDessus) override;
};


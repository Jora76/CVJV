#pragma once
#include <SFML/Graphics.hpp>
#include "Bouton.h"
#include "Curseur.h"

class BoutonValider :
    public Bouton
{
public:
    BoutonValider(Interface& interface_ptr);
    virtual void reagirClic(sf::Event& event) override;
private:
    Interface& interface;
    //virtual void reagirSouris(bool sourisDessus) override;
};


#pragma once
#include "Bouton.h"
#include "Jeu.h"
class BoutonJouer :
    public Bouton
{
public:
    BoutonJouer(Interface& interface_ptr, Jeu& jeu_ptr, Coordonnees& position_ptr);
private:
    virtual void reagirClic(sf::Event& event) override;

    Jeu& jeu;
    Interface& interface;
};


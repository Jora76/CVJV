#pragma once
#include "Bouton.h"
#include "Interface.h"
#include "Panneau.h"

class BoutonGrille :
    public Bouton

{
public:
    explicit BoutonGrille(Interface& interface_ptr, Coordonnees const& position_ptr);
    Interface& interface;
    virtual void reagirClic(sf::Event& event) override;
private:
    virtual void setCouleur(bool sourisDessus) override;
};


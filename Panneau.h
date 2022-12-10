#pragma once
#include "Interface.h"
#include "ElementInterface.h"
class Panneau :
    public Bouton
{
public:
    explicit Panneau(const Coordonnees& position_ptr, const float angle_ptr);
private:
    virtual void reagirClic(sf::Event& event) override;
    
};


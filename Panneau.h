#pragma once
#include "Interface.h"
#include "ElementInterface.h"
class Panneau :
    public Bouton
{
public:
    explicit Panneau(const Coordonnees& position_ptr, const float angle_ptr);
    void setNombrePanneaux();
private:
    virtual void reagirClic(sf::Event& event) override;
    virtual void reagirCollision(TypeElement typeAutre, float angle = 0) override;
    virtual void setCouleur(bool sourisDessus) override;
};


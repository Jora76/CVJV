#pragma once
#include "Panneau.h"

class PanneauDirection :
    public Panneau
{
public:
    PanneauDirection(const Coordonnees& position_ptr, const float angle_ptr, Interface& interface_ptr);
private:
    virtual void genererPanneau() override;
    float angle;
};


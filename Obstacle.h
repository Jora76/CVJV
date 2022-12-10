#pragma once
#include "ElementInterface.h"
#include "Interface.h"

class Obstacle :
    public ElementInterface
{
public:
    explicit Obstacle(Interface& interface_ptr, Coordonnees const& position_ptr);
    Interface& interface;
protected:
    //virtual void reagirCollision(TypeElement typeAutre) override;

private:
};


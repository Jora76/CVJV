#pragma once
#include "Interface.h"
#include "ElementInterface.h"
#include "BoutonGrille.h"
#include <array>

class Panneau :
    public Bouton
{
public:
    explicit Panneau(const Coordonnees& position_ptr, Interface& interface_ptr,/* int qte, std::array <unsigned short int, 5>& tab_ptr,*/ std::string_view chemin);
    //void setNombrePanneaux(float i);
protected:
    virtual void genererPanneau() = 0;
    virtual float getTypePanneau() = 0;
    Coordonnees posDrop;
    Coordonnees posInit;
    Interface& interface;
private:
    virtual void reagirClic(sf::Event& event) override;
    virtual void reagirCollision(TypeElement typeAutre, float angle = 0) override;
    virtual void setCouleur(bool sourisDessus) override;
    virtual void testerClic(sf::Event& event, sf::RenderWindow& window) override;
    void drop();
    
    //std::array <unsigned short int, 5>& tab;
};


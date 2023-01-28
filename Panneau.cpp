#include "Panneau.h"

Panneau::Panneau(const Coordonnees& position_ptr, Interface& interface_ptr, std::string_view chemin) : Bouton{position, chemin }, interface{interface_ptr}
{
	type = TypeElement::AUTRE;
	sprite.setScale(sprite.getScale().x, sprite.getScale().x);
}

void Panneau::testerClic(sf::Event& event, sf::RenderWindow& window, sf::View& view)
{
	if (!valider)
	{
		sf::Vector2f sourisGlobalPos = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
		//Drag

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (interface.dragAutre() == false 
				&& ((type == TypeElement::PANNEAU || type == TypeElement::TP) || interface.panneauDispo(getTypePanneau()) == true))
			{
				if (type == TypeElement::PANNEAU_BASE)
					interface.actualiserComptPanneau(-1, getTypePanneau());
				setType(TypeElement::PANNEAU_DRAG);
			}

			if (sf::Event::MouseMoved && type == TypeElement::PANNEAU_DRAG)
			{
				position = { sourisGlobalPos.x, sourisGlobalPos.y };
			}

		}

		//Drop

		Coordonnees posSouris = { sourisGlobalPos.x, sourisGlobalPos.y };

		if (type == TypeElement::PANNEAU_DRAG && position != posSouris)
		{
			drop();
		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (type == TypeElement::PANNEAU_DRAG)
				{
					drop();
				}
			}
		}
		
	}
}

void Panneau::drop()
{
	posDrop = interface.getPosBtn();
	if (posDrop.getX() != 0 && posDrop.getY() != 0)
	{
		genererPanneau();
		position = posDrop;
	}
	else
	{
		position = posInit;
		setType(TypeElement::PANNEAU_BASE);
		interface.actualiserComptPanneau(1, getTypePanneau());
	}
}

void Panneau::reagirClic(sf::Event& event)
{
}

void Panneau::reagirCollision(TypeElement typeAutre, float angle)
{
	if(typeAutre == TypeElement::CURSEUR)
		sprite.setColor(sf::Color::Color(0, 255, 0, 0));
}
void Panneau::setCouleur(bool sourisDessus)
{
	if (type == TypeElement::PANNEAU || type == TypeElement::TP)
		sprite.setColor(sf::Color::Color(0, 255, 0, 255));
}
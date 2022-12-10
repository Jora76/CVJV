#pragma once

#include <SFML/Graphics.hpp>
#include <string_view>
#include <unordered_map>
#include <iostream>

class GestionnaireRessources
{
	public:
		GestionnaireRessources() = delete; //évite toute création d'objet de type Gestionnaireressources
		static sf::Texture const& getRessource(std::string_view const& chemin); //const pour ne pas modifier texture chargée

	private:
		static std::unordered_map<std::string_view, sf::Texture> ressources;

};


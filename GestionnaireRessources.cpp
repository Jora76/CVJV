#include "GestionnaireRessources.h"

template<>
std::unordered_map<std::string_view, sf::Texture> GestionnaireRessources<sf::Texture>::ressources{};//cr�ation tableau de pairs pour gestion dynamique des textures des sprites en m�moire

template<>
std::unordered_map<std::string_view, sf::SoundBuffer> GestionnaireRessources<sf::SoundBuffer>::ressources{};//cr�ation tableau de pairs pour gestion dynamique des textures des sprites en m�moire

//Le gestionnaire de ressources prend en param�tre un string_view pointant vers la texture � charger
//Il teste si la texture est d�ja en m�moire. Si oui, il pointe vers la texture correspondante. Si non, il la charge et cr�e une nouvelle pair pour celle-ci.
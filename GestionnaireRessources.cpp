#include "GestionnaireRessources.h"

template<>
std::unordered_map<std::string_view, sf::Texture> GestionnaireRessources<sf::Texture>::ressources{};//création tableau de pairs pour gestion dynamique des textures des sprites en mémoire

template<>
std::unordered_map<std::string_view, sf::SoundBuffer> GestionnaireRessources<sf::SoundBuffer>::ressources{};//création tableau de pairs pour gestion dynamique des textures des sprites en mémoire

//Le gestionnaire de ressources prend en paramètre un string_view pointant vers la texture à charger
//Il teste si la texture est déja en mémoire. Si oui, il pointe vers la texture correspondante. Si non, il la charge et crée une nouvelle pair pour celle-ci.
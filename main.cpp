#include <SFML/Graphics.hpp>
#include <memory>

#include "Interface.h"
#include "Enigme.h"
#include "Jeu.h"

constexpr int LONGUEUR_FENETRE{ 1280 };
constexpr int HAUTEUR_FENETRE{ 720 };

int main()
{
    sf::Event event;
    sf::RenderWindow window(sf::VideoMode(LONGUEUR_FENETRE, HAUTEUR_FENETRE), "CV Jeu-vidéo");
    auto interface = Interface{};
    auto enigme = Enigme{interface};
    auto jeu = Jeu{interface, enigme};
    jeu.demarrer();


    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //window.setKeyRepeatEnabled(false);
        interface.positionner();
        interface.gererSouris(event, window);
        interface.actualiser();
        window.clear();
        interface.afficher(window);
        jeu.afficherTexte(window);
        window.display();
        interface.nettoyer(); 
    }

    return 0;
}

/*Reste à faire :

- mini histoire avec lignes de dialogue
- création classe jeu qui va gerer le déroulement de la partie (en cours)
- terminer les réactions aux collisions
- coder les textes (en cours)
- coder les boutons (en cours)
- gestion des erreurs et exceptions
- sound design
- animations de certains sprites
*/
/*
---------------------------------------GITHUB-------------------------------------------------

Afficher terminal VS : ctrl + ù

Envoyer projet :
    - compiler projet
    - git status
    - git add *.cpp
    - git add *.h
    - git commit -m 'modif'
    - git push origin master

Recuperer projet :
    - git status
    - git fetch
    - git pull
*/


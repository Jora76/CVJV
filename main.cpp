#include <SFML/Graphics.hpp>
#include <memory>

#include "Interface.h"
#include "Enigme.h"
#include "Jeu.h"
#include "GestionnaireTexte.h"

constexpr float LONGUEUR_FENETRE{ 1920 };
constexpr float HAUTEUR_FENETRE{ 1080 };

void redimentionnerView(sf::RenderWindow& window, sf::View& view)
{
    double ratioBase = LONGUEUR_FENETRE / HAUTEUR_FENETRE;
    float windowRatio = float(window.getSize().x) / float(window.getSize().y);
    float viewRatio = 1280.f / 720.f;

    sf::FloatRect viewport;

    if (windowRatio < viewRatio)
    {
        viewport.width = 1.f;
        viewport.height = windowRatio / viewRatio;
        viewport.left = 0.f;
        viewport.top = (1.f - viewport.height) / 2.f;
    }

    else
    {
        viewport.width = viewRatio / windowRatio;
        viewport.height = 1.f;
        viewport.left = (1.f - viewport.width) / 2.f;
        viewport.top = 0.f;
    }

    view.setViewport(viewport);
}

int main()
{
    sf::Event event;
    sf::View view (sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1280, 720));
    sf::RenderWindow window(sf::VideoMode(LONGUEUR_FENETRE, HAUTEUR_FENETRE), "CV Jeu-vidéo");
    auto texte = GestionnaireTexte{window};
    auto interface = Interface{};
    auto enigme = Enigme{interface};
    auto jeu = Jeu{interface, enigme, texte};
    jeu.demarrer();


    while (window.isOpen())
    {
        window.setFramerateLimit(60);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
                redimentionnerView(window, view);
        }
        window.setView(view);
        view.setCenter(640.f, 360.f);
        window.setKeyRepeatEnabled(false);
        interface.positionner();
        interface.gererSouris(event, window);
        interface.actualiser();
        window.clear();
        interface.afficher(window);
        jeu.actualiser();
        jeu.gererTexte();
        window.display();
        interface.nettoyer();
    }

    return 0;
}

/*Reste à faire :

- mini histoire avec lignes de dialogue (en cours)
- création classe jeu qui va gerer le déroulement de la partie (en cours)
- coder les textes (en cours)
- coder les boutons (en cours)
- gestion des erreurs et exceptions
- sound design
- animations de certains sprites

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

---------------------------------------------------------------------------------------------
*/


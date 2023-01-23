#include "Jeu.h"

Jeu::Jeu(Interface& interface_ptr, Enigme& enigme_ptr, GestionnaireTexte& texte_ptr) : interface{ interface_ptr }, enigme{enigme_ptr}, texte{texte_ptr}
{
}


void Jeu::demarrer()
{
	enCours = true;
    choisirEnigme();
    interface.ajouter(std::make_unique<Fenetre>(cheminFenetre));
    interface.ajouterBouton(std::make_unique<BoutonValider>(interface));
    interface.ajouterBouton(std::make_unique<BoutonSupprimer>(interface));
    enigme.generer(cheminEnigme);
    instanceActuelle = Instance::ENIGME;
}

void Jeu::choisirEnigme()
{
    if (compteur < 3) {
       // compteur = 2;
        ++compteur;
    }
    else
        terminer();
    cheminEnigme = "ressources/niveaux/enigme" + std::to_string(compteur) + ".txt";
    cheminFenetre = "ressources/sprites/Fenetre_" + std::to_string(compteur) + ".png";
}

//void Jeu::afficherTexte(sf::RenderWindow& fenetre)
//{
//    police.loadFromMemory(data, data_length);
//
//    sf::Text texteObjectif("Objectif : Ramassez tous les checkpoints !", police);
//    sf::Text texteConsigne("Placez les panneaux de manière à emmener le curseur vers l'arrivée.", police, 20);
//
//    texteConsigne.setPosition(172, 135);
//    //definirTexte(texteObjectif);
//    texte.setStyle(texteConsigne);
//    texte.setStyle(texteObjectif);
//    fenetre.draw(texteObjectif);
//    fenetre.draw(texteConsigne);
//}

void Jeu::gererTexte() //gerer tout court, pas juste texte
{/*
    switch (instanceActuelle)
    {
    case Instance::ENIGME:
        texte.actualiserCompteurs(compteursPanneaux);
    }*/
}

//void Jeu::definirTexte(sf::Text& texte)
//{
//    texte.setFillColor(sf::Color::Green);
//    texte.setFont(police);
//    texte.setCharacterSize(20);
//    texte.setPosition(172, 85);
//}

void Jeu::continuer()
{
    demarrer();
    interface.setContinuer();
}

void Jeu::actualiser()
{
    if (interface.getContinuer() == true)
    {
        continuer();
    }
}

void Jeu::retirerTexte()
{

}
void Jeu::terminer()
{
    interface.vider();
    //retirerTexte();
}

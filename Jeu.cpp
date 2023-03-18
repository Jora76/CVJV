#include "Jeu.h"

Jeu::Jeu(Interface& interface_ptr, Enigme& enigme_ptr, GestionnaireTexte& texte_ptr, sf::Event& event_ptr) : interface{ interface_ptr }, enigme{enigme_ptr}, texte{texte_ptr}, event{event_ptr}
{
}

void Jeu::demarrer() //Doit etre appelée qu'une seule fois. 
{
    switch (instanceActuelle)
    {
    case Instance::ENIGME:
        choisirEnigme();
        interface.ajouter(std::make_unique<Fenetre>(cheminFenetre));
        interface.ajouterBouton(std::make_unique<BoutonValider>(interface));
        interface.ajouterBouton(std::make_unique<BoutonSupprimer>(interface));
        enigme.generer(cheminEnigme);
        break;
    case Instance::DIALOGUE:
        interface.ajouter(std::make_unique<Fenetre>("ressources/sprites/Interface_dialogues.png"));
        initDialogues();
        break;
    }
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

void Jeu::actualiserTexte(sf::RenderWindow& window) //gerer tout court, pas juste texte
{
    switch (instanceActuelle)
    {
    case Instance::ENIGME:
        interface.mettre_A_Jour_Txt_ComptPanneau(texte);
        break;
    case Instance::DIALOGUE:
        bool clic = false;
        if (event.type == sf::Event::MouseButtonPressed && !clic)
        {
            clic = true;
            if (i < dialogues.size())
            {
                sf::Text dial;
                dial.setString(dialogues[i]);
                texte.ajouter(dialogues[i], posTxtDialogues, 2);
                interface.defilerTxt(texte, dial, posTxtDialogues, window);
                ++i;
            }
            else
            {
                interface.setContinuer(true);
            }
        }
        break;
    }
    texte.afficher();
}

void Jeu::setInstance()
{
    switch (instanceActuelle)
    {
    case Instance::DIALOGUE:
        instanceActuelle = Instance::ENIGME;
        break;
    default:
        instanceActuelle = Instance::DIALOGUE;
        break;
    }
}

void Jeu::initDialogues()
{
    std::string chemin = "ressources/dialogues/dialogues" + std::to_string(compteur) + ".txt";
    std::ifstream dialogue(chemin.data());

    if (!dialogue)
    {
        std::cout << "Le fichier n'a pas pu etre charge." << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        std::string ligne;
        while (getline(dialogue, ligne))
        {
            dialogues.push_back(ligne);
        }
    }
}


void Jeu::continuer()
{
    texte.vider();
    interface.vider();
    setInstance();
    demarrer();
    initTexte();
    interface.setContinuer(false);
}

void Jeu::actualiser(sf::RenderWindow& window)
{
    if (interface.getContinuer() == true)
    {
        continuer();
    }
    actualiserTexte(window);
}

void Jeu::initTexte()
{
    switch (instanceActuelle)
    {
    case Instance::ENIGME:
        texte.ajouter(texteConsigne, posTxtConsigne, 1);
        texte.ajouter(texteObjectif, posTxtObjectif, 1);
        interface.ajouterCompteurs(texte);
        break;
    case Instance::MENU:
        texte.ajouter(texteMenu, posTxtMenu, 3);
        texte.ajouter(texteEchap, posTxtEchap, 3, 15);
        break;
    }
}

void Jeu::terminer()
{
    interface.vider();
}

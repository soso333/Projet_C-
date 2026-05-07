#include <iostream>
#include "Donjon.h"
#include "Aventurier.h"



int main() {
    Donjon terrain; // initialisation du donjon
    Aventurier joueur;  // initialisation du joueur

    terrain.initialiserGrille(15,7); // création du donjon
    terrain.placerElements();  // placement des monstres, trésors, pièges, ...

    joueur.boucleDeJeu(terrain); // lancement du jeu
    return 0;
}
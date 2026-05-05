#include <iostream>
#include "Donjon.h"
#include "Aventurier.h"

/*
void resoudreCase(Case* c){
    c.appliqueEffet();
};
*/



int main() {
    Donjon terrain;
    Aventurier joueur;
    terrain.initialiserGrille(21,21);
    terrain.placerElements();
    joueur.boucleDeJeu(terrain);
    return 0;
}
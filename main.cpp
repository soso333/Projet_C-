#include <iostream>
#include "Donjon.h"
#include "Aventurier.h"


int main() {
    Donjon terrain;
    terrain.initialiserGrille(21,21);
    terrain.placerElements();
    terrain.afficher();
    return 0;
}
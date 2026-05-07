#include <iostream>
using namespace std;
#include "Case.h"


#ifndef CASEFACTORY_H
#define CASEFACTORY_H

class Case;

enum class TypeCase{
    Mur,
    Passage,
    Tresor,
    Piege,
    Monstre
};

class CaseFactory {
    /*
    Classe permettant l'implémentation du design pattern.
    
    Méthodes :
        - creerCase(TypeCase type) : static Case*
            Permet la création de la case à travers l'enum.
    
    */
    public:
        static Case* creerCase(TypeCase type);
};

#endif
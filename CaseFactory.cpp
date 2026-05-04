#include "CaseFactory.h"
#include "Case.h"

#include "Mur.h"
#include "Passage.h"
#include "Tresor.h"
#include "Monstre.h"
#include "Piege.h"


Case* CaseFactory::creerCase(TypeCase type) {
    if (type == TypeCase::Mur) {
        return new Mur();
    }
    if (type == TypeCase::Passage) {
        return new Passage();
    }
    if (type == TypeCase::Monstre) {
        return new Monstre();
    }
    if (type == TypeCase::Piege) {
        return new Piege();
    }
    if (type == TypeCase::Tresor) {
        return new Tresor();
    }
    return nullptr;
};
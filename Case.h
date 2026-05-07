#ifndef CASE_H
#define CASE_H

#include "CaseFactory.h"
//#include "Aventurier.h", pb de dépendance circulaire

//du coup on va déclarer la classe aventurier de manière anticipée pour régler le souci...
class Aventurier; 
// on donnera les détails de la classe aventurier dans le .h, mais pour que le code compile on doit quand meme déclarer la classe


class Case {
    /*
    Classe permettant de définir chaque case de la grille.

    Paramètres :
        - visite : bool (private)
            Désigne si la case a été visité ou pas.

    Méthodes :
        - afficher() : char
            Renvoie le symbole ASCII de la case.
        - appliqueEffet(int points_de_vie_joueur) : int
            Applique l'effet spécifique de la case sur l'aventurier.
        - ~Case()
            Destructeur de la classe Case.
        - getVisite() : bool
            Getter du paramètre visite. Renvoie l'état de la case (visité ou pas).
        - setVisite : void
            Setter du paramètre visite. Modifie l'état de la case.
    */
    private:
            bool visite = false;
            
    public:
        TypeCase type; 
        virtual char afficher() const = 0; 
        virtual void appliqueEffet(Aventurier& aventurier) = 0;
        virtual ~Case() = default;
        bool getVisite(){
            return visite;
        };
        void setVisite(bool visit){
            visite = visit;
        };
        
        friend std::ostream& operator<<(std::ostream& os, Case& c) {
            os << c.afficher();
            return os;
        }
        

};


#endif
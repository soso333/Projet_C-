#ifndef CASE_H
#define CASE_H


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
            virtual char afficher() = 0; 
            virtual int appliqueEffet(int points_de_vie_joueur) = 0;
            virtual ~Case() = default;
            bool getVisite(){
                return visite;
            };
            void setVisite(bool visit){
                visite = visit;
            };
};

#endif
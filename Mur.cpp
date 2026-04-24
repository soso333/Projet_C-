class Mur : public Case {

    /* Classe permettant de définir un mur

    Méthode : 
        afficher() : char
        Permet d'afficher la chaîne de caractère représentant le mur dans le labyrinthe (par #)

        appliqueEffet() : int
        Les PV du joueur restent inchangés, mais il faut quand même définir cette méthode pour que le code compile, vu que c'est une méthode virtuelle pure dans la classe Case
    */

    public:
        char afficher(){
            char a = '#';
            return a;
        }

        virtual int appliqueEffet(int points_de_vie_joueur){ 
            return points_de_vie_joueur;
        }
};
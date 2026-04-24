class Tresor : public Case {

    /* Classe permettant de définir le trésor qu'un joueur peut avoir

    Paramètres : 
        valeur : int (private)
        Permet de définir une valeur à une récompense perçue par un joueur (exemple : +10 trésors)

    Méthode : 
        init : void 
        Permet d'initiliaser la valeur du trésor

        afficher() : char
        Permet d'afficher la chaîne de caractère représentant le trésor dans le labyrinthe (par +)

        appliqueEffet() : int
        Permet d'appliquer l'effet du trésor sur le joueur 
    */

    private : 
        int valeur;

    public : 
        void init(int a){
            valeur = a;
        }

        char afficher(){
            char b = '+';
            return b;
        }

        virtual int appliqueEffet(int points_de_vie_joueur){
            points_de_vie_joueur += valeur;
            return points_de_vie_joueur;
        }

};
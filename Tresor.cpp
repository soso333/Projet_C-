class Tresor : public Case {

    /* Classe permettant de définir le trésor qu'un joueur peut avoir

    Paramètres : 
        valeur : int (private)
        Permet de définir une valeur à une récompense perçue par un joueur (exemple : +10 trésors)
        nb_tresor : int (private)
        Permet de définir le nb de trésor qu'un joueur possède

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
        int nb_tresor;

    public : 
        void init(int a, int b){
            valeur = a;
            nb_tresor = b;
        }

        char afficher(){
            char b = '+';
            return b;
        }

        virtual int appliqueEffet(){
            nb_tresor += valeur;
            return nb_tresor;
        }

};
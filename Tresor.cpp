class Tresor : public Case {

    """ Classe permettant de définir le trésor qu'un joueur peut avoir

    Paramètres : 
        valeur : int (private)
        Permet de définir une valeur à une récompense perçue par un joueur (exemple : +10 pts de vie)

    Méthode : 
        init : void 
        Permet d'initiliaser la valeur du trésor

        afficher() : char
        Permet d'afficher la chaîne de caractère représentant le trésor dans le labyrinthe (par +)

        appliqueEffet() : void 
        Permet d'appliquer l'effet du trésor sur le joueur (exemple : augmenter les points de vie du joueur)


    """

    private : 
        int valeur;

    public : 
        //jsp 
        void init(int a){
            valeur = a
        }
        char afficher(){
            char a = '+';
            return a;
        }

        void appliqueEffet(){

        }

};
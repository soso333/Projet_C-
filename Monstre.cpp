class Monstre : public Case{

    """ Classe permettant de définir le monstre qu'un joueur peut rencontrer

    Paramètres : 
        valeur : int (private)
        Permet de définir une valeur qui supprime des points de vie à un joueur

    Méthode : 
        init : void 
        Permet d'initiliaser la valeur de l'attaque du monstre

        afficher() : char
        Permet d'afficher la chaîne de caractère représentant le monstre dans le labyrinthe (par +)

        appliqueEffet(int points_de_vie_joueur) : int
        Permet d'appliquer l'effet de l'attaque du monstre sur le joeur
        Prends en paramètre les pv de l'aventurier

        fuite() : void 
        Permet de déterminer si le joueur veut fuir ou pas face au monstre
    """

    private : 
        int valeur;

    public : 
        void init(int a){
            valeur = a;
        }

        char afficher(){
            char a = 'M';
            return a;
        }

        virtual int appliqueEffet(int points_de_vie_joueur){
            points_de_vie_joueur =- valeur; 
            return points_de_vie_joueur;
        }

        void fuite(){
            //ksndjdjd
        }
};
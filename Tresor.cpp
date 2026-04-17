class Tresor : public Case {

    """ Classe permettant de définir le trésor qu'un joueur peut avoir

    Paramètres : 
        valeur : int (private)

    Méthode : 
        afficher() : char

    """

    private : 
        int valeur;

    public : 
        //jsp 
        void init(double a, double b){
            x = a;
            y = b;
        }
        void afficher(){
            cout<<x<<"+i"<<y;
        }

        void appliqueEffet(){
            
        }

};
// Classe abstraite de base 

class Case { 
    public:
        virtual char afficher() = 0; 
        virtual int appliqueEffet(int points_de_vie_joueur) = 0;
        virtual ~Case() = default;
};


class Aventurier : public Case {
    private:
        int pv;
        int x, y;
        int inventaire;
    
    public:
        char constafficher(){
            char a = '@';
            return a;
        }

        void deplacer(int nx, int ny){
            // si (x+nx,y+ny) dans grille est différent de MUR => x = x + nx et y = y + ny
            x = x + nx;
            y = y + ny;
        }

        bool estVivant(){
            if (pv > 0) {
                return True;
            }
            else {
                return False;
            }
        }

        void afficherStatut(){
            cout << 'Position : ( ' << x << ' , ' << y << ' )' << endl;
            cout << 'Sante : ' << pv << '/100' << endl;
            cout << 'Inventaire : ' << inventaire << ' tresors' << endl;
        }

};

//Morgane
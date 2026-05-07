#include <iostream>
#include "Donjon.h"
using namespace std;

#ifndef AVENTURIER_H
#define AVENTURIER_H

class Aventurier {
    /* Classe permettant de définir le joueur, ses déplacements, ainsi que la boucle de jeu.

    Paramètres :
        - pv : int
            Points de vie du joueur.
        - x : int
            Position en x du joueur dans le donjon.
        - y : int
            Position en y du joueur dans le donjon.
        - inventaire : int
            Nombre de trésors ramassés par le joueur au cours de la partie.
        - x_precedent : int
            Position en x à l'instant t-1 du joueur dans le donjon.
        - y_precedent : int
            Position en y à l'instant t-1 du joueur dans le donjon.
        - pas_x : int
            déplacement en x du joueur dans le donjon.
        - pas_y : int
            déplacement en y du joueur dans le donjon.
    
    Méthodes :
        - Aventurier()
            Constructeur de la classe Aventurier.
        - ~Aventurier()
            Destructeur de la classe Aventurier.
        - constafficher() : char
            Permet de définir l'affichage du personnage dans la donjon.
        - deplacer(int nx, int ny) : void
            Permet de déplacer le joueur d'un déplacement nx en x et ny en y dans le donjon.
        - estVivant() : bool
            Permet de vérifier que le joueur est toujours en vie (pv > 0) pour définir la condition de fin de jeu.
        - afficherStatut() : void
            Permet l'affichage de l'état du joueur.
        - boucleDeJeu(Donjon& d) : void
            Définit les différentes étapes du jeu et permet de gérer la partie.

        - getPV() : int
            Obtenir les PV du joueur.
        - setPV(int vie) : void
            Modifier les PV du joueur.
        - getInventaire() : int
            Obtenir le nombre de trésors ramassés.
        - setInventaire(int inv) : void
            Modifier le nombre de trésors.
        - getX() : int
            Obtenir la position x du joueur.
        - setX(int posx) : void
            Modifier la position x du joueur.
        - getY() : int
            Obtenir la position y du joueur.
        - setY(int posy) : void
            Modifier la position y du joueur.
        - getXprec() : int
            Obtenir la position x précédente à t-1 du joueur.
        - getYprec() : int
            Obtenir la position y précédente à t-1 du joueur.
        */

    private:
        // etat du joueur
        int pv;
        int x, y;
        int inventaire;

        //permet au joueur de fuir
        int x_precedent, y_precedent;
        
        //stocker le pas selon x et le pas selon y 
        int pas_x, pas_y;
    
    public:
        // Constructeur par défault
        Aventurier(){
           pv = 100;
           x = 0;
           y = 0;
           inventaire = 0; 

           //ajout des positions précédentes du joueur pour permettre au joueur de fuir face au monstre
           x_precedent = 0;
           y_precedent = 0;
           pas_x = 0; 
           pas_y = 0;
        };

        ~Aventurier() = default;

        int getPV() {
            return pv;
        }

        void setPV(int vie){
            pv = vie;
        }

        int getInventaire(){
            return inventaire;
        }

        void setInventaire(int inv){
            inventaire = inv;
        }
        
        int getX(){
            return x;
        }

        void setX(int posx){
            x = posx;
        }

        int getY(){
            return y;
        }

        void setY(int posy){
            y = posy;
        }

        int getXprec(){
            return x_precedent;
        }

        int getYprec(){
            return y_precedent;
        }


        char constafficher(){
            char a = '@';
            return a;
        };

        void deplacer(int nx, int ny){
            x_precedent = x;
            y_precedent = y;
            x = x + nx;
            y = y + ny; 
        };

        bool estVivant(){
            if (pv > 0) {
                return true;
            }
            else {
                return false;
            }
        };

        void afficherStatut(){
            cout << "Position : ( " << x << " , " << y << " )" << endl;
            cout << "Sante : " << pv << "/100" << endl;
            cout << "Inventaire : " << inventaire << " tresors" << endl;
        };

        void boucleDeJeu(Donjon& d){
            int nx=0;
            int ny=0;

            vector<pair<int,int>> chemin;   // pour calcul chemin optimal
            int distance; // pour affichage de la distance à la sortie
            chemin = d.trouverChemin({0,0}, {d.h-1,d.l-1});
            distance = chemin.size()-1;

            // BOUCLE TANT QUE LE JOUEUR EST VIVANT
            while (estVivant() == true){
                
                char direction;

                // APPUIE SUR P POUR AFFICHAGE CHEMIN OPTIMAL
                if (direction == 'p'){

                    // AFFICHAGE DU DONJON ET JOUEUR
                    for(int i = 0; i<d.h; i++){
                        for(int j = 0; j<d.l; j++){
                            if (i == x && j == y) {
                                cout << constafficher();
                            }
                            else {

                                // AFFICHAGE CHEMIN OPTIMAL
                                bool dans_chemin = false;
                                for (int k = 0; k<chemin.size();k++){
                                    if (chemin[k].first == i && chemin[k].second == j){
                                        dans_chemin = true;
                                    }
                                }
                                if (dans_chemin == true){
                                    cout << ".";
                                }
                                else{
                                cout << d.grille[i][j] -> afficher(); 
                                }
                            }
                        };
                    cout << endl;
                    };
                    cout << "" << endl;
                    afficherStatut();
                    cout << "Distance à la sortie : " << distance << " cases" << endl;

                    cin >> direction;
                }


                else {
                    //réinitialisation des pas du joueur à chaque itération : 
                    pas_x = 0; 
                    pas_y = 0; 

                    // LECTURE TOUCHE
                    if (direction == 'z'){

                    //petit changement pour se déplacer uniquement si y a pas un mur sur le chemin
                    pas_x = -1;
                    pas_y = 0;
                    }
                    else if (direction == 's') {
                        pas_x = 1;
                        pas_y = 0;
                    }
                    else if (direction == 'q') {
                        pas_x = 0; 
                        pas_y = -1;
                    }
                    else if (direction == 'd') {
                        pas_x = 0; 
                        pas_y = 1;
                    }
                    
                    nx = x + pas_x;
                    ny = y + pas_y;

                    //on vérifie qu'on fonce pas sur un mur
                    if (nx>=0 && nx<d.h && ny>=0 && ny<d.l && d.grille[x+pas_x][y+pas_y] -> type != TypeCase::Mur) {
                        deplacer(pas_x, pas_y); // on déplace le joueur
                        d.grille[x][y] -> appliqueEffet(*this); //on applique l'effet de la case sur le joueur
                        
                        // calcul du nouveau chemin optimal après déplacement
                        chemin = d.trouverChemin({x,y}, {d.h-1,d.l-1});
                        distance = chemin.size()-1;

                        // remplacement du trésor par un passage après ramassage
                        if (d.grille[nx][ny] -> type == TypeCase::Tresor){
                            d.grille[x][y] = CaseFactory::creerCase(TypeCase::Passage);
                        }
                    }

                    // AFFICHAGE DU DONJON ET JOUEUR
                    for(int i = 0; i<d.h; i++){
                        for(int j = 0; j<d.l; j++){
                            if (i == x && j == y) {
                                cout << constafficher();
                            }
                            else {
                                cout << d.grille[i][j] -> afficher(); 
                            }
                        };
                    cout << endl;
                    };
                    cout << "" << endl;
                    afficherStatut();
                    cout << "Distance à la sortie : " << distance << " cases" << endl;

                    
                    // AFFICHAGE VICTOIRE
                    if (x == d.h-1 && y == d.l-1){
                        cout << "FELICITATIONS !! Vous avez gagné la partie !!" << endl;
                        return;
                    }


                    cin >> direction;
                }
                
            
            }

            // FIN DE PARTIE
            cout << "GAME OVER :(" << endl;
            return;

        };

};

#endif



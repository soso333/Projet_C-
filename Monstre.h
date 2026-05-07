#ifndef MONSTRE_H
#define MONSTRE_H

#include <iostream>
using namespace std;
#include "Aventurier.h"
#include "Case.h"
#include <random>

class Monstre : public Case{

    /* Classe permettant de définir le monstre qu'un joueur peut rencontrer

    Paramètres : 
        valeur : int (private)
        Permet de définir une valeur qui supprime des points de vie à un joueur
        pv : int (private)
        Permet de définir les points de vie du monstre (pour le combat)

    Méthode : 
        init : void 
        Permet d'initiliaser la valeur de l'attaque du monstre

        afficher() : char
        Permet d'afficher la chaîne de caractère représentant le monstre dans le labyrinthe (par +)

        appliqueEffet(Aventurier& aventurier) : void
        Permet d'appliquer l'effet de l'attaque du monstre sur le joeur
        Prends en paramètre l'aventurier lui-même

        fuite() : void 
        Permet de déterminer si le joueur veut fuir ou pas face au monstre

        vaincu() : void
        Permet de dire si le monstre est vaincu ou pas s'il y a combat (s'il fuit pas)
    */

    private : 
        int valeur;
        int pv;
        bool est_fuite = false; 
        bool est_vaincu = false;
        
        //proba random pour l'attaque du monstre, puis pour l'attaque du joueur
        std::default_random_engine de;
        //std::uniform_real_distribution<double> distrib(0.0,1.0); compile pas avec des parenthèses
        std::uniform_real_distribution<double> distrib{0.0,1.0};
        //double proba_attaque_monstre = distrib(de); ;; on les met dans appliqueEffet sinon ça sera la même proba à chaque fois

        std::default_random_engine de2;
        std::uniform_real_distribution<double> distrib2{0.0,1.0};
        //double proba_attaque_joueur = distrib2(de);

        //fin aléatoire; source: https://blog.alphorm.com/les-fonctions-aleatoires-en-c-11


        // adresse du joueur comme ça ça modifie directement sa position
        // en privé car je vais me servir des deux méthodes dans appliqueEffet sinon ça va être compliqué d'utiliser ces fonctions étant donnés qu'elles sont pas définies dans case
        void fuite(Aventurier& aventurier){

            if (est_fuite == true) { 
                aventurier.setX(aventurier.getXprec());
                aventurier.setY(aventurier.getYprec());
            }
        }

        //dialogue pour dire que le combat est fini, pour arrêter le combat on aura qu'à juste plus utiliser applique_effet...
        void vaincu(){

            if (pv <= 0) {
                std::cout << "le monstre a été vaincu" <<std::endl;
            }
        }

    public : 
        Monstre(){
            type = TypeCase::Monstre;
            init();
        };

        void init(int a = 20, int b = 100){
            valeur = a;
            pv = b;
        }

        char afficher()const override{
            char a = 'M';
            return a;
        }

        virtual void appliqueEffet(Aventurier& aventurier){ //en cas de coup par le monstre

            //initialisation des paramètres aléatoires : 
            double proba_attaque_monstre = distrib(de);
            double proba_attaque_joueur = distrib2(de);

            // on propose tout d'abord au joueur s'il veut fuir ou pas : 
            std::cout << "Oh non ! Un monstre est apparu... Souhaitez-vous fuir ?! Y/N" << std::endl;

            //lecture clavier décision jour : 
            char decision; 
            std::cin >> decision;

            if (decision == 'Y' || decision == 'y') {

                est_fuite = true;
                //le joueur retourne alors à la case précédente : 
                this->fuite(aventurier); 
            }

            //if (decision == 'N' || decision == 'n') {
            else {

                std::cout << "Vous engagez le combat avec le monstre !" << std::endl;
                est_fuite = false;

                while(est_vaincu == false && aventurier.getPV() > 0){ //tant que le monstre n'est pas vaincu et que le joueur n'est pas mort, le combat continue

                    //on laisse le choix au joueur d'attaquer ou de fuir à chaque itération : 
                    std::cout << " Souhaitez vous fuir (F) ? ou Souhaitez vous attaquer (A) ? F/A " << std::endl;
                    char decision2; 
                    std::cin >> decision2; 

                    if (decision2 == 'F' || decision2 == 'f') {
                        est_fuite = true;
                        //le joueur retourne alors à la case précédente : 
                        this->fuite(aventurier); 
                        break; //le combat s'arrête
                    }

                    if (decision2 == 'A' || decision2 == 'a') {
                        est_fuite = false;
                    

                        //le monstre attaque le joueur avec une probabilité de 70% de réussite : 
                        if (proba_attaque_monstre <= 0.5) {
                            aventurier.setPV(aventurier.getPV() - valeur); 
                            std::cout << " Vous venez de subir " << valeur << "dégâts de la part du monstre" << std::endl;
                            est_vaincu = false;
                        }

                        else {
                            std::cout << "flop du monstre, aucun dégât subi" << std::endl;
                            est_vaincu = false;
                        }

                        // le joueur attaque le monstre avec une probabilité de 30% : 
                        if (proba_attaque_joueur <= 0.5){
                            pv -= 50; 
                            std::cout << "un coup critique a été donné au monstre" << std::endl;

                            if (pv<=0){
                                est_vaincu = true; 
                                this->vaincu();

                            }
                        }
                        else {
                            std::cout << "Le joueur est fatigué... il a raté son attaque" << std::endl;
                            est_vaincu = false;
                        }
                    }
                }
            }
        }
};

#endif
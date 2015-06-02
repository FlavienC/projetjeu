#ifndef GOBAN_H
#define GOBAN_H

#include <SDL/SDL.h>
#include <vector>
#include "Pawn.h"
#include "../SDL/affichage.h"


using namespace std;


class Goban
{
    private :
        int const m_taille; //nbr de ligne ou de colon
        SDL_Surface **m_ecran;   //l'ecran de jeu
        vector <vector<Pawn*> > m_goban;    //le tableau qui contien les info sur chaque case du goban
    public:
        Goban(int taille, SDL_Surface **ecan);
        void supprPawn (int x, int y);
        bool addPawn (int x, int y, bool couleur);  //retourne true si pas de piece deja sur la case false sinon
        Pawn *getPown (int x, int y);
        int getLiberte (int x, int y);
};

#endif // GOBAN_H

#ifndef PAWN_H
#define PAWN_H

#include "../SDL/affichage.h"


class Pawn
{
    private:
        int const m_x;  //la position du pion en x
        int const m_y;  //la position du pion en y
        int m_couleur; //a quel joueur appartient il
        SDL_Surface *m_ecran;   //l'ecran pour ppouvoir suppr l'image du pion
        int m_liberte; //le nbr de liberté du pion
    public:
        Pawn(int x, int y, bool couleur, SDL_Surface **ecran);
        void suppr ();
        int getX ();
        int getY ();
        bool getColor ();
        int getLiberte ();
};

#endif // PAWN_H

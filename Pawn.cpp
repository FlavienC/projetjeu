#include "Pawn.h"

Pawn :: Pawn (int x, int y, bool couleur, SDL_Surface **ecran) : m_x(x), m_y(y), m_ecran(*ecran)
{
    couleur ? m_couleur = 255 : m_couleur = 0;
    ajoutPiece (m_x , m_y, m_couleur, &(m_ecran));
}

void Pawn :: suppr ()
{
    effacerPiece (&(m_ecran), m_x, m_y);
    delete this;
}

int Pawn :: getX ()
{
    return m_x;
}
int Pawn :: getY ()
{
    return m_y;
}

bool Pawn :: getColor ()
{
    return m_couleur;
}

int Pawn :: getLiberte ()
{
    return m_liberte;
}

#include "Goban.h"

using namespace std;

Goban :: Goban(int const taille, SDL_Surface ** ecran) : m_taille (taille), m_ecran(ecran)
{
    int i, j;
    for (i = 0; i < taille ; i ++)
    {
        m_goban.push_back(vector<Pawn*> (taille));
        for (j = 0; j < taille; j ++)
            m_goban [i][j] = NULL;
    }
    plateau (taille - 1, &(*m_ecran));
}

void Goban :: supprPawn (int x, int y)
{
    if (m_goban [x][y] != NULL)
    {
        (*m_goban[x][y]).suppr();
        m_goban [x][y] = 0;
    }
}

bool Goban :: addPawn (int x, int y, bool couleur) //retourn true si possible et false si impossible
{
    if (m_goban[x][y] == NULL)
    {
        m_goban[x][y] = new Pawn (x,y,couleur,&(*m_ecran));
        return true;
    }
    return false;
}

Pawn *Goban :: getPown (int x, int y)
{
    return m_goban[x][y];
}

int Goban :: getLiberte (int x, int y)
{
    return (*m_goban[x][y]).getLiberte();
}






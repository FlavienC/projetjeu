#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "../SDL/affichage.h"
#include "Goban.h"
#include "Chain.h"


class Player
{
    private:
        bool m_couleur, m_passer;
        int m_territoire, m_taille, m_nbListe;
        vector <Chain *> liste;
    public:
        Player(bool couleur, int taille);
        void jouer (Goban &goban);

};

#endif // PLAYER_H

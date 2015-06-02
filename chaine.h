#ifndef CHAINE_H
#define CHAINE_H

#include <vector>
#include "Pawn.h"

class Chaine
{
    private:
        Pawn **m_pawn;
        Chaine *succ;
    public:
        Chaine();
        bool estEgale (Chaine const&a)const;
};

bool operator == (Chaine const&a, Chaine const&b);

#endif // CHAINE_H

#include "chaine.h"

Chaine::Chaine() : m_pawn(0), succ(0) {}


bool Chaine :: estEgale (Chaine const& a)const
{
    if (*(a->pawn) == NULL)
        return false;
    if (*(a->pawn) == this->m_pawn)
        return true;
    return this.estEgale(a.succ);
}


bool operator == (Chaine const&a, Chaine const&b)
{
    return a.estEgale(b);
}

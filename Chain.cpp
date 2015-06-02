#include "Chain.h"

#include <stdlib.h>

int nbElements (Chain c)
{
    if (c == NULL)
        return 0;
    return nbElements(c->succ) + 1;
}

Chain creeMaillon (int x, int y)
{
    Chain c = new Maillon;
    c->x = x;
    c->y = y;
    c->succ = NULL;
    return c;
}

bool estIlDansLaChaine (Chain tete, Pawn piece)
{
    if (tete == NULL)
        return false;
    if ( tete->x == piece.getX() && tete->y == piece.getY())
        return true;
    return estIlDansLaChaine((tete->succ), piece);
}

void addPawn (Chain *tete, Pawn piece)
{
    if (*tete == NULL)
        *tete = creeMaillon(piece.getX(), piece.getY());
    addPawn(&((*tete)->succ), piece);
}

void supprChain(Chain *c, Goban& goban)
{
    if (*c == NULL)
        return;
    supprChain (&((*c)->succ), goban);
    goban.supprPawn((*c)->x, (*c)->y);
    delete *c;
}

int getLibetrer (Chain c, Chain *lib, Goban & goban, int taille)
{
    if (c == NULL)
        return nbElements(*lib);
    int liberteDeC = goban.getLiberte(c->x, c->y);
    if (liberteDeC == 0)
        return getLibetrer (c->succ, &(*lib), goban, taille);
    if (c->x != taille - 1)
    {
        Pawn *voisin (goban.getPown(c->x + 1, c->y));
        if (voisin == NULL && estIlDansLaChaine(*lib, *voisin) != false)
            addPawn(&(*lib), *voisin);
        else
            return getLibetrer (c->succ, &(*lib), goban, taille);
    }
    if (c->x != 0)
    {
        Pawn *voisin (goban.getPown(c->x - 1, c->y));
        if (voisin == NULL && estIlDansLaChaine(*lib, *voisin) != false)
            addPawn(&(*lib), *voisin);
        else
            return getLibetrer (c->succ, &(*lib), goban, taille);
    }
    if (c->y != 0)
    {
        Pawn *voisin (goban.getPown(c->x, c->y - 1));
        if (voisin == NULL && estIlDansLaChaine(*lib, *voisin) != false)
            addPawn(&(*lib), *voisin);
        else
            return getLibetrer (c->succ, &(*lib), goban, taille);
    }
    if (c->y != taille)
    {
        Pawn *voisin (goban.getPown(c->x, c->y + 1));
        if (voisin == NULL && estIlDansLaChaine(*lib, *voisin) != false)
            addPawn(&(*lib), *voisin);
        else
            return getLibetrer (c->succ, &(*lib), goban, taille);
    }
    return getLibetrer (c->succ, &(*lib), goban, taille);
}

void concatene (Chain *a, Chain *b)
{
    if (*a == NULL)
        *a = *b;
    else
        concatene (&(*a)->succ, &(*b)->succ);
}







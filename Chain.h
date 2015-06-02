#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include "Pawn.h"
#include "Goban.h"

typedef struct Maillon
{
    int x, y, lib;
    Maillon *succ;
}Maillon;

typedef struct Maillon * Chain;

bool estIlDansLaChaine (Chain tete, Pawn piece);
void addPawn (Chain *tete, Pawn piece);
void supprChain (Chain c, Goban& goban);
int getLibetrer (Chain c, Chain *lib, Goban &goban);
void concatene (Chain *a, Chain *b);

#endif // CHAIN_H

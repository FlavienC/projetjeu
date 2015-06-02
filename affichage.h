#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <math.h>

void pause ();
void plateau(int nbCase, SDL_Surface **ecran);
void effacerPiece(SDL_Surface **ecran, int x, int y);
void ligneHorizontale(int x, int y, int largeur, bool boolCoul, SDL_Surface **ecran);
void ajoutPiece(int cx, int cy, int coul, SDL_Surface **ecran);
void clic (int *x, int *y, int nbLigne);
#endif // AFFICHAGE_H_INCLUDED

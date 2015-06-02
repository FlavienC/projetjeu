#include <SDL/SDL.h>
#include <iostream>
#include "../SDL/affichage.h"
#include "Pawn.h"
#include "Player.h"
#include "Goban.h"

using namespace std;

int main (int argc, char** argv )
{
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL");
        exit(EXIT_FAILURE);
    }


    int i = 1;
    SDL_Surface *ecran = NULL;
    int nbLigne = 9;
    //cin >> nbLigne;
    Goban tableDeJeu(nbLigne, &ecran);
    Player blanc (1, nbLigne), noir(0, nbLigne);

    while(i){
        if ((i+1) % 2 == 0)
            noir.jouer(tableDeJeu);
        else
            blanc.jouer(tableDeJeu);
        //clic(&x,&y,nbLigne);
        //tableDeJeu.supprPawn(x,y);
        i ++;
    }

    pause();
    SDL_Quit();
    return 0;
}

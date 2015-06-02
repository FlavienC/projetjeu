#include "affichage.h"

int aSupr = 0;
int const bord = 25;
int const ecart = 40;

void pause ()
{
    int continuer=1;
    SDL_Event event;
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer=0;
                break;
            default :
                break;
            }
        }
    }
}


void plateau(int nbCase, SDL_Surface **ecran)
{
    *ecran = NULL;
    SDL_Surface *lignesV = NULL, *lignesH = NULL;

    int const tailleEcran = nbCase * ecart + 2 * bord;
    int i;

    SDL_Rect position1, position2;

    //tailles des surface
    *ecran = SDL_SetVideoMode(tailleEcran, tailleEcran, 32, SDL_HWSURFACE); //l'ecran
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    lignesV = SDL_CreateRGBSurface(SDL_HWSURFACE, 1, tailleEcran - 2 * bord, 32,0,0,0,0); //les lignes
    lignesH = SDL_CreateRGBSurface(SDL_HWSURFACE, tailleEcran - 2 * bord, 1, 32,0,0,0,0);

    //nom de l'ecran
    SDL_WM_SetCaption("Jeu De Go", NULL);

    //couleurs des surfac
    SDL_FillRect(*ecran,NULL,SDL_MapRGB((*ecran)->format,244,215,153));
    SDL_FillRect(lignesV,NULL, SDL_MapRGB(lignesV->format,0,0,0));
    SDL_FillRect(lignesH,NULL, SDL_MapRGB(lignesH->format,0,0,0));

    //placement des lignes
    for (i = 0; i <= nbCase ; i ++)
    {
        position1.x= bord + i * ecart;
        position1.y= bord;

        position2.x= bord;
        position2.y= bord + i * ecart;

        SDL_BlitSurface(lignesV, NULL, *ecran, &position1);
        SDL_BlitSurface(lignesH, NULL, *ecran, &position2);
    }


    //mise à jour de l'ecran
    SDL_Flip(*ecran);
    SDL_FreeSurface(lignesV);
    SDL_FreeSurface(lignesH);
    //pause();
}

void effacerPiece(SDL_Surface **ecran, int x, int y)
{
    SDL_Surface *coinHG = NULL, *ligneH = NULL, *ligneV = NULL;
    SDL_Rect pos;
    int nbLigne = (((*ecran)->h - 2*bord) / ecart) + 1;

    //tailles des surfaces
    coinHG = SDL_CreateRGBSurface(SDL_HWSURFACE,ecart,ecart, 32,0,0,0,0);
    ligneH = SDL_CreateRGBSurface(SDL_HWSURFACE,ecart/2, 1, 32,0,0,0,0);
    ligneV = SDL_CreateRGBSurface(SDL_HWSURFACE,1, ecart/2, 32,0,0,0,0);

    //couleurs des surfaces
    SDL_FillRect(coinHG, NULL, SDL_MapRGB(coinHG->format,244,215,153));
    SDL_FillRect(ligneH, NULL, SDL_MapRGB(ligneH->format, 0, 0, 0));
    SDL_FillRect(ligneV, NULL, SDL_MapRGB(ligneV->format, 0, 0, 0));

    //placement des surfaces
    if (x != 0)//si on est tout a gauche
    {
        pos.x = 0;
        pos.y = ecart/2;
        SDL_BlitSurface(ligneH, NULL, coinHG, &pos);
    }
    if (x != nbLigne - 1)//si on est tout a droite (-1 car on commence a 0)
    {
        pos.x = ecart/2;
        pos.y = ecart/2;
        SDL_BlitSurface(ligneH, NULL, coinHG, &pos);
    }
    if (y != 0)//si on est tout en haut
    {
        pos.x = ecart/2;
        pos.y = 0;
        SDL_BlitSurface(ligneV, NULL, coinHG, &pos);
    }
    if (y != nbLigne - 1)//si on est tout en bas (-1 car on commence a 0)
    {
        pos.x = ecart/2;
        pos.y = ecart/2;
        SDL_BlitSurface(ligneV, NULL, coinHG, &pos);
    }

    //on laise le "- ecart/2 + bord" au cas ou l'on en change l'un d'entre eux
    pos.x = x*ecart - ecart/2 + bord;   //oui "- ecart/2 + bord" = 0 mais seulement quand ecart = 50 et bord = 25
    pos.y = y*ecart - ecart/2 + bord;
    SDL_BlitSurface(coinHG, NULL, *ecran, &pos);

    //mise a jour
    SDL_Flip(*ecran);
    SDL_free(ligneH);
    SDL_free(ligneV);
    SDL_free(coinHG);
}

void ligneHorizontale(int x, int y, int largeur, int coul, SDL_Surface **ecran)
{

    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_Surface *ligneH = SDL_CreateRGBSurface(SDL_HWSURFACE,largeur, 1, 32, 0,0,0,0);
    SDL_FillRect(ligneH, NULL, SDL_MapRGB((*ecran)->format, coul, coul, coul));
    SDL_BlitSurface(ligneH, NULL, *ecran, &pos);
    SDL_Flip(*ecran);
    SDL_free(ligneH);
}

void ajoutPiece(int cx, int cy, int coul, SDL_Surface **ecran)
{
    int rayon = ecart/2 - 1;
    int d, y, x;
    cx = bord + ecart * cx;
    cy = bord + ecart * cy;
    d = 3 - (2 * rayon);
    x = 0;
    y = rayon;
           //                         fprintf(stderr, "2\n");
    while (y >= x)
    {
          //                          fprintf(stderr, "3\n");
        ligneHorizontale(cx - x, cy - y, 2 * x + 1, coul, &(*ecran));
        ligneHorizontale(cx - x, cy + y, 2 * x + 1, coul, &(*ecran));
        ligneHorizontale(cx - y, cy - x, 2 * y + 1, coul, &(*ecran));
        ligneHorizontale(cx - y, cy + x, 2 * y + 1, coul, &(*ecran));
        if (d < 0)
            d = d + (4 * x) + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
      //                              fprintf(stderr, "\n4");
    }
     //                               fprintf(stderr, "\n5");
}


void clic (int *x, int *y, int nbLigne)
{
    *x = *y = -1;
    SDL_Event event;
    int pixX, pixY;
    int i = 0;
    bool continuer = true;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                continuer = false;
                break;
            case SDL_MOUSEBUTTONUP: // test du clic souris
                switch (event.button.button)
                {
                    case SDL_BUTTON_LEFT:   // test du clic gauche
                        pixX = event.button.x - bord;   //position du clic en x - le bord
                        pixY = event.button.y - bord;   //position du clic en Y _ le bord
                        i = 0;// conteur initialiser
                        //choix de deux boucl distiencte par soucie de simpliciter
                        while (i < nbLigne && (pixX > 10 || pixX < -10))
                        {
                            pixX = pixX - ecart;
                            i ++;
                        }
                        if (i != nbLigne)
                        {
                            *x = i;
                            i = 0;
                            while (i < nbLigne && (pixY > 10 || pixY < -10))
                            {
                                pixY = pixY - ecart;
                                i ++;
                            }
                            if (i != nbLigne)
                            {
                                continuer = false;
                                *y = i;
                            }
                        }
                        break;
                    default :
                        break;
                }
                break;
            default:
                break;
        }
    }
}









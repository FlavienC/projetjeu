#include "Player.h"

Player::Player(bool couleur, int taille)
: m_couleur(couleur), m_passer(false), m_territoire(0), m_taille(taille), m_nbListe(0){}

void Player :: jouer (Goban &goban)
{
    int x, y, i;
    bool aUnVoisin = false, listeTrouver;
    clic (&x, &y, m_taille);
    while (goban.addPawn(x,y,m_couleur) != true){clic (&x, &y, m_taille);}  //si on clic sur une case deja occuper
    if (x != m_taille - 1 && goban.getPown(x+1,y) != NULL && (*goban.getPown(x+1,y)).getColor() == m_couleur)   // si il a un voisin a droite
    {
        i = 0;
        listeTrouver = false;
        while (i <= m_nbListe && listeTrouver == false) //tan qu'on a pas fait toute les liste ou que l'on a pas trouver a liste dans la quelle est la piece de droite
        {
            if (estIlDansLaChaine(*liste[i], (*goban.getPown(x+1, y))) == true)
            {
                addPawn (&(*liste[i]), *goban.getPown(x,y));    //on ajoute la nouvelle piece dans la liste de son voisin
                aUnVoisin = true;
            }
            i++;
        }
    }
    if (x != 0 && goban.getPown(x-1, y) != NULL && (*goban.getPown(x-1,y)).getColor() == m_couleur) // si il a un voisin a gauche
    {
        if (aUnVoisin == true)  // si la nouvelle piece appartiens deja à une liste (a deja un voisin detecter)
        {
            if (estIlDansLaChaine(*liste[m_nbListe], (*goban.getPown(x-1, y))) == false)//la list a la quel appartient la nouvelle piece est elle la mm que la liste de la piece de gauche
            {
                i = 0;
                listeTrouver = false;
                while (i <= m_nbListe && listeTrouver == false) //tan qu'on a pas fait toute les liste ou que l'on a pas trouver a liste dans la quelle est la piece des gauche
                {
                    if (estIlDansLaChaine(*liste[i], (*goban.getPown(x-1, y))) == true) //on teste pour savoir si cette liste est celle dans la quelle il y a la piece de gauche
                    {
                        concatene(&(*liste[m_nbListe]), &(*liste[i]));
                        listeTrouver = true;
                        m_nbListe --;
                    }
                    i ++;
                }
            }
        }
        else    // si la nouvelle piece n'appartiens deja a une liste
        {
            i = 0;
            listeTrouver = false;
            while (i <= m_nbListe && listeTrouver == false) //tan qu'on a pas fait toute les liste ou que l'on a pas trouver a liste dans la quelle est la piece de gauche
            {
                if (estIlDansLaChaine(*liste[i], (*goban.getPown(x-1, y))) == true)
                {
                    addPawn (&(*liste[i]), *goban.getPown(x,y));    //on ajoute la nouvelle piece dans la liste de son voisin
                    aUnVoisin = true;
                }
                i++;
            }
        }
    }






    if (y != 0 && goban.getPown(x, y-1) != NULL && (*goban.getPown(x,y-1)).getColor() == m_couleur) // si il a un voisin a gauche
    {
        if (aUnVoisin == true)  // si la nouvelle piece appartiens deja à une liste (a deja un voisin detecter)
        {
            if (estIlDansLaChaine(*liste[m_nbListe], (*goban.getPown(x, y-1))) == false)//la list a la quel appartient la nouvelle piece est elle la mm que la liste de la piece de gauche
            {
                i = 0;
                listeTrouver = false;
                while (i <= m_nbListe && listeTrouver == false) //tan qu'on a pas fait toute les liste ou que l'on a pas trouver a liste dans la quelle est la piece des gauche
                {
                    if (estIlDansLaChaine(*liste[i], (*goban.getPown(x, y-1))) == true) //on teste pour savoir si cette liste est celle dans la quelle il y a la piece de gauche
                    {
                        concatene(&(*liste[m_nbListe]), &(*liste[i]));
                        listeTrouver = true;
                        m_nbListe --;
                    }
                    i ++;
                }
            }
        }
        else    // si la nouvelle piece n'appartiens deja a une liste
        {
            i = 0;
            listeTrouver = false;
            while (i <= m_nbListe && listeTrouver == false) //tan qu'on a pas fait toute les liste ou que l'on a pas trouver a liste dans la quelle est la piece de gauche
            {
                if (estIlDansLaChaine(*liste[i], (*goban.getPown(x, y-1))) == true)
                {
                    addPawn (&(*liste[i]), *goban.getPown(x,y));    //on ajoute la nouvelle piece dans la liste de son voisin
                    aUnVoisin = true;
                }
                i++;
            }
        }
    }
}

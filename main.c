#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#include "headers/plateau.h"
#include "headers/jeu.h"
#include "headers/interface.h"

int main(void)
{
    srand(time(NULL));

    joueur liste_joueur[4];
    int liste_couleurs[4];
    //init des couleurs à 0 de base pour les 4 joueurs
    for(int i=0; i<4;i++)
    {
      liste_joueur[i].couleur = 0;
    }


    int nb_joueur = init_partie(liste_joueur, liste_couleurs);

    // Place les chevaux dans les écuries
    placer_chevaux_joueurs(liste_joueur);
    init_chevaux(liste_joueur);

    //Initialisation du plateau de Jeu.
    char plateau[15][15] = {
                      {'k','k','k','k','k','k','7','7','7','c','c','c','c','c','c'},
                      {'k','0','0','0','0','k','7','1','7','c','0','0','0','0','c'},
                      {'k','0','0','0','0','k','7','2','7','c','0','0','0','0','c'},
                      {'k','0','0','0','0','k','7','3','7','c','0','0','0','0','c'},
                      {'k','0','0','0','0','k','7','4','7','c','0','0','0','0','c'},
                      {'k','k','k','k','k','k','7','5','7','c','c','c','c','c','c'},
                      {'7','7','7','7','7','7','7','6','7','7','7','7','7','7','7'},
                      {'7','1','2','3','4','5','6','8','6','5','4','3','2','1','7'},
                      {'7','7','7','7','7','7','7','6','7','7','7','7','7','7','7'},
                      {'w','w','w','w','w','w','7','5','7','s','s','s','s','s','s'},
                      {'w','0','0','0','0','w','7','4','7','s','0','0','0','0','s'},
                      {'w','0','0','0','0','w','7','3','7','s','0','0','0','0','s'},
                      {'w','0','0','0','0','w','7','2','7','s','0','0','0','0','s'},
                      {'w','0','0','0','0','w','7','1','7','s','0','0','0','0','s'},
                      {'w','w','w','w','w','w','7','7','7','s','s','s','s','s','s'}
                    };

     // Update le plateau avec les chevaux dans les écuries.
     update(plateau, liste_joueur);
     // Affiche le plateau
     refresh(liste_joueur, plateau);
    printf("\n\n");
    jeu(liste_joueur, nb_joueur,liste_couleurs, plateau);

  return 0;
}

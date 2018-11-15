#include <stdio.h>
#include <stdlib.h>
#include "headers/plateau.h"// Place les chevaux dans les écuries (ne marche pas encore)
  placer_chevaux_joueurs(liste_joueur);
  // Affiche le plateau (ne marche pas encore)
  refresh(plateau_jeu);


/*int update_plateau(int size, char plateau[size][size], coord_x, coord_y, joueur, cheval, etc..){ // fonction qui rafraichira le plateau en fonction des nouvelles coords, etc...

printf("test");
}*/

// TODO: Créer une fonction qui regarde les coords de tous les chevaux de chaque joueurs et modifie les valeurs des cases du plateau
void update(char plateau[15][15], liste_joueur[4]) {
    for(int i = 0; i < 4; i++) {
        // Code here
    }
}

// TODO: Créer une fonction qui affiche le plateau et toutes les modifs qui ont eu lieu
void refresh(char plateau[15][15]) {
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
        printf(" %c ", plateau[i][j]);
    }
    printf("\n");
  }
}

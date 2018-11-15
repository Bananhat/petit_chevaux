#include <stdio.h>
#include <stdlib.h>
#include "headers/plateau.h"// Place les chevaux dans les écuries (ne marche pas encore)

// Update les positions des chevaux sur le plateau
void update(char plateau[15][15], joueur liste_joueur[4]) {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      // TODO: ajouter la couleur de chaque joueur pour chaque cheval
      plateau[liste_joueur[i].liste_chevaux[j].case_x][liste_joueur[i].liste_chevaux[j].case_y] = 'W';
    }
  }
}

// Affiche le plateau
void refresh(char plateau[15][15]) {
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
        printf(" %c ", plateau[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

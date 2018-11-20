#include <stdio.h>
#include <stdlib.h>
#include "headers/plateau.h"// Place les chevaux dans les écuries (ne marche pas encore)

// Couleurs pour la console
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

// Update les positions des chevaux sur le plateau
void update(char plateau[][15], joueur liste_joueur[4]) {
  // (Peut être optimisé pour ne boucler que sur le nombre précis de joueurs et donc plus besoin de test avant de bouger les chevaux)
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      // Si les joueurs sont actifs (léger bug pour cette condition qui laisse parfois passer à revoir)
      if (liste_joueur[i].couleur) {
        plateau[liste_joueur[i].liste_chevaux[j].case_x][liste_joueur[i].liste_chevaux[j].case_y] = liste_joueur[i].couleur;
      }
    }
  }
}

// Affiche le plateau
void refresh(char plateau[15][15]) {
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
        if (plateau[i][j] == 'r') {
          printf((RED" %c "RESET),plateau[i][j]);
        }
        else if (plateau[i][j] == 'j') {
          printf((YELLOW" %c "RESET),plateau[i][j]);
        }
        else if (plateau[i][j] == 'b') {
          printf((BLUE" %c "RESET),plateau[i][j]);
        }
        else if (plateau[i][j] == 'v') {
          printf((GREEN" %c "RESET),plateau[i][j]);
        }
        else {
          printf(" %c ", plateau[i][j]);
        }
    }
    printf("\n");
  }
  printf("\n\n");
}

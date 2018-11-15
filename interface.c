#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/joueur.h"

#include "headers/interface.h"

void afficher_plateau(int size, char plateau[size][size])
{
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
        printf(" %c ", plateau[i][j]);
    }
    printf("\n");
  }
}

void init_partie(joueur* liste_joueur) {
  int nb_joueurs;
  char couleur_test;
  printf("Entrez le nombre de joueur (minimum 2) :");
  scanf("%d", &nb_joueurs);

  while (getchar() != '\n');

  for(int i = 0; i < nb_joueurs; i++) {
    do {
    printf("Choisissez votre couleur: \n");
    printf("Rouge(r), Bleu(b), Vert(v), Jaune(j)");
    scanf("%c", &couleur_test);
    if (couleur_test == 'r' || couleur_test == 'v' || couleur_test == 'b' || couleur_test  == 'j'){
      liste_joueur[i].couleur = couleur_test;
    }

  } while(couleur_test != 'r' || couleur_test != 'v' || couleur_test != 'b' || couleur_test != 'j');

    printf("Entrez votre nom : \n");
    scanf("%s", liste_joueur[i].nom);
  }

}

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

void init_partie() {
  
  joueur liste_joueur[4];
  int nb_joueurs;
  char couleur;
  char nom[15];

  printf("Entrez le nombre de joueur (minimum 2) :");
  scanf("%d", &nb_joueurs);

  while (getchar() != '\n');

  for(int i = 0; i < nb_joueurs; i++) {
    do {
    printf("Choisissez votre couleur: \n");
    printf("Rouge(r), Bleu(b), Vert(v), Jaune(j)");
    scanf("%c", &couleur);
  } while(couleur != 'r' || couleur != 'v' || couleur != 'b' || couleur != 'j');

    printf("Entrez votre nom : \n");
    scanf("%s", nom);

    joueur nouveau_joueur;
    nouveau_joueur.couleur = couleur;
    strcpy(nouveau_joueur.nom, nom);
    liste_joueur[i] = nouveau_joueur;
  }

}

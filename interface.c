#include<stdio.h>
#include <stdlib.h>
#include "joueur.h"

void afficher_plateau(int size, char plateau[size][size]) {
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
        printf("%c ", plateau[i][j]);
    }
    printf("\n");
  }
}

void init_partie() {
  liste_joueur[4];
  int nb_joueurs;
  char couleur, nom[15];
  printf("Entrez le nombre de joueur (minimum 2) :")
  scanf("&nb_joueurs");

  for (int i = 0; i < nb_joueurs; i++) {
    printf("Choisissez votre couleur:\n");
    printf("Rouge(r), Bleu(b), Vert(v), Jaune(j)");
    scanf("%c", &couleur);
    printf("Entrez votre nom");
    scanf("%s", &nom)
    joueur nouveau_joueur;
    nouveau_joueur.couleur = couleur;
    strcpy(nouveau_joueur.nom, nom);
    liste_joueur[i] = nouveau_joueur;
  }


}

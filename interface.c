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
  char couleur_use[4];
  int deja_utiliser;

  printf("Entrez le nombre de joueur (minimum 2) : ");
  scanf("%d", &nb_joueurs);

  while (getchar() != '\n');

  for(int i = 0; i < nb_joueurs; i++) {
    printf("\n-------------------------------------------------------\n");
    do {
      deja_utiliser =0;
    printf("Choisissez votre couleur ( Rouge(r), Bleu(b), Vert(v), Jaune(j) ): ");
    scanf("%c", &couleur_test);
    while(getchar() != '\n');

    for(int i=0; i<4; i++){
      if(couleur_use[i] == couleur_test){
        deja_utiliser = 1;
      }
    }

    if ((couleur_test == 'r' || couleur_test == 'v' || couleur_test == 'b' || couleur_test  == 'j') && deja_utiliser==0){
      liste_joueur[i].couleur = couleur_test;
      couleur_use[i] = couleur_test;
    }
    else{
      if(deja_utiliser == 1){
        printf("Cette couleur est déjà utilise..\n");
      }
      else{
        printf("Ce n'est pas une couleur propose !!\ns");
      }
    }
  } while( (couleur_test != 'r' && couleur_test != 'v' && couleur_test != 'b' && couleur_test != 'j') || deja_utiliser==1);

    printf("Entrez votre nom : ");
    scanf("%s", liste_joueur[i].nom);
    while(getchar() != '\n');
  }
  printf("\n----------------------LA PARTIE COMMENCE-----------------------\n");

}

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/joueur.h"
#include "headers/interface.h"



int init_partie(joueur* liste_joueur) {
  int nb_joueurs;
  char couleur_test;
  char couleur_use[4];
  int deja_utiliser;
  couleur_enum e_couleur;

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
      if (couleur_test == 'j'){
        e_couleur = JAUNE;

      }else if (couleur_test == 'r'){
        e_couleur = ROUGE;

      }else if (couleur_test == 'b'){
        e_couleur = BLEU;

      }else if (couleur_test == 'v'){
        e_couleur = VERT;

      }
      liste_joueur[e_couleur].couleur = couleur_test;
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
  return nb_joueurs;
}

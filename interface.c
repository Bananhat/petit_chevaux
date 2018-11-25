#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/plateau.h"
#include "headers/interface.h"




int init_partie(joueur liste_joueur[], int liste_couleurs[]) {
  int nb_joueurs;
  char couleur_test;
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

    for(int i=0; i<4; i++)
    {
      if(liste_joueur[i].couleur == couleur_test)
      {
        deja_utiliser = 1;
      }
    }

    if ((couleur_test == 'r' || couleur_test == 'v' || couleur_test == 'b' || couleur_test  == 'j') && deja_utiliser==0){
      if (couleur_test == 'j')
      {
        e_couleur = JAUNE;

      }
      else if (couleur_test == 'r')
      {
        e_couleur = ROUGE;

      }
      else if (couleur_test == 'b')
      {
        e_couleur = BLEU;

      }
      else if (couleur_test == 'v')
      {
        e_couleur = VERT;

      }
      liste_joueur[e_couleur].couleur = couleur_test;
      liste_couleurs[i] = e_couleur;
    }
    else
    {
      if(deja_utiliser)
      {
        printf("Cette couleur est déjà utilise..\n");
      }
      else
      {
        printf("Ce n'est pas une couleur propose !!\ns");
      }
    }
  } while( (couleur_test != 'r' && couleur_test != 'v' && couleur_test != 'b' && couleur_test != 'j') || deja_utiliser==1);
/*
    printf("Entrez votre nom : ");
    scanf("%s", liste_joueur[e_couleur].nom);*/
    //while(getchar() != '\n');
  }
  printf("\n----------------------LA PARTIE COMMENCE-----------------------\n");
  return nb_joueurs;
}

// Fonctions interface joueur-jeu
int joueur_valide_deplacement(char plateau[][15], joueur liste_joueur[])
{
		char choix;
		int choix_return = 0;
    // Update le plateau avec les chevaux dans les écuries.
    update(plateau, liste_joueur);
    // Affiche le plateau
    refresh(liste_joueur, plateau);
		printf("Voici votre position apres un deplacement ? \n Etes vous sur de vouloir vous deplacer (o/n) : ");
		scanf("%c", &choix);
		if (choix == 'o')
		{
			choix_return = 1;
		}
		return choix_return;
}

int jouer_valide_numeroCheval(joueur * p_j)
{
  int n_cheval;
  do
  {
    printf("Le quel voulez vous deplacer ? : (1,2,3,4)");
    scanf("%d", &n_cheval);
    while(getchar() != '\n');
  } while(p_j->liste_chevaux[n_cheval-1].actif != 1 || n_cheval>4);
  return n_cheval;
}

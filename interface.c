#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/plateau.h"
#include "headers/sauvegarde.h"
#include "headers/interface.h"

void trie_tab( int tab[], int nb_joueur)
{
  int tmp=0;

  for(int i = 0; i < nb_joueur; i++)          //On veut remplir la case i du tableau
    {
      for(int j= i+1; j<nb_joueur; j++)    //On vérifie s'il n'y a pas de nombre inférieur
        {                                //Dans les cases suivantes
          if(tab[j] < tab[i])
            {
              tmp = tab[i];              //Si c'est le cas on intervertit les cases
              tab[i] = tab[j];
              tab[j] = tmp;
            }
        }
    }
}

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
    printf("Choisissez votre couleur ( Jaune(j), Bleu(b), Rouge(r), Vert(v) ): ");
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
  trie_tab(liste_couleurs, nb_joueurs);
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
    else if(choix=='s'){
      choix_return=2;
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

int joueur_valide_cheval_sortir(joueur p_joueur)
{
int n_cheval;
do
{
  printf("Quel numero de cheval ? :");
  scanf("%d", &n_cheval);
  while(getchar()!='\n');
} while(p_joueur.liste_chevaux[n_cheval-1].actif == 1 || n_cheval > 4);
return n_cheval;
}

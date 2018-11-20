#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/plateau.h"
#include "headers/jeu.h"
#include "headers/interface.h"

int lancer_de()
{
  int valeur_d = rand()%7-1 +1;
  return valeur_d;
}


void jeu (joueur *liste_joueur, int nb_joueur)
{
  int n_joueur=rand()%nb_joueur +1,n_tour=1, val_D;
  int valide;
  int n_cheval;
  char reponse;

  /*

  cheval j1 {case_x, case_y, 1, case_debut_x, case_debut_y, 'j', 'a'}
  cheval j2 {case_x, case_y, 2, case_debut_x, case_debut_y, 'j', 'b'}
  cheval j3 {}
  cheval j4 {}
  init_chevaux(liste_joueur, &j1, &j2, &j3, &j4); //ajoute les chevaux dans la main du joueur
  cheval r1 {}
  cheval r2 {}
  cheval r3 {}
  cheval r4 {}
  init_chevaux(liste_joueur, &r1, &r2, &r3, &r4); //ajoute les chevaux dans la main du joueur
  cheval b1 {}
  cheval b2 {}
  cheval b3 {}
  cheval b4 {}
init_chevaux(liste_joueur, &b1, &b2, &b3, &b4); //ajoute les chevaux dans la main du joueur
  cheval v1 {}
  cheval v2 {}
  cheval v3 {}
  cheval v4 {}
  init_chevaux(liste_joueur, &v1, &v2, &v3, &v4); //ajoute les chevaux dans la main du joueur 7

  */

// fonction pour ajouter un cheval a la liste active et le sortir coder par arthur

  char plateau[15][15] = {
                    {'0','0','0','0','0','0','7','7','7','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','7','1','7','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','7','2','7','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','7','3','7','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','7','4','7','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','7','5','7','0','0','0','0','0','0'},
                    {'7','7','7','7','7','7','7','6','7','7','7','7','7','7','7'},
                    {'7','1','2','3','4','5','6','8','6','5','4','3','2','1','7'},
                    {'7','7','7','7','7','7','7','6','7','7','7','7','7','7','7'},
                    {'0','0','0','0','0','0','7','5','7','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','7','4','7','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','7','3','7','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','7','2','7','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','7','1','7','0','0','0','0','0','0'},
                    {'0','0','0','0','0','0','7','7','7','0','0','0','0','0','0'}
                  };


   // Place les chevaux dans les écuries
   placer_chevaux_joueurs(liste_joueur);
   // Update le plateau avec les chevaux dans les écuries.
   update(plateau, liste_joueur);
   // Affiche le plateau
   refresh(plateau);

    printf("LE JOUEUR NUMERO %d COMMENCE \n", n_joueur);

    joueur joueur_courant = liste_joueur[n_joueur];

     while(/*nb_chevaux(&liste_joueur[0]) && nb_chevaux(&liste_joueur[1]) && nb_chevaux(&liste_joueur[2]) && nb_chevaux(&liste_joueur[3]) */ reponse != 's')
    { // boucle principale du jeu;
      val_D = lancer_de();
      printf("Le joueur %d a fais un %d\n", n_joueur, val_D);

      if(nb_chevaux(&joueur_courant) == 0)
    /* && chevaux_numerote(&joueur_courant) == 0*/ // si le joueur qui doit jouer n'a aucun cheval sur le plateau ou sur les cases numerotées */
      {
        if(val_D == 6)
        {
          printf("Voulez vous sortir un nouveau cheval ? (o/n) : ");
          scanf("%c", &reponse);
          while(getchar() != '\n'); // vide le cache
          if(reponse == 'o')
          {
          sortir_chevaux(&n_joueur, &joueur_courant);
          }
          else
          {
            printf("Alors vous passez votre tour");
          }
          // Update le plateau avec les chevaux dans les écuries.
          update(plateau, liste_joueur);
          // Affiche le plateau
          refresh(plateau);
        }
        else
        {
          printf("Dommage.. Vous passez votre tour ! \n");
        }

      }
      else
      {

        if(val_D == 6) //si le joueur fait un 6
        {
            n_joueur-=1; // rejoueras
            printf("Voulez vous sortir un nouveau cheval ? (o/n) : ");
            scanf("%c", &reponse);
            while(getchar() != '\n'); // vide le cache
            if(reponse == 'o')
              {
              sortir_chevaux(&n_joueur, &joueur_courant);

              }
            else // si il ne veut pas sortir de cheval, il se deplace donc..
              {
                deplacement_test(plateau, &joueur_courant, val_D);
              }
        }
        else // si le joueur fait autre chose que 6 il ne peut que se deplacer ou non en fonction de si ila  le droit (deplacement_test())
        {
              // fonction deplacement et conditions..
        }

      }

      n_tour+=1;
      n_joueur = (n_joueur)%nb_joueur +1;
      joueur_courant = liste_joueur[n_joueur];
      printf("\nAu tour du joueur %d \n",n_joueur);

  }

}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/jeu.h"
#include "headers/joueur.h"
#include "headers/plateau.h"
#include "headers/interface.h"


int lancer_de()
{
  int valeur_d = rand()%7-1 +1
  return valeur_d;
}


void jeu (joueur *liste_joueur)
{
  int n_joueur=1+rand()%4,n_tour=1;
  int valide;
  int n_cheval;

/*  cheval j1 {}
  cheval j2 {}
  cheval j3 {}
  cheval j4 {} */
//  ajouter_chevaux(liste_joueur, j1, j2, j3, j4);



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
    printf("LE JOUEUR NUMERO %d COMMENCE \n", n_joueur);
    /* while()
    //{ // boucle principale du jeu;
      val_D = lancer_de();    joueur j;
      if (nb_chevaux(j.liste_chevaux) == 0) // si le joueur qui doit jouer n'a aucun cheval
      {
        if(val_D == 6)
        {
          /* sortir les chevaux fonction à coder par arthur*/
        } /*
        else
        {
          printf("Dommage.. Vous passez votre tour ! \n");
        }

      }
      else
      {

        if(val_D == 6) //su le joueur fait un 6
        {
            n_joueur-=1; // rejoueras
            printf("Voulez vous sortir un nouveau cheval ? (o/n) : ");
            scanf("%c", reponse);
            while(get_char() != '\n'); // vide le cache
            if(reponse == 'o')
              {
              // fonction pour ajouter un cheval a la liste et le sortir coder par arthur

              }
            else // si il ne veut pas sortir de cheval, il se deplace donc..
              {  // a factoriser en fonction genre test_deplacement(); qui fait ca dans cheval(); avec *plateau pour modifier diredt (demander si droit de faire ca)
                test_deplacement(15, plateau, &liste_joueur[n_joueur], &coord_x, &coord_y)
              }
          }
        else
        {
              // fonction deplacement a factoriser (voir si il peu se deplacer lequel bouger etc...)
        }

      }

      n_tour+=1;
      n_joueur = (n_joueur+=1)%4;

  } */

}

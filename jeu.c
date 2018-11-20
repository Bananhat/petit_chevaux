#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/plateau.h"
#include "headers/jeu.h"
#include "headers/interface.h"

int lancer_de()
{
  int valeur_d = rand()%6 + 1;
  return valeur_d;
}


void jeu (joueur *liste_joueur, int nb_joueur)
{
  int n_joueur=rand()%nb_joueur +1,n_tour=1, val_D;

  char reponse;

    // Place les chevaux dans les écuries
    placer_chevaux_joueurs(liste_joueur);



  cheval j1= {liste_joueur[JAUNE].liste_chevaux[0].case_x, liste_joueur[JAUNE].liste_chevaux[0].case_y, 1, 6, 0, 'j', '1'};
  cheval j2 ={liste_joueur[JAUNE].liste_chevaux[1].case_x, liste_joueur[JAUNE].liste_chevaux[1].case_y, 2, 6, 0, 'j', '2'};
  cheval j3 ={liste_joueur[JAUNE].liste_chevaux[2].case_x,liste_joueur[JAUNE].liste_chevaux[2].case_y,3,6,0,'j', '3'};
  cheval j4 ={liste_joueur[JAUNE].liste_chevaux[3].case_x,liste_joueur[JAUNE].liste_chevaux[3].case_y,4,6,0,'j', '4'};
  init_chevaux(liste_joueur, &j1, &j2, &j3, &j4); //ajoute les chevaux dans la main du joueur


  cheval b1 = {liste_joueur[BLEU].liste_chevaux[0].case_x, liste_joueur[BLEU].liste_chevaux[0].case_y, 1, 0, 8, 'b', '1'};
  cheval b2 = {liste_joueur[BLEU].liste_chevaux[1].case_x, liste_joueur[BLEU].liste_chevaux[1].case_y, 2, 0, 8, 'b', '2'};
  cheval b3 = {liste_joueur[BLEU].liste_chevaux[2].case_x,liste_joueur[BLEU].liste_chevaux[2].case_y,3,0,8,'b', '3'};
  cheval b4 = {liste_joueur[BLEU].liste_chevaux[3].case_x,liste_joueur[BLEU].liste_chevaux[3].case_y,4,0,8,'b', '4'};
  init_chevaux(liste_joueur, &b1, &b2, &b3, &b4); //ajoute les chevaux dans la main du joueur

  cheval t1 = {liste_joueur[VERT].liste_chevaux[0].case_x, liste_joueur[VERT].liste_chevaux[0].case_y, 1, 14, 6, 'v', '1'};
  cheval t2 = {liste_joueur[VERT].liste_chevaux[1].case_x, liste_joueur[VERT].liste_chevaux[1].case_y, 2, 14, 6, 'v', '2'};
  cheval t3 = {liste_joueur[VERT].liste_chevaux[2].case_x, liste_joueur[VERT].liste_chevaux[2].case_y, 3, 14, 6, 'v', '3'};
  cheval t4 = {liste_joueur[VERT].liste_chevaux[3].case_x, liste_joueur[VERT].liste_chevaux[3].case_y, 4, 14, 6, 'v', '4'};
  init_chevaux(liste_joueur, &t1, &t2, &t3, &t4); //ajoute les chevaux dans la main du joueur

  cheval v1 = {liste_joueur[ROUGE].liste_chevaux[0].case_x, liste_joueur[ROUGE].liste_chevaux[0].case_y, 1, 8, 14, 'r', '1'};
  cheval v2 = {liste_joueur[ROUGE].liste_chevaux[1].case_x, liste_joueur[ROUGE].liste_chevaux[1].case_y, 2, 8, 14, 'r', '2'};
  cheval v3 = {liste_joueur[ROUGE].liste_chevaux[2].case_x,liste_joueur[ROUGE].liste_chevaux[2].case_y,3,8,14,'r', '3'};
  cheval v4 = {liste_joueur[ROUGE].liste_chevaux[3].case_x,liste_joueur[ROUGE].liste_chevaux[3].case_y,4,8,14,'r', '4'};
  init_chevaux(liste_joueur, &v1, &v2, &v3, &v4); //ajoute les chevaux dans la main du joueur

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


   // Update le plateau avec les chevaux dans les écuries.
   update(plateau, liste_joueur);
   // Affiche le plateau
   refresh(liste_joueur, plateau);

    printf("LE JOUEUR NUMERO %d COMMENCE \n", n_joueur);
    joueur *joueur_courant = &liste_joueur[n_joueur-1];

     while(/*nb_chevaux(&liste_joueur[0]) && nb_chevaux(&liste_joueur[1]) && nb_chevaux(&liste_joueur[2]) && nb_chevaux(&liste_joueur[3]) */ reponse != 's')
    { // boucle principale du jeu;
      val_D = lancer_de();
      printf("Le joueur %d a fais un %d\n", n_joueur, val_D);
      if(nb_chevaux(joueur_courant) == 0)
    /* && chevaux_numerote(&joueur_courant) == 0*/ // si le joueur qui doit jouer n'a aucun cheval sur le plateau ou sur les cases numerotées */
      {
        if(val_D == 6)
        {
          printf("Voulez vous sortir un nouveau cheval ? (o/n) : ");
          scanf("%c", &reponse);
          while(getchar() != '\n'); // vide le cache
          if(reponse == 'o')
          {
          sortir_chevaux(&n_joueur, joueur_courant, plateau);
          }
          else
          {
            printf("Alors vous passez votre tour");
          }
          // Update le plateau avec les chevaux dans les écuries.
          update(plateau, liste_joueur);
          // Affiche le plateau
          refresh(liste_joueur, plateau);
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
              sortir_chevaux(&n_joueur, joueur_courant, plateau);

              }
            else // si il ne veut pas sortir de cheval, il se deplace donc..
              {
                deplacement_test(plateau, joueur_courant, val_D);
              }
        }
        else // si le joueur fait autre chose que 6 il ne peut que se deplacer ou non en fonction de si ila  le droit (deplacement_test())
        {
              // fonction deplacement et conditions..
        }

      }

      n_tour+=1;
      n_joueur = (n_joueur)%nb_joueur + 1;
      joueur_courant = &liste_joueur[n_joueur-1];
      printf("\nAu tour du joueur %d \n",n_joueur);


  }

}

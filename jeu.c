#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/jeu.h"
#include "headers/joueur.h"

int lancer_de(){
  srand(time(NULL));
  int valeur_d = rand()%7-1 +1
  return valeur_d;
}
void jeu (void){
  int n_joueur=(fonction pendant le init la),n_tour=1;
  int valide;
  int n_cheval;

  while()
  { // boucle principale du jeu;
    val_D = lancer_de();
    if (nb_chevaux(j.liste_chevaux) == 0){
      if(val_D == 6){
        /* sortir les chevaux fonction à coder par arthur*/
      }
      else{
        printf("Dommage.. Vous passez votre tour ! \n");
      }

    }
    else
    {

      if(val_D == 6)
      {
          n_joueur-=1; // rejoueras
          printf("Voulez vous sortir un nouveau cheval ? (o/n) : ");
          scanf("%c", reponse);
          while(get_char() != '\n'); // vide le cache
          if(reponse == 'o')
            {
            // fonction pour ajouter un cheval a la liste et le sortir coder par arthur

            }
          else
            {  // a factoriser en fonction genre test_deplacement(); qui fait ca dans cheval(); avec *plateau pour modifier diredt (demander si droit de faire ca)
              if (nb_chevaux(j.liste_chevaux > 1)){
                printf("Le quel voulez vous deplacer ? : (1,2,3,4)");
                scanf("%d", n_cheval);
              }
              valide = deplacement(coor_x, coord_y, val_D);
              if (valide == 0)
                {
                  printf("Vous ne pouvez pas vous deplacer ..")
                }
              else
                {
                  printf("Appuyez sur une touche pour vous deplaer de 6 cases....");
                  /* appuez sur entrer*/
                  plateau[coord_y][coord_x] = j.liste_chevaux[n_cheval];
                }
            }
        }
      else
      {
            // fonction deplacement a factoriser (voir si il peu se deplacer lequel bouger etc...)
      }

    }
    
    n_tour+=1;
    n_joueur = (n_joueur+=1)%4;

}
}

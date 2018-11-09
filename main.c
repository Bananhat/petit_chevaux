#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/plateau.h"
#include "headers/joueur.h" // pas besoin d'inclure cheval.h car il est déjà inclu dans joueur pour faire la liste de chevaux
#include "headers/interface.h"
//#include "headers/jeu.h"

int main(int argc, const char* argv[]) {
  srand(time(NULL));

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

//  init_partie();
  int val_D;
    int coord_x = 6;
int   coord_y=0;
  plateau[0][6] = 'j';
  afficher_plateau(15, plateau);
  printf("De combine de case voulez vous deplacer le joueur ?");
  scanf("%d", &val_D);
  plateau[coord_y][coord_x] = '7';
  deplacement(&coord_x,&coord_y, val_D);
  printf("%d || %d \n", coord_x, coord_y);
  plateau[coord_y][coord_x] = 'j';
  afficher_plateau(15, plateau);


  return 0;
}

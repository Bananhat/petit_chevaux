#include <stdlib.h>
#include <stdio.h>


enum couleur {'j', 'r', 'b','v'};

typedef struct cheval {
  int case_x, case_y, numero;
  char couleur;
  char nom[2];
}cheval;
int deplacement(int *coord_x, int *coord_y, int val_D); // on utilise des pointeurs pour modifier directement les valeurs de coord_x ET coord_y

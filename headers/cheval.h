#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int case_x, case_y, numero;
  int case_debut_x, case_debut_y;
  int case_ecurie_x, case_ecurie_y;

  char couleur;
  char nom;
  int actif;
}  cheval;

int deplacement(int *coord_y, int *coord_x, int val_D, cheval cheval, char plateau[15][15]); // on utilise des pointeurs pour modifier directement les valeurs de coord_x ET coord_y

#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int case_x, case_y, numero;
  int case_debut_x, case_debut_y;
  int case_ecurie_x, case_ecurie_y;
  int case_fin_x, case_fin_y;

  char couleur;
  char nom;
  int actif;
  int final;
}  cheval;

int deplacement(int *coord_y, int *coord_x, int old_coord_y, int old_coord_x, int val_D, cheval cheval, char plateau[][15], int* final); // on utilise des pointeurs pour modifier directement les valeurs de coord_x ET coord_y
int validation_deplacement(int *coord_x, int *coord_y, int val_D, char plateau[][15],cheval cheval, int *incr, int old_coord_x, int old_coord_y, int *final);
void deplacement_final(char plateau[][15], int pos_x, int pos_y, cheval* cheval, int val_D);

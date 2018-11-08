#include <stdio.h>
#include <stdlib.h>

typedef struct joueur joueur;

struct joueur {
  char couleur;
  char nom[15];
  cheval liste_chevaux[4];
};

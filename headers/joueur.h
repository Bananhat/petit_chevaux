#include <stdio.h>
#include <stdlib.h>
#include "cheval.h"

typedef struct joueur joueur;

struct joueur {
  char couleur;
  char nom[15];
  cheval liste_chevaux[4];
};

int nb_chevaux(cheval* liste_chevaux)

#include <stdio.h>
#include <stdlib.h>
#include "cheval.h"


typedef struct joueur {
  char couleur;
  char nom[15];
  cheval liste_chevaux[4];
  cheval liste_ecurie[4];
}joueur;

int nb_chevaux(joueur * p_joueur) //on declarera comme ca : joueur j et on fera nb_chevaux(&j);

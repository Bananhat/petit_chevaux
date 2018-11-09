#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "headers/jeu.h"

int main(void) {

  joueur *liste_joueur = init_partie();
  jeu(joueur liste_joueur[4]);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "headers/jeu.h"
#include "headers/plateau.h"
#include "headers/interface.h"

int main(void) {
    srand(time(NULL));
    joueur liste_joueur[4];

    init_partie(liste_joueur);
    printf("\n\n");
    jeu(liste_joueur);

  return 0;
}

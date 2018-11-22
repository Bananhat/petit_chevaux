#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#include "headers/plateau.h"
#include "headers/jeu.h"
#include "headers/interface.h"

int main(void) {
    srand(time(NULL));
    joueur liste_joueur[4];
    int liste_couleurs[4];
    int nb_joueur = init_partie(liste_joueur, liste_couleurs);
    printf("\n\n");
    jeu(liste_joueur, nb_joueur,liste_couleurs);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "headers/joueur.h"



int nb_chevaux(joueur *p_joueur){ //le but est de trouver un moyen pour compter les chevaux actif du joueur (les chevaux qui serons ejecter porterons le numero -1
  int incr=0;
    for (int i =0; i<4; i++)
    {
      if(p_joueur->liste_chevaux[i].numero == 1 || p_joueur->liste_chevaux[i].numero == 2 ||
         p_joueur->liste_chevaux[i].numero == 3 || p_joueur->liste_chevaux[i].numero == 4)
      {
          incr+=1;
      }
  }
  return incr;
}

void ajouter_chevaux_ecurie_init(joueur liste_joueur[], cheval* j1, cheval* j2, cheval* j3, cheval* j4){
    int i =0;
    while(liste_joueur[i].couleur != j1->couleur)
    {
      i+=1;
    }

    liste_joueur[i].liste_ecurie[0] = *j1;
    liste_joueur[i].liste_ecurie[1] = *j2;
    liste_joueur[i].liste_ecurie[2] = *j3;
    liste_joueur[i].liste_ecurie[3] = *j4;

}

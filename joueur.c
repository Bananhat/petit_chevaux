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
          incr+=1
      }
  }
  return incr;
}

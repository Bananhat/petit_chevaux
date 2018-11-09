#include <stdio.h>
#include <stdlib.h>
#include "headers/joueur.h"



int nb_chevaux(cheval liste_chevaux[]){
  int incr =0;
    for (int i =0; i<4; i++){
    if(liste_chevaux[i] == 'j' || liste_chevaux[i] == 'r' || liste_chevaux[i] == 'b' || liste_chevaux[i] == 'v'){
        incr+=1
    }
  }
  return incr;
}

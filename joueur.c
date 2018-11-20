#include <stdio.h>
#include <stdlib.h>
#include "headers/joueur.h"


// A REVOIR
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
void init_chevaux(joueur liste_joueur[], cheval* c1, cheval* c2, cheval* c3, cheval* c4)
{
    int i =0;
    while(liste_joueur[i].couleur != c1->couleur)
    {
      i+=1;
    }

    liste_joueur[i].liste_ecurie[0] = *c1;
    liste_joueur[i].liste_ecurie[1] = *c2;
    liste_joueur[i].liste_ecurie[2] = *c3;
    liste_joueur[i].liste_ecurie[3] = *c4;

    liste_joueur[i].liste_chevaux[0] = *c1;
    liste_joueur[i].liste_chevaux[1] = *c2;
    liste_joueur[i].liste_chevaux[2] = *c3;
    liste_joueur[i].liste_chevaux[3] = *c4;

    liste_joueur[i].liste_chevaux[0].numero = -1;
    liste_joueur[i].liste_chevaux[1].numero = -1;
    liste_joueur[i].liste_chevaux[2].numero = -1;
    liste_joueur[i].liste_chevaux[3].numero = -1;

}

void placer_chevaux(cheval liste_chevaux[4], int x, int y) {
  liste_chevaux[0].case_x = x;
  liste_chevaux[0].case_y = y;

  liste_chevaux[1].case_x = x + 1;
  liste_chevaux[1].case_y = y;

  liste_chevaux[2].case_x = x;
  liste_chevaux[2].case_y = y + 1;

  liste_chevaux[3].case_x = x + 1;
  liste_chevaux[3].case_y = y + 1;
}

void placer_chevaux_joueurs(joueur liste_joueur[]) {
  int tab_x[4]= {2,2,11,11};
  int tab_y[4] = {2,11,2,11};
  // On prend les 4 joueurs
  for (int i = 0; i < 4; i++) {
    // On place ses chevaux
    placer_chevaux(liste_joueur[i].liste_chevaux, tab_x[i], tab_y[i]);
  }
}

void ajouter_cheval_actif(joueur *p_joueur, int n_cheval, char plateau[][15])
{
  plateau[p_joueur->liste_chevaux[n_cheval-1].case_x][p_joueur->liste_chevaux[n_cheval-1].case_y]='0';
  p_joueur->liste_chevaux[n_cheval-1] = p_joueur->liste_ecurie[n_cheval-1];
  p_joueur->liste_ecurie[n_cheval-1].numero = -1;
  p_joueur->liste_chevaux[n_cheval-1].case_x =  p_joueur->liste_chevaux[n_cheval-1].case_debut_x;
  p_joueur->liste_chevaux[n_cheval-1].case_y =   p_joueur->liste_chevaux[n_cheval-1].case_debut_y;
}

void sortir_chevaux(int * n_joueur, joueur *p_joueur, char plateau[][15])
{

      int n_cheval;
      printf("Quel numero de cheval ? :");
      scanf("%d", &n_cheval);
      // fonction pour ajouter un cheval a la liste active et le sortir coder par arthur
      ajouter_cheval_actif(p_joueur, n_cheval, plateau);
        //  *n_joueur -= 1; // rejoueras
}

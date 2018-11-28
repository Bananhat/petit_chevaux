#include <stdio.h>
#include <stdlib.h>
#include "headers/joueur.h"

//------------------------------------------------------------------------------------
// FONCTIONS CALCULS
void update_etat_joueur(etat_joueur * etat_joueur, joueur * joueur_courant, char plateau[][15])
{
  if( (plateau[joueur_courant->liste_chevaux[0].case_debut_x][joueur_courant->liste_chevaux[0].case_debut_y]!='7'
    && plateau[joueur_courant->liste_chevaux[0].case_debut_x][joueur_courant->liste_chevaux[0].case_debut_y] != joueur_courant->couleur)
  || nb_chevaux(joueur_courant) == 4)
  {
    etat_joueur->impossible_sortir_chevaux = 1;
  }
  else
  {
    etat_joueur->impossible_sortir_chevaux = 0;
  }

}
int search_player(joueur liste_joueur[4], char couleur) {
  for(int i = 0; i < 4; i++) {
    if (liste_joueur[i].couleur == couleur) {
      return i;
    }
  }
  return -1;
}

char search_char_number(joueur liste_joueur[4], int player, int pos_x, int pos_y) {
  for(int i = 0; i < 4; i++) {
    if (liste_joueur[player].liste_chevaux[i].case_x == pos_x && liste_joueur[player].liste_chevaux[i].case_y == pos_y) {
      return liste_joueur[player].liste_chevaux[i].nom;
    }
  }
  return 0;
}
char search_number(joueur liste_joueur[4], int player, int pos_x, int pos_y) {
  for(int i = 0; i < 4; i++) {
    if (liste_joueur[player].liste_chevaux[i].case_x == pos_x && liste_joueur[player].liste_chevaux[i].case_y == pos_y) {
      return liste_joueur[player].liste_chevaux[i].numero - 1;
    }
  }
  return -1;
}

int nb_chevaux(joueur *p_joueur)
{
  int incr=0;
    for (int i =0; i<4; i++)
    {
      incr+=p_joueur->liste_chevaux[i].actif;
  }
  return incr;
}
// FIN FONCTION CALCUL
//------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------
//FONCTION QUI PLACE LES CHEVAUX
void init_chevaux_dans_ecurie(joueur liste_joueur[], cheval c1, cheval c2, cheval c3, cheval c4, int num) //initialiser les chevaux dans la main du joueur
{
    liste_joueur[num].liste_chevaux[0] = c1;
    liste_joueur[num].liste_chevaux[1] = c2;
    liste_joueur[num].liste_chevaux[2] = c3;
    liste_joueur[num].liste_chevaux[3] = c4;
}

void placer_chevaux(cheval liste_chevaux[4], int x, int y) //place les chevaux dans l'écurie
{
  liste_chevaux[0].case_x = x;
  liste_chevaux[0].case_y = y;

  liste_chevaux[1].case_x = x + 1;
  liste_chevaux[1].case_y = y;

  liste_chevaux[2].case_x = x;
  liste_chevaux[2].case_y = y + 1;

  liste_chevaux[3].case_x = x + 1;
  liste_chevaux[3].case_y = y + 1;
}
void placer_chevaux_joueurs(joueur liste_joueur[])
{
  int tab_x[4]= {2,2,11,11};
  int tab_y[4] = {2,11,2,11};
  // On prend les 4 joueurs
  for (int i = 0; i < 4; i++) {
    // On place ses chevaux
    placer_chevaux(liste_joueur[i].liste_chevaux, tab_x[i], tab_y[i]);
  }
}

//ajoute un cheval sur le jeu
void ajouter_cheval_actif(joueur *p_joueur, int n_cheval, char plateau[][15])
{
  plateau[p_joueur->liste_chevaux[n_cheval-1].case_x][p_joueur->liste_chevaux[n_cheval-1].case_y]='0'; //on reset la case de base à 0
  p_joueur->liste_chevaux[n_cheval-1].case_x =  p_joueur->liste_chevaux[n_cheval-1].case_debut_x;
  p_joueur->liste_chevaux[n_cheval-1].case_y =   p_joueur->liste_chevaux[n_cheval-1].case_debut_y;
  p_joueur->liste_chevaux[n_cheval-1].actif = 1;
}

void sortir_chevaux(joueur *p_joueur, char plateau[][15], joueur liste_joueur[])
{

    int n_cheval;
    do
    {
      printf("Quel numero de cheval ? :");
      scanf("%d", &n_cheval);
      while(getchar()!='\n');
    } while(p_joueur->liste_chevaux[n_cheval-1].actif == 1 || n_cheval > 4);
    // ON EJECTE LES CHEVAUX PRESENTS SUR CETTE CASE SAUF SI C'EST SA COULEUR
    int debut_x = p_joueur->liste_chevaux[n_cheval-1].case_debut_x;
    int debut_y = p_joueur->liste_chevaux[n_cheval-1].case_debut_y;
    char couleur = p_joueur->liste_chevaux[n_cheval-1].couleur;
    printf("Case debut x = %d\n", debut_x);
    printf("Case debut y = %d\n", debut_y);
    printf("Couleur = %d\n", couleur);
    if(plateau[debut_x][debut_y] != couleur && plateau[debut_x][debut_y] != '7') {
      eject_cheval(plateau, plateau[debut_x][debut_y], debut_x, debut_y, liste_joueur);
    }
    // On ajoute le cheval sauf si il a gagné
    if (p_joueur->liste_chevaux[n_cheval-1].case_x != 7 && p_joueur->liste_chevaux[n_cheval-1].case_y != 7) {
      ajouter_cheval_actif(p_joueur, n_cheval, plateau);
      printf("Vous pouvez re-jouer !   \n");
    }
    else {
      printf("Vous avez déja gagné avec ce cheval !\n");
    }
}



// FIN FONCTION DE PLACEMENT
//------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------
// fonction qui ejecte un cheval quand un joueur arrive pile dessus
void eject_cheval(char plateau[][15], char couleur, int pos_x, int pos_y, joueur liste_joueur[])
{
  int player = -1, nom = -1;
  // On éjecte tous les chevaux de cette case (si il y en a plusieurs)
  player = search_player(liste_joueur, couleur);
  do {
    nom = search_number(liste_joueur, player, pos_x, pos_y);
    if (nom >= 0 && nom <=3) {
      liste_joueur[player].liste_chevaux[nom].case_x = liste_joueur[player].liste_chevaux[nom].case_ecurie_x;
      liste_joueur[player].liste_chevaux[nom].case_y = liste_joueur[player].liste_chevaux[nom].case_ecurie_y;
      liste_joueur[player].liste_chevaux[nom].actif = 0;
    }
  } while(nom != -1);
}

int check_cheval(char plateau[][15], int pos_x, int pos_y, cheval cheval, int val_D) {
  if(cheval.couleur == 'j') {
    if(plateau[pos_x][pos_y+val_D] == cheval.couleur || pos_y+val_D>6) {
      return 1;
    }
  }
  else if(cheval.couleur == 'b') {
    if(plateau[pos_x+val_D][pos_y] == cheval.couleur || pos_x+val_D > 6) {
      return 1;
    };
  }
  else if(cheval.couleur == 'v') {
    if(plateau[pos_x-val_D][pos_y] == cheval.couleur || pos_x-val_D > 6) {
      return 1;
    };
  }
  else if(cheval.couleur == 'r') {
    cheval.case_y-=1;
    if(plateau[pos_x][pos_y-val_D] == cheval.couleur || pos_y-val_D>6) {
      return 1;
    }
  }
  return 0;
}



void deplacement_final(char plateau[][15], int pos_x, int pos_y, cheval* cheval, int val_D) {

  char tab_result[7] = {'7','1','2','3','4','5','6'};
  int num = 0;

  if (check_cheval(plateau, pos_x, pos_y, *cheval, val_D) == 0)
  {

    if(cheval->couleur == 'j') {
      plateau[pos_x][cheval->case_y+=val_D] = cheval->couleur;
    }
    else if(cheval->couleur == 'b') {
      plateau[cheval->case_x+=val_D][pos_y] = cheval->couleur;
    }
    else if(cheval->couleur == 'v') {
      plateau[cheval->case_x-=val_D][pos_y] = cheval->couleur;
    }
    else if(cheval->couleur == 'r') {
      plateau[pos_x][cheval->case_y-=val_D] = cheval->couleur;
    }

    if(cheval->couleur == 'j' || cheval -> couleur == 'r') {
      num = abs(7 - (7 - pos_y));
    }
    else if (cheval->couleur == 'v' || cheval -> couleur == 'b') {
      num = 7 - (7 - pos_x);
    }

    plateau[pos_x][pos_y] = tab_result[num];
    cheval->final = 2;
  }

}

void cheval_victoire(char plateau[][15], cheval* cheval) {
  printf("Ce cheval a terminé la partie !\n");
  cheval->actif = 0;
}

int test_victoire(joueur* joueur_courant) {
  int victoire = 0;
  for(int i = 0; i < 4; i++) {
    if(joueur_courant->liste_chevaux[i].final == 2) {
        victoire++;
    }
  }
  printf("victoire = %d\n", victoire);
  return victoire;
}

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
  int indice=-1;
  for(int i = 0; i < 4; i++)
  {
    if (liste_joueur[i].couleur == couleur)
    {
      indice=i;
    }
  }
  return indice;
}

char search_char_number(joueur liste_joueur[4], int player, int pos_x, int pos_y) {
  char nom=0;
  for(int i = 0; i < 4; i++)
  {
    if (liste_joueur[player].liste_chevaux[i].case_x == pos_x && liste_joueur[player].liste_chevaux[i].case_y == pos_y)
    {
      nom=liste_joueur[player].liste_chevaux[i].nom;
    }
  }
  return nom;
}
int search_number(joueur liste_joueur[4], int player, int pos_x, int pos_y)
{
  int numero=-1;
  for(int i = 0; i < 4; i++)
  {
    if (liste_joueur[player].liste_chevaux[i].case_x == pos_x && liste_joueur[player].liste_chevaux[i].case_y == pos_y)
    {
      numero = liste_joueur[player].liste_chevaux[i].numero - 1;
    }
  }
  return numero;
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
  int tab_y[4] = {2,11,11,2};
  // On prend les 4 joueurs
  for (couleur_enum i =JAUNE; i<=VERT; i++)
  {
    // On place ses chevaux
    placer_chevaux(liste_joueur[i].liste_chevaux, tab_x[i], tab_y[i]);
  }
}

void init_chevaux(joueur liste_joueur[])
{
      /*
        cheval c1 = {liste_joueur[JAUNE].liste_chevaux[0].case_x, liste_joueur[JAUNE].liste_chevaux[0].case_y, 1, 6, 0, 2, 2, 7, 0, 'j', '1',0,0};
        cheval c2 = {liste_joueur[JAUNE].liste_chevaux[1].case_x, liste_joueur[JAUNE].liste_chevaux[1].case_y, 2, 6, 0, 3, 2, 7, 0, 'j', '2',0,0};
        cheval c3 = {liste_joueur[JAUNE].liste_chevaux[2].case_x,liste_joueur[JAUNE].liste_chevaux[2].case_y,3,6,0,2,3,7,0,'j', '3',0,0};
        cheval c4 = {liste_joueur[JAUNE].liste_chevaux[3].case_x,liste_joueur[JAUNE].liste_chevaux[3].case_y,4,6,0,3,3,7,0,'j', '4',0,0};
        init_chevaux_dans_ecurie(liste_joueur, c1, c2, c3, c4, JAUNE  );
        */

          cheval c1 = {liste_joueur[JAUNE].liste_chevaux[0].case_x, liste_joueur[JAUNE].liste_chevaux[0].case_y, 1, 8, 2, 2, 2, 7, 0, 'j', '1',0,0};
          cheval c2 = {liste_joueur[JAUNE].liste_chevaux[1].case_x, liste_joueur[JAUNE].liste_chevaux[1].case_y, 2, 8, 3, 3, 2, 7, 0, 'j', '2',0,0};
          cheval c3 = {liste_joueur[JAUNE].liste_chevaux[2].case_x,liste_joueur[JAUNE].liste_chevaux[2].case_y,3,8,4,4,3,7,0,'j', '3',0,0};
          cheval c4 = {liste_joueur[JAUNE].liste_chevaux[3].case_x,liste_joueur[JAUNE].liste_chevaux[3].case_y,4,8,5,5,3,7,0,'j', '4',0,0};
          init_chevaux_dans_ecurie(liste_joueur, c1, c2, c3, c4, JAUNE  );


         cheval d1 = {liste_joueur[BLEU].liste_chevaux[0].case_x, liste_joueur[BLEU].liste_chevaux[0].case_y, 1, 0, 8, 2, 11, 0, 7, 'b', '1',0,0};
         cheval d2 = {liste_joueur[BLEU].liste_chevaux[1].case_x, liste_joueur[BLEU].liste_chevaux[1].case_y, 2, 0, 8, 3, 11, 0, 7, 'b', '2',0,0};
         cheval d3 = {liste_joueur[BLEU].liste_chevaux[2].case_x,liste_joueur[BLEU].liste_chevaux[2].case_y,3,0,8,2,12,0,7,'b', '3',0,0};
         cheval d4 = {liste_joueur[BLEU].liste_chevaux[3].case_x,liste_joueur[BLEU].liste_chevaux[3].case_y,4,0,8,3,12,0,7,'b', '4',0,0};
         init_chevaux_dans_ecurie(liste_joueur, d1, d2, d3, d4, BLEU);

         cheval e1 = {liste_joueur[VERT].liste_chevaux[0].case_x, liste_joueur[VERT].liste_chevaux[0].case_y, 1, 14, 6, 11, 2, 14, 7, 'v', '1',0,0};
         cheval e2 = {liste_joueur[VERT].liste_chevaux[1].case_x, liste_joueur[VERT].liste_chevaux[1].case_y, 2, 14, 6, 12, 2, 14, 7, 'v', '2',0,0};
         cheval e3 = {liste_joueur[VERT].liste_chevaux[2].case_x, liste_joueur[VERT].liste_chevaux[2].case_y, 3, 14, 6, 11, 3, 14, 7, 'v', '3',0,0};
         cheval e4 = {liste_joueur[VERT].liste_chevaux[3].case_x, liste_joueur[VERT].liste_chevaux[3].case_y, 4, 14, 6, 12, 3, 14, 7, 'v', '4',0,0};
         init_chevaux_dans_ecurie(liste_joueur, e1, e2, e3, e4, VERT);

         cheval f1 = {liste_joueur[ROUGE].liste_chevaux[0].case_x, liste_joueur[ROUGE].liste_chevaux[0].case_y, 1, 8, 14, 11, 11, 7, 14, 'r', '1',0,0};
         cheval f2 = {liste_joueur[ROUGE].liste_chevaux[1].case_x, liste_joueur[ROUGE].liste_chevaux[1].case_y, 2, 8, 14, 12, 11, 7, 14, 'r', '2',0,0};
         cheval f3 = {liste_joueur[ROUGE].liste_chevaux[2].case_x,liste_joueur[ROUGE].liste_chevaux[2].case_y,3,8,14,11,12,7,14,'r', '3',0,0};
         cheval f4 = {liste_joueur[ROUGE].liste_chevaux[3].case_x,liste_joueur[ROUGE].liste_chevaux[3].case_y,4,8,14,12,12,7,14,'r', '4',0,0};
         init_chevaux_dans_ecurie(liste_joueur, f1, f2, f3, f4, ROUGE);
  }

//ajoute un cheval sur le jeu
void ajouter_cheval_actif(joueur *p_joueur, int n_cheval, char plateau[][15])
{
  plateau[p_joueur->liste_chevaux[n_cheval-1].case_x][p_joueur->liste_chevaux[n_cheval-1].case_y]='0'; //on reset la case de base à 0
  p_joueur->liste_chevaux[n_cheval-1].case_x =  p_joueur->liste_chevaux[n_cheval-1].case_debut_x;
  p_joueur->liste_chevaux[n_cheval-1].case_y =   p_joueur->liste_chevaux[n_cheval-1].case_debut_y;
  p_joueur->liste_chevaux[n_cheval-1].actif = 1;
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
      if (nom >= 0 && nom <=3)
      {
        liste_joueur[player].liste_chevaux[nom].case_x = liste_joueur[player].liste_chevaux[nom].case_ecurie_x;
        liste_joueur[player].liste_chevaux[nom].case_y = liste_joueur[player].liste_chevaux[nom].case_ecurie_y;
        liste_joueur[player].liste_chevaux[nom].actif = 0;
      }
  } while(nom != -1);
}

void cheval_inactif_case_numerote(int position_apres, cheval *cheval, int val_D, int num, int pos_2, char plateau[][15])
{
  printf("entree\n");
  int i=num+1;
  int personne=0;

  while(personne==0 && i<=6) //rend inactif si quelqu'un devant lui ou la fin (i==6 a la fin)
  {
    if( (cheval->couleur == 'j' && plateau[pos_2][i] != 'j') || (cheval->couleur=='r' && plateau[pos_2][i] != 'r') ||
          (cheval->couleur == 'b' &&plateau[i][pos_2] != 'b') || (cheval->couleur=='v' && plateau[i][pos_2] != 'v'))
    {
      personne=1;
    }
    i++;
  }

  if(personne==0)
  {
    printf("okkk\n");
    cheval->actif=0;
  }

}
// Sortric condition dans une autre fonction
int cheval_present(int pos1, int pos2, int val_D, cheval cheval, char plateau[][15])
{
  int cheval_present=0;
  for(int i=1; i<=val_D;i++)
  {
    if (cheval.couleur=='j' && plateau[pos1][pos2+i] == 'j')
    {
      cheval_present=1;
    }
    else if (cheval.couleur=='b' && plateau[pos1+i][pos2] == 'b')
    {
      cheval_present=1;
    }
    else if (cheval.couleur=='r'  && plateau[pos1-i][pos2] == 'r')
    {
      cheval_present=1;
    }
    else if (cheval.couleur=='v'  && plateau[pos1][pos2-i] == 'v')
    {
      cheval_present=1;
    }

  }
  return cheval_present;
}
int check_cheval(char plateau[][15], int pos_x, int pos_y, cheval *cheval, int val_D)
{
  int obstacle_cheval=0;
  if(cheval->couleur == 'j')
  {
    if(plateau[pos_x][pos_y+val_D] == cheval->couleur || pos_y+val_D>6)
    {
       obstacle_cheval=1;
    }
  }
  else if(cheval->couleur == 'b')
  {
    if(plateau[pos_x+val_D][pos_y] == cheval->couleur || pos_x+val_D > 6)
    {
       obstacle_cheval= 1;
    }
  }
  else if(cheval->couleur == 'v')
  {
    if(plateau[pos_x-val_D][pos_y] == cheval->couleur || pos_x-val_D > 6)
    {
       obstacle_cheval=1;
    }
  }
  else if(cheval->couleur == 'r')
  {
    if(plateau[pos_x][pos_y-val_D] == cheval->couleur || pos_y-val_D>6)
    {
       obstacle_cheval=1;
    }
  }
  return  obstacle_cheval;
}


int numero_case(cheval cheval, int pos_x, int pos_y){
  int num=0;
  if(cheval.couleur == 'j' || cheval.couleur == 'r')
  {
    num = abs(7 - (7 - pos_y));
  }
  else if (cheval.couleur == 'v' || cheval.couleur == 'b')
  {
    num = abs(7 - (7 - pos_x));
  }
  return num;
}

void deplacement_final(char plateau[][15], int pos_x, int pos_y, cheval* cheval, int val_D)
{

  char tab_result[7] = {'7','1','2','3','4','5','6'};
  int num;

  if (check_cheval(plateau, pos_x, pos_y, cheval, val_D) == 0 && cheval_present(pos_x, pos_y, val_D, *cheval, plateau) == 0)
  {

    num = numero_case(*cheval, pos_x, pos_y);

    if(cheval->couleur == 'j')
    {
      plateau[pos_x][cheval->case_y+=val_D] = cheval->couleur;
      cheval_inactif_case_numerote(pos_y+val_D, cheval, val_D, num+val_D, pos_x, plateau);
    }

//-------------------
    else if(cheval->couleur == 'b')
    {
      plateau[cheval->case_x+=val_D][pos_y] = cheval->couleur;
      cheval_inactif_case_numerote(pos_x+val_D, cheval, val_D, num, pos_y, plateau);
    }
    else if(cheval->couleur == 'v')
    {
      plateau[cheval->case_x-=val_D][pos_y] = cheval->couleur;
      cheval_inactif_case_numerote(pos_x-val_D, cheval, val_D, num, pos_y, plateau);

    }
    else if(cheval->couleur == 'r')
    {
      plateau[pos_x][cheval->case_y-=val_D] = cheval->couleur;
      cheval_inactif_case_numerote(pos_y+val_D, cheval, val_D, num, pos_x, plateau);

    }

    plateau[pos_x][pos_y] = tab_result[num];
    cheval->final = 2;
  }

}
/* FONCTION A CHANGER EN DESACTIVER CHEVAUX
void cheval_victoire(char plateau[][15], cheval* cheval) {
  printf("Ce cheval a terminé la partie !\n");
  cheval->actif = 0;
}*/

int test_victoire(joueur* joueur_courant)
{
  int victoire = 0;
  for(int i = 0; i < 4; i++)
  {
    victoire+=(joueur_courant->liste_chevaux[i].final == 2);
  }
  return victoire;
}

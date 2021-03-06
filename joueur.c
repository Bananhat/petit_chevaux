#include <stdio.h>
#include <stdlib.h>
#include "headers/joueur.h"
#include "headers/interface.h"
//------------------------------------------------------------------------------------
// FONCTIONS CALCULS
void mettre_a_jour_etat_joueur(etat_joueur * etat_joueur, joueur * joueur_courant, char plateau[][15])
{
  if(nb_chevaux(joueur_courant) == 4)
  {
    etat_joueur->impossible_sortir_chevaux = 1;
  }
  else
  {
    etat_joueur->impossible_sortir_chevaux = 0;
  }

}

int cherche_indice_joueur(joueur liste_joueur[4], char couleur)
{
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

char cherche_numero_cheval_caractere(joueur liste_joueur[4], int player, int pos_x, int pos_y) {
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

int cherhce_numero_cheval_entier(joueur liste_joueur[4], int player, int pos_x, int pos_y)
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

void sortir_chevaux(joueur *p_joueur, char plateau[][15], joueur liste_joueur[])
{

    int n_cheval;
    n_cheval = joueur_valide_cheval_sortir(*p_joueur);

    // ON EJECTE LES CHEVAUX PRESENTS SUR CETTE CASE SAUF SI C'EST SA COULEUR
    int debut_x = p_joueur->liste_chevaux[n_cheval-1].case_debut_x;
    int debut_y = p_joueur->liste_chevaux[n_cheval-1].case_debut_y;
    char couleur = p_joueur->liste_chevaux[n_cheval-1].couleur;

    if(plateau[debut_x][debut_y] != couleur && plateau[debut_x][debut_y] != '7')
    {
      eject_cheval(plateau[debut_x][debut_y], debut_x, debut_y, liste_joueur);
    }
    // On ajoute le cheval sauf si il a gagné
    if (p_joueur->liste_chevaux[n_cheval-1].case_x != 7 && p_joueur->liste_chevaux[n_cheval-1].case_y != 7)
    {
      ajouter_cheval_actif(p_joueur, n_cheval, plateau);
      printf("Vous pouvez re-jouer !   \n");
    }
    else
    {
      printf("Vous avez déja gagné avec ce cheval !\n");
    }
}

void init_chevaux(joueur liste_joueur[])
{
          cheval c1 = {liste_joueur[JAUNE].liste_chevaux[0].case_x, liste_joueur[JAUNE].liste_chevaux[0].case_y, 1, 6, 0, 2, 2, 7, 0, 'j', '1',0,0};
          cheval c2 = {liste_joueur[JAUNE].liste_chevaux[1].case_x, liste_joueur[JAUNE].liste_chevaux[1].case_y, 2, 6, 0, 3, 2, 7, 0, 'j', '2',0,0};
          cheval c3 = {liste_joueur[JAUNE].liste_chevaux[2].case_x,liste_joueur[JAUNE].liste_chevaux[2].case_y,3,6,0,2,3,7,0,'j', '3',0,0};
          cheval c4 = {liste_joueur[JAUNE].liste_chevaux[3].case_x,liste_joueur[JAUNE].liste_chevaux[3].case_y,4,6,0,3,3,7,0,'j', '4',0,0};
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
void eject_cheval(char couleur, int pos_x, int pos_y, joueur liste_joueur[])
{
  int player = -1, nom = -1;
  // On éjecte tous les chevaux de cette case (si il y en a plusieurs)
  player = cherche_indice_joueur(liste_joueur, couleur);
  do {
      nom = cherhce_numero_cheval_entier(liste_joueur, player, pos_x, pos_y);
      if (nom >= 0 && nom <=3)
      {
        liste_joueur[player].liste_chevaux[nom].case_x = liste_joueur[player].liste_chevaux[nom].case_ecurie_x;
        liste_joueur[player].liste_chevaux[nom].case_y = liste_joueur[player].liste_chevaux[nom].case_ecurie_y;
        liste_joueur[player].liste_chevaux[nom].actif = 0;
      }
  } while(nom != -1);
}

void cheval_inactif_case_numerote(cheval *cheval,int num, int pos_2, char plateau[][15])
{

  int i=num;
  int personne=0;

  while(personne==0 && i<=6) //rend inactif si quelqu'un devant lui ou la fin (i==6 a la fin)
  {
    if( (cheval->couleur == 'j' && plateau[pos_2][i] != 'j') || (cheval->couleur=='r' && plateau[pos_2][14-i] != 'r') ||
          (cheval->couleur == 'b' && plateau[i][pos_2] != 'b') || (cheval->couleur=='v' && plateau[14-i][pos_2] != 'v'))
    {
      personne=1;
    }
    i++;
  }

  if(personne==0)
  {
    cheval->actif=0;
  }

}

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
    else if (cheval.couleur=='r'  && plateau[pos1][pos2-i] == 'r')
    {
      cheval_present=1;
    }
    else if (cheval.couleur=='v'  && plateau[pos1-i][pos2] == 'v')
    {
      cheval_present=1;
    }

  }
  return cheval_present;
}

int test_obstacle_cheval(char plateau[][15], int pos_x, int pos_y, cheval *cheval, int val_D)
{
  int obstacle_cheval=0;
  if(cheval->couleur == 'j' && pos_y+val_D>6)
    {
       obstacle_cheval=1;
    }
    else if(cheval->couleur == 'r' && abs(14-(pos_y-val_D))>6)
    {
       obstacle_cheval=1;
    }
  else if(cheval->couleur == 'b' && pos_x+val_D > 6)
    {
       obstacle_cheval= 1;
    }
  else if(cheval->couleur == 'v' && abs(14-(pos_x-val_D)) > 6)
    {
       obstacle_cheval=1;
    }

  return  obstacle_cheval;
}


int numero_case(cheval cheval, int pos_x, int pos_y){
  int num=0;
  if(cheval.couleur == 'j' || cheval.couleur == 'r')
  {
    num = 7 - abs(7 - pos_y);
  }
  else if (cheval.couleur == 'v' || cheval.couleur == 'b')
  {
    num = 7 - abs(7 - pos_x);
  }
  return num;
}


int test_victoire(joueur* joueur_courant)
{
  int victoire = 0;
  for(int i = 0; i < 4; i++)
  {
    victoire+=(joueur_courant->liste_chevaux[i].final == 2);
  }
  return victoire;
}

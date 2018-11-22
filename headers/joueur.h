#include <stdio.h>
#include <stdlib.h>
#include "cheval.h"

typedef enum {JAUNE, BLEU, VERT, ROUGE} couleur_enum;

typedef struct {
  char couleur;
  char nom[30];
  cheval liste_chevaux[4];
  cheval liste_ecurie[4]; //l'écurie n'est utile que pour le sconditions et les calculs
}joueur;

typedef struct {
  int impossible_sortir_chevaux;
}etat_joueur;
int nb_chevaux(joueur *p_joueur); //on declarera comme ca : joueur j et on fera nb_chevaux(&j);

void placer_chevaux(cheval liste_chevaux[4], int x, int y);

void placer_chevaux_joueurs(joueur liste_joueur[]);
void init_chevaux(joueur liste_joueur[], cheval c1, cheval c2, cheval c3, cheval c4, int num);
void deplacement_test(char plateau[15][15], joueur * p_j, int val_D);
void sortir_chevaux(int* n_joueur, joueur *p_joueur, char plateau[][15]);
void ajouter_cheval_actif(joueur *p_joueur, int n_cheval, char plateau[][15]);


void update_etat_joueur(etat_joueur * etat_joueur, joueur * jouer_courant, char plateau[][15]);

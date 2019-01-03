#ifndef CHEVAL_H
#define CHEVAL_H

/**
* \file cheval.h
* \brief Fonctions concernant les chevaux
*
*/


typedef struct {
  int case_x, case_y, numero;
  int case_debut_x, case_debut_y;
  int case_ecurie_x, case_ecurie_y;
  int case_fin_x, case_fin_y;

  char couleur;
  char nom;
  int actif;
  int final;
} cheval;

/**
* \fn int deplacement(int *coord_y, int *coord_x, int old_coord_y, int old_coord_x, int val_D, cheval cheval, char plateau[][15], int* final)
* \brief Déplace le cheval sur le plateau en fonction des coordonnées du plateau de jeu
*
* @param coord_x coordoonées du cheval
* @param coord_y coordoonées du cheval
* @param old_coord_y coordonnées du cheval avant son déplacement
* @param old_coord_x coordonnées du cheval avant son déplacement
* @param val_D valeur du dé
* @param cheval cheval qui va subir le déplacement
* @param plateau plateau de jeu
* @param final variable qui indique si le cheval est sur les cases numérotées
* @return la validité final du déplacement sous forme d'un entier qui peut prendre 3 valeurs (0,1,2)
*/
int deplacement(int *coord_y, int *coord_x, int old_coord_y, int old_coord_x, int val_D, cheval cheval, char plateau[][15], int* final);

/**
* \fn int validation_deplacement(int *coord_x, int *coord_y, int val_D, char plateau[][15],cheval cheval, int *incr, int old_coord_x, int old_coord_y, int *final)
* \brief Vérifie si un déplacement sur une case donnée est valide
*
* @param coord_x coordoonées du cheval
* @param coord_y coordoonées du cheval
* @param val_D valeur du dé
* @param plateau plateau de jeu
* @param cheval cheval qui va subir le déplacement
* @param incr variable qui indique le nombre déplacement
* @param old_coord_x coordonnées du cheval avant son déplacement
* @param old_coord_y coordonnées du cheval avant son déplacement
* @param final variable qui indique si le cheval est sur les cases numérotées
* @return la validité de chaque déplacements sous forme d'un entier qui peut prendre 3 valeurs (0,1,2)
*/
int validation_deplacement(int *coord_x, int *coord_y, int val_D, char plateau[][15], cheval cheval, int *incr, int old_coord_x, int old_coord_y, int *final);

/**
* \fn void deplacement_final(char plateau[][15], int pos_x, int pos_y, cheval* cheval, int val_D)
* \brief Permet le déplacement du cheval sur les cases numérotées
*
* @param plateau plateau de jeu
* @param pos_x coordoonées du cheval
* @param pos_y coordoonées du cheval
* @param cheval cheval courant
* @param val_D valeur du dé
*/
void deplacement_final(char plateau[][15], int pos_x, int pos_y, cheval* cheval, int val_D);

#endif

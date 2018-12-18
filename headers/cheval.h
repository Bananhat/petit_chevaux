#ifndef CHEVAL_H
#define CHEVAL_H

typedef struct {
  int case_x, case_y, numero;
  int case_debut_x, case_debut_y;
  int case_ecurie_x, case_ecurie_y;
  int case_fin_x, case_fin_y;

  char couleur;
  char nom;
  int actif;
  int final;
}  cheval;

/**
*Déplace le cheval sur le plateau en fonction des coordonnées du plateau de jeu
*@param, @param coordoonées du cheval
*@param,@param coordonnées du cheval avant son déplacement
*@param valeur du dé
*@param cheval qui va subir le déplacement
@param plateau de jeu
@param variable qui indique si le cheval est sur les cases numérotées
@return la validité final du déplacement sous forme d'un entier qui peut prendre 3 valeurs (0,1,2)
**/
int deplacement(int *coord_y, int *coord_x, int old_coord_y, int old_coord_x, int val_D, cheval cheval, char plateau[][15], int* final); // on utilise des pointeurs pour modifier directement les valeurs de coord_x ET coord_y
/**
*Vérifie si un déplacement sur une case donnée est valide
*@param, @param coordoonées du cheval
*@param valeur du dé
*@param plateau de jeu
*@param cheval qui va subir le déplacement
@param variable qui indique le nombre déplacement
*@param,@param coordonnées du cheval avant son déplacement
*@param variable qui indique si le cheval est sur les cases numérotées
@return la validité de chaque déplacements sous forme d'un entier qui peut prendre 3 valeurs (0,1,2)
**/
int validation_deplacement(int *coord_x, int *coord_y, int val_D, char plateau[][15],cheval cheval, int *incr, int old_coord_x, int old_coord_y, int *final);
/**
*Permet le déplacement du cheval sur les cases numérotées
*@param plateau de jeu
*@param,@param coordoonées du cheval
*@param cheval courant
*@param valeur du dé
**/
void deplacement_final(char plateau[][15], int pos_x, int pos_y, cheval* cheval, int val_D);

#endif

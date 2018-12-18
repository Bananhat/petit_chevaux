#ifndef JOUEUR_H
#define JOUEUR_H

#include "cheval.h"

typedef enum {JAUNE, BLEU, ROUGE, VERT} couleur_enum;

typedef struct {
  char couleur;
  char nom[30];
  cheval liste_chevaux[4];
} joueur;

typedef struct { //structure peut être temporaire (ca peut être utile pour spécifer les etats de joueurs possibles)
  int impossible_sortir_chevaux;
} etat_joueur;

/**
*Retourne le nombre de chevaux posés sur le plateau d'un joueur
*@param Joueur courant
*return le nombre de joueurs actifs sur le plateau
**/
int nb_chevaux(joueur *p_joueur);

/**
*Défini les coordonnées de placement dans l'écurie d'un joueur
*@param liste de chevaux du joueur
*@param coordonée x de placement dans l'écurie
*@param coordonée y de placement dans l'écurie
**/
void placer_chevaux(cheval liste_chevaux[4], int x, int y);

/**
*Place effectivement tous les joueurs grace a une boucle qui parcours tous les joueurs
*@param liste des joueurs
**/
void placer_chevaux_joueurs(joueur liste_joueur[]);
/**
*Rempli la liste de chevaux d'un joueur
*@param liste des joueurs
*@param, @param, @param, @param chevaux initialisés
*@param couleur du joueur
**/
void init_chevaux_dans_ecurie(joueur liste_joueur[], cheval c1, cheval c2, cheval c3, cheval c4, int num);
/**
*Test le deplacement et gère les différents cas
*@param plateau de jeu
*@param joueur courant
*@param valeur du dé
*@param liste des joueurs
**/
void deplacement_test(char plateau[15][15], joueur * p_j, int val_D, joueur liste_joueur[]);
/**
*Gere les différents cas de sorti de chevaux (si un cheval est déjà sur le case, etc...)
*@param joueur courant
*@param plateau de jeu
*@param liste des joueurs
**/
void sortir_chevaux(joueur *p_joueur, char plateau[][15], joueur liste_joueur[]);
/**
*Sors effectivement un cheval à sa position initiale
*@param joueur courant
*@param numero du cheval
*@param plateau de jeu
**/
void ajouter_cheval_actif(joueur *p_joueur, int n_cheval, char plateau[][15]);
/**
*Cherche l'indice du joueur correspondant à sa couleur, passé en entré
*@param liste des joueurs
*@param couleur du joueur
*@return l'indice du joueur en type int
**/
int search_player(joueur liste_joueur[4], char couleur);
/**
*Cherche le numéro du cheval présent sur une case en type caractère à partir de l'indice du joueur et d'une position
*@param liste des joueurs
*@param indice du joueur
*@param, @param coordonées x et y d'une case
@return le numero du cheval en type caractere si il est present sur une case
**/
char search_char_number(joueur liste_joueur[4], int player, int pos_x, int pos_y);

/**
*Cherche le numéro du cheval présent sur une case en type entier à partir de l'indice du joueur et d'une position
*@param liste des joueurs
*@param indice du joueur
*@param, @param coordonée x et y d'une case
@return le numero du cheval en type entier si il est present sur une case
**/
int search_number(joueur liste_joueur[4], int player, int pos_x, int pos_y);

/**
*Fonction qui met à jour les booléens qui traduise de l'état du joueur dans la structure état joueur
*@param structure etat du joueur
*@param joueur courant
*@param plateau de jeu
**/
void update_etat_joueur(etat_joueur * etat_joueur, joueur * joueur_courant, char plateau[][15]);
/**
*Remet un cheval à sa position dans l'écurie
*@param couleur du joueur qui va se faire ejecter
*@param, @param position x,y du joueur avant l'éjection
*@param liste des joueurs
**/
void eject_cheval(char couleur, int pos_x, int pos_y, joueur liste_joueur[]);

/**
*Retourne le nombre de personne qui sont sur les cases nunmérotés
*@param joueur courants
*return le nombre de joueur dont la variable final de leur chevaux vaut 2
**/
int test_victoire(joueur* joueur_courant);



/**
*Initialise tous les chevaux pour les mettre dans la liste de chevaux des joueurs
**/
void init_chevaux(joueur liste_joueur[]);

/**
*Rend un cheval inactif si il a fini de jouer, qu'on ne pourra plus jamais le déplacer
@param cheval a rendre potentiellement inactif
@param Premiere coordonnée : numero de la case sur laquelle le joueur se trouvera apres son deplacement
@param Deuxieme coordonnée  : permet de bien déplacer le joueur sur les cases numérotés
@param plateau de jeu
**/
void cheval_inactif_case_numerote(cheval *cheval, int num, int pos_2, char plateau[][15]);

/**
*Fonction qui informe de la presence d'un cheval sur son parcours sur les cases numérotés
@param,@param coordonnée x,y
@param valeur du dé
@param cheval qui se déplace
@param plateau de jeu
@return 1 si un cheval est present et 0 sinon
**/
int cheval_present(int pos1, int pos2, int val_D, cheval cheval, char plateau[][15]);
/**
*Fonction test si un cheval va hors de sa limite dans les cases numérotés
@param plateau de jeu
@param, @param coordonnée du cheval avant son déplacement
@param cheval veut se déplacer
@param valeur du dé
@return 1 si le cheval est hors de ces limites, 0 sinon
**/
int check_cheval(char plateau[][15], int pos_x, int pos_y, cheval *cheval, int val_D);
/**
*Fonction qui renvoie le numéro de case sur lequelle un cheval est
@param cheval courant
@param, @param coordonnées du cheval
@return le numéro du cheval
**/
int numero_case(cheval cheval, int pos_x, int pos_y);

#endif

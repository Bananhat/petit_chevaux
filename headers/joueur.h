#ifndef JOUEUR_H
#define JOUEUR_H

#include "cheval.h" 

/**
* \file joueur.h
* \brief Fonctions concernant le joueur
*
*/

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
* \fn int nb_chevaux(joueur *p_joueur)
* \brief Retourne le nombre de chevaux posés sur le plateau d'un joueur
*
* @param p_joueur Joueur courant
* @return le nombre de chevaux actifs sur le plateau
*/
int nb_chevaux(joueur *p_joueur);

/**
* \fn void placer_chevaux(cheval liste_chevaux[4], int x, int y)
* \brief Défini les coordonnées de placement dans l'écurie d'un joueur
*
* @param liste_chevaux liste de chevaux du joueur
* @param x coordonée x de placement dans l'écurie
* @param y coordonée y de placement dans l'écurie
*/
void placer_chevaux(cheval liste_chevaux[4], int x, int y);

/**
* \fn void placer_chevaux_joueurs(joueur liste_joueur[])
* \brief Place effectivement tous les joueurs grace a une boucle qui parcours tous les joueurs
*
* @param liste_joueur liste des joueurs
*/
void placer_chevaux_joueurs(joueur liste_joueur[]);

/**
* \fn void init_chevaux_dans_ecurie(joueur liste_joueur[], cheval c1, cheval c2, cheval c3, cheval c4, int num);
* \brief Rempli la liste de chevaux d'un joueur
*
* @param liste_joueur liste des joueurs
* @param c1 cheval 1
* @param c2 cheval 2
* @param c3 cheval 3
* @param c4 cheval 4
* @param num couleur du joueur
*/
void init_chevaux_dans_ecurie(joueur liste_joueur[], cheval c1, cheval c2, cheval c3, cheval c4, int num);

/**
* \fn void deplacement_test(char plateau[15][15], joueur * p_j, int val_D, joueur liste_joueur[])
* \brief Test le deplacement et gère les différents cas
*
* @param plateau plateau de jeu
* @param p_j joueur courant
* @param val_D valeur du dé
* @param liste_joueur liste des joueurs
*/
void deplacement_test(char plateau[15][15], joueur * p_j, int val_D, joueur liste_joueur[]);

/**
* \fn void sortir_chevaux(joueur *p_joueur, char plateau[][15], joueur liste_joueur[])
* \brief Gere les différents cas de sorti de chevaux (si un cheval est déjà sur le case, etc...)
*
* @param p_joueur joueur courant
* @param plateau plateau de jeu
* @param liste_joueur liste des joueurs
*/
void sortir_chevaux(joueur *p_joueur, char plateau[][15], joueur liste_joueur[]);

/**
* \fn void ajouter_cheval_actif(joueur *p_joueur, int n_cheval, char plateau[][15])
* \brief Sors effectivement un cheval à sa position initiale
*
* @param p_joueur joueur courant
* @param n_cheval numero du cheval
* @param plateau plateau de jeu
*/
void ajouter_cheval_actif(joueur *p_joueur, int n_cheval, char plateau[][15]);

/**
* \fn int cherche_indice_joueur(joueur liste_joueur[4], char couleur)
* \brief Cherche l'indice du joueur correspondant à sa couleur, passé en entrée
*
* @param liste_joueur liste des joueurs
* @param couleur couleur du joueur
* @return l'indice du joueur en type int
*/
int cherche_indice_joueur(joueur liste_joueur[4], char couleur);

/**
* \fn char cherche_numero_cheval_caractere(joueur liste_joueur[4], int player, int pos_x, int pos_y)
* \brief Cherche le numéro du cheval présent sur une case en type caractère à partir de l'indice du joueur et d'une position
*
* @param liste_joueur liste des joueurs
* @param player indice du joueur
* @param pos_x coordonée x de la case
* @param pos_y coordonnée y de la case
* @return le numero du cheval en type caractere si il est present sur une case
*/
char cherche_numero_cheval_caractere(joueur liste_joueur[4], int player, int pos_x, int pos_y);

/**
* \fn int cherhce_numero_cheval_entier(joueur liste_joueur[4], int player, int pos_x, int pos_y)
* \brief Cherche le numéro du cheval présent sur une case en type entier à partir de l'indice du joueur et d'une position
*
* @param liste_joueur liste des joueurs
* @param player indice du joueur
* @param pos_x coordonée x de la case
* @param pos_y coordonnée y de la case
* @return le numero du cheval en type entier si il est present sur une case
*/
int cherhce_numero_cheval_entier(joueur liste_joueur[4], int player, int pos_x, int pos_y);

/**
* \fn void mettre_a_jour_etat_joueur(etat_joueur * etat_joueur, joueur * joueur_courant, char plateau[][15])
* \brief Fonction qui met à jour les booléens qui traduise de l'état du joueur dans la structure état joueur
*
* @param etat_joueur structure etat du joueur
* @param joueur_courant joueur courant
* @param plateau plateau de jeu
*/
void mettre_a_jour_etat_joueur(etat_joueur * etat_joueur, joueur * joueur_courant, char plateau[][15]);

/**
* \fn void eject_cheval(char couleur, int pos_x, int pos_y, joueur liste_joueur[]);
* \brief Remet un cheval à sa position dans l'écurie
*
* @param couleur couleur du joueur qui va se faire ejecter
* @param pos_x coordonée x avant l'éjection
* @param pos_y coordonnée y avant l'éjection
* @param liste_joueur liste des joueurs
*/
void eject_cheval(char couleur, int pos_x, int pos_y, joueur liste_joueur[]);

/**
* \fn int test_victoire(joueur* joueur_courant)
* \brief Retourne le nombre de personne qui sont sur les cases nunmérotés
*
* @param joueur_courant joueur courants
* @return le nombre de joueur dont la variable final de leur chevaux vaut 2
*/
int test_victoire(joueur* joueur_courant);

/**
* \fn void init_chevaux(joueur liste_joueur[])
* \brief Initialise tous les chevaux pour les mettre dans la liste de chevaux des joueurs
*
* @param liste_joueur liste des joueurs
*/
void init_chevaux(joueur liste_joueur[]);

/**
* \fn void cheval_inactif_case_numerote(cheval *cheval, int num, int pos_2, char plateau[][15])
* \brief Rend un cheval inactif si il a fini de jouer, qu'on ne pourra plus jamais le déplacer
*
* @param cheval cheval a rendre potentiellement inactif
* @param num Premiere coordonnée : numero de la case sur laquelle le joueur se trouvera apres son deplacement
* @param pos_2 Deuxieme coordonnée  : permet de bien déplacer le joueur sur les cases numérotés
* @param plateau plateau de jeu
*/
void cheval_inactif_case_numerote(cheval *cheval, int num, int pos_2, char plateau[][15]);

/**
* \fn int cheval_present(int pos1, int pos2, int val_D, cheval cheval, char plateau[][15])
* \brief Fonction qui informe de la presence d'un cheval sur son parcours sur les cases numérotés
*
* @param pos1 coordonée x
* @param pos2 coordonnée y
* @param val_D valeur du dé
* @param cheval cheval qui se déplace
* @param plateau plateau de jeu
* @return renvoie 1 si un cheval est present et 0 autrement
*/
int cheval_present(int pos1, int pos2, int val_D, cheval cheval, char plateau[][15]);

/**
* \fn int test_obstacle_cheval(char plateau[][15], int pos_x, int pos_y, cheval *cheval, int val_D)
* \brief Fonction test si un cheval va hors de sa limite dans les cases numérotés
*
* @param plateau plateau de jeu
* @param pos_x coordonnée x du cheval avant son déplacement
* @param pos_y coordonnée y du cheval avant son déplacement
* @param cheval cheval qui veut se déplacer
* @param val_D valeur du dé
* @return renvoie 1 si le cheval est hors de ces limites, 0 autrement
*/
int test_obstacle_cheval(char plateau[][15], int pos_x, int pos_y, cheval *cheval, int val_D);

/**
* \fn int numero_case(cheval cheval, int pos_x, int pos_y)
* \brief Fonction qui renvoie le numéro de case sur lequelle un cheval se trouve
*
* @param cheval cheval courant
* @param pos_x coordonnée x du cheval
* @param pos_y coordonnée y du cheval
* @return le numéro de la case (numérotée) sur lequel le cheval se trouve
*/
int numero_case(cheval cheval, int pos_x, int pos_y);

#endif

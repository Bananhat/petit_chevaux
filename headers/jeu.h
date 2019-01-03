#ifndef JEU_H
#define JEU_H 

/**
* \file jeu.h
* \brief Fonctions concernant le jeu
*
*/

/**
* \fn void jeu(joueur liste_joueur[], int nb_joueur, int liste_couleurs[], char plateau[][15])
* \brief Boucle principal du jeu et condition
*
* @param liste_joueur liste des joueurs
* @param nb_joueur nombres de joueurs
* @param liste_couleur liste des couleurs des joueurs
* @param plateau plateau de jeu
*/
void jeu(joueur liste_joueur[], int nb_joueur, int liste_couleurs[], char plateau[][15]);

/**
* \fn int lancer_de()
* \brief Retourne un nombre aleatoire entre 1 et 6
*
* @return l'entier aléatoire obtenu
*/
int lancer_de();

#endif

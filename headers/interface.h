#ifndef INTERFACE_H
#define INTERFACE_H 

/**
* \file interface.h
* \brief Fonctions concernant l'interface
*
*/

/**
* \fn int init_partie(joueur liste_joueur[], int liste_couleurs[])
* \brief Initialise la partie (nombre de joueurs, choix couleur)
*
* @param liste_joueur liste des joueurs
* @param liste_couleurs liste contenant l'énumeration des couleurs
* @return Le nombre de joueurs
*/
int init_partie(joueur liste_joueur[], int liste_couleurs[]);

/**
* \fn int joueur_valide_deplacement(char plateau[][15], joueur liste_joueur[])
* \brief Demande à l'utilisateur si il veut valider son déplacement
*
* @param plateau plateau de jeu
* @param liste_joueur liste des joueurs
* @return le choix du joueur
*/
int joueur_valide_deplacement(char plateau[][15], joueur liste_joueur[]);

/**
* \fn int joueur_valide_numeroCheval(joueur p_j)
* \brief Demande à l'utilisateur quel numéro de cheval il veut déplacer
*
* @param p_j joueur courant
* @return le numéro choisi
*/
int joueur_valide_numeroCheval(joueur p_j);

/**
* \fn int joueur_valide_cheval_sortir(joueur p_joueur)
* \brief Demande à l'utilisateur quel numéro de cheval il veut sortir
*
* @param p_joueur joueur courant
* @return le numéro choisi
*/
int joueur_valide_cheval_sortir(joueur p_joueur);

/**
* \fn void trie_tab( int tab[], int nb_joueur)
* \brief Trie un tableau par ordre croissant (permet de jouer dans l'ordre des aiguilles d'une montre)
*
* @param tab tableau à trier
* @param nb_joueur nombre de joueurs
*/
void trie_tab( int tab[], int nb_joueur);

#endif

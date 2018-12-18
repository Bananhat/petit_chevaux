#ifndef INTERFACE_H
#define INTERFACE_H

/**
*Initialise la partie (nombre de joueurs, choix couleur)
*@param1 liste des joueurs
*@param2 liste contenant l'énumeration des couleurs
**/
int init_partie(joueur liste_joueur[], int liste_couleurs[]);
/**
*Demande à l'utilisateur si il veut valider son déplacement
*@param1 plateau de jeu
*@param2 liste des joueurs
**/
int joueur_valide_deplacement(char plateau[][15], joueur liste_joueur[]);
/**
*Demande à l'utilisateur quel numéro de cheval il veut déplacer
*@param1 liste des joueurs
*@param2 liste des couleurs en énumeration
**/
int jouer_valide_numeroCheval(joueur * p_j);
/**
*Demande à l'utilisateur quel numéro de cheval il veut sortir
*@param1 joueur courant
**/
int joueur_valide_cheval_sortir(joueur p_joueur);
/**
*Trie un tableau par ordre croissant (pour jouer dans l'ordre des aiguilles d'une montre)
*@param1 tableau
*@param2 nombre de joueurs
**/
void trie_tab( int tab[], int nb_joueur);

#endif

#ifndef JEU_H
#define JEU_H

/**
*Boucle principal du jeu et condition
*@param liste des joueurs
*@param nombres de joueurs
*@param liste des couleurs des joueurs
*@param plateau de jeu
**/
void jeu(joueur liste_joueur[], int nb_joueur, int liste_couleurs[], char plateau[][15]);
/**
*Retourne un nombre aleatoire entre 1 et 6
**/
int lancer_de();

#endif

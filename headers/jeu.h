#ifndef JEU_H
#define JEU_H

/**
*Boucle principal du jeu et condition
*@param1 liste des joueurs
*@param2 nombres de joueurs
*@param3 liste des couleurs des joueurs
*@param4 plateau de jeu
**/
void jeu(joueur liste_joueur[], int nb_joueur, int liste_couleurs[], char plateau[][15]);
/**
*Retourne un nombre aleatoire entre 1 et 6
**/
int lancer_de();

#endif

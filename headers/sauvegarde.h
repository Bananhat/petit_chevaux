#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

/**
*Sauvegarde toutes les informations necessaire du jeu dans un fichier de sauvegarde (positions chevaux, etc...)
*@param plateau de jeu
*@param nom du fichier de sauvegarde à ouvrir ou créer
*@param liste des joueurs
*@param nombre de joueurs
*@param liste contenant l'énumeration des couleurs
*/
void sauvegarde_partie(char plateau[][15], char nom[30], joueur liste_joueur[], int nb_joueurs, int liste_couleurs[4]);
/**
*Recupère toutes les infos provenant d'un fichier de sauvegarde
*@param liste des joueurs
*@param nom du fichier de sauvegarde à ouvrir
*@param plateau de jeu
*@param liste contenant l'énumeration des couleurs
*/
int recup_sauvegarde(joueur liste_joueur[], char nom[30], char plateau[][15], int liste_couleurs[4]);

#endif

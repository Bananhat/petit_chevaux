#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H 

/**
* \file sauvegarde.h
* \brief Fonctions concernant la sauvegarde
*
*/

/**
* \fn void sauvegarde_partie(char plateau[][15], char nom[30], joueur liste_joueur[], int nb_joueurs, int liste_couleurs[4])
* \brief Sauvegarde toutes les informations necessaire du jeu dans un fichier de sauvegarde (positions chevaux, etc...)
*
* @param plateau plateau de jeu
* @param nom nom du fichier de sauvegarde à ouvrir ou créer
* @param liste_joueur liste des joueurs
* @param nb_joueurs nombre de joueurs
* @param liste_couleurs liste contenant l'énumeration des couleurs
*/
void sauvegarde_partie(char plateau[][15], char nom[30], joueur liste_joueur[], int nb_joueurs, int liste_couleurs[4]);

/**
* \fn int recup_sauvegarde(joueur liste_joueur[], char nom[30], char plateau[][15], int liste_couleurs[4])
* \brief Recupère toutes les infos provenant d'un fichier de sauvegarde
*
* @param liste_joueur liste des joueurs
* @param nom nom du fichier de sauvegarde à ouvrir
* @param plateau plateau de jeu
* @param liste_couleurs liste contenant l'énumeration des couleurs
*/
int recup_sauvegarde(joueur liste_joueur[], char nom[30], char plateau[][15], int liste_couleurs[4]);

#endif

#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

/**
*Sauvegarde toutes les informations necessaire du jeu dans un fichier de sauvegarde (positions chevaux, etc...)
*@param1 plateau de jeu
*@param2 nom du fichier de sauvegarde à ouvrir ou créer
*@param3 liste des joueurs
*@param4 nombre de joueurs
*@param2 liste contenant l'énumeration des couleurs
**/
void sauvegarde_partie(char plateau[][15], char nom[30], joueur liste_joueur[], int nb_joueurs, int liste_couleurs[4]);
/**
*Recupère toutes les infos provenant d'un fichier de sauvegarde
*@param1 liste des joueurs
*@param2 nom du fichier de sauvegarde à ouvrir
*@param3 plateau de jeu
*@param2 liste contenant l'énumeration des couleurs
**/
int recup_sauvegarde(joueur liste_joueur[], char nom[30], char plateau[][15], int liste_couleurs[4]);

#endif

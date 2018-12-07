#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

void sauvegarde_partie(char plateau[][15], char nom[30], joueur liste_joueur[], int nb_joueurs, int liste_couleurs[4]);

int recup_sauvegarde(joueur liste_joueur[], char nom[30], char plateau[][15], int liste_couleurs[4]);

#endif

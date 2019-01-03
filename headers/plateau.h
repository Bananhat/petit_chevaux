#ifndef PLATEAU_H
#define PLATEAU_H 

#include "joueur.h"

/**
* \file plateau.h
* \brief Fonctions concernant le plateau
*
*/

// Couleurs pour la console
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"
#define RESET1  "\e[0m"
#define FOND_BLACK "\x1b[40m"
#define FOND_RED "\e[48;5;196m"
#define FOND_RED1 "\e[48;5;088m"
#define FOND_GREEN "\x1b[42m"
#define FOND_GREEN1 "\e[48;5;022m"
#define FOND_YELLOW "\e[48;5;214m"
#define FOND_YELLOW1 "\e[48;5;220m"
#define FOND_BLUE "\x1b[44m"
#define FOND_BLUE1 "\e[48;5;027m"
#define FOND_PURPLE "\x1b[45m"
#define FOND_WHITE "\x1b[47m"
#define TEST "\e[4;34m"


/**
* \fn void mettre_a_jour(char plateau[][15], joueur liste_joueur[4])
* \brief Met à jour la position des chevaux sur le plateau
*
* @param plateau plateau de jeu
* @param liste_joueur liste des joueurs
*/
void mettre_a_jour(char plateau[][15], joueur liste_joueur[4]);

/**
* \fn void rafraichir(joueur liste_joueur[4], char plateau[][15])
* \brief Affiche le plateau dans la console avec les différentes couleurs
*
* @param liste_joueur liste des joueurs
* @param plateau plateau de jeu
*/
void rafraichir(joueur liste_joueur[4], char plateau[][15]);

#endif

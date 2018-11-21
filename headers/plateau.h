#include "joueur.h"
void update(char plateau[][15], joueur liste_joueur[4]);
void refresh(joueur liste_joueur[4], char plateau[15][15]);
int search_player(joueur liste_joueur[4], char couleur);
char search_number(joueur liste_joueur[4], int player, int pos_x, int pos_y);

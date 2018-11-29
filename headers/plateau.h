#include "joueur.h"

// Couleurs pour la console
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"
#define RESET1  "\e[0m"
#define FOND_BLACK "\x1b[40m"
#define FOND_RED "\x1b[41m"
#define FOND_RED1 "\e[48;5;160m"
#define FOND_GREEN "\x1b[42m"
#define FOND_YELLOW "\e[48;5;214m"
#define FOND_YELLOW1 "\e[48;5;220m"
#define FOND_BLUE "\x1b[44m"
#define FOND_BLUE1 "\e[48;5;075m"
#define FOND_PURPLE "\x1b[45m"
#define FOND_WHITE "\x1b[47m"
#define TEST "\e[4;34m"


void update(char plateau[][15], joueur liste_joueur[4]);
void refresh(joueur liste_joueur[4], char plateau[15][15]);

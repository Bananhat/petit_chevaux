#include <stdio.h>
#include <stdlib.h>
#include "headers/plateau.h"// Place les chevaux dans les écuries (ne marche pas encore)

// Couleurs pour la console
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"
#define FOND_BLACK "\x1b[40m"
#define FOND_RED "\x1b[41m"
#define FOND_GREEN "\x1b[42m"
#define FOND_YELLOW "\x1b[43m"
#define FOND_BLUE "\x1b[44m"
#define FOND_PURPLE "\x1b[45m"
#define FOND_WHITE "\x1b[47m"
#define TEST "\e[4;34m"


// Update les positions des chevaux sur le plateau
void update(char plateau[][15], joueur liste_joueur[4])
{
  // (Peut être optimisé pour ne boucler que sur le nombre précis de joueurs et donc plus besoin de test avant de bouger les chevaux)
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      // Si les joueurs sont actifs (léger bug pour cette condition qui laisse parfois passer à revoir)
      if (liste_joueur[i].couleur)
      {
        plateau[liste_joueur[i].liste_chevaux[j].case_x][liste_joueur[i].liste_chevaux[j].case_y] = liste_joueur[i].couleur;
      }
    }
  }
}

// Affiche le plateau
void refresh(joueur liste_joueur[4], char plateau[15][15])
{
  char nom;
  int player;
  for (int i = 0; i < 15; i++)
  {
    for (int j = 0; j < 15; j++)
    {
        if (plateau[i][j] == 'r')
        {
          player = search_player(liste_joueur, 'r');
          nom = search_char_number(liste_joueur, player, i, j);
          printf((FOND_RED" %c "RESET),nom);
        }
        else if (plateau[i][j] == 'j')
        {
          player = search_player(liste_joueur, 'j');
          nom = search_char_number(liste_joueur, player, i, j);
          printf((FOND_YELLOW" %c "RESET),nom);
        }
        else if (plateau[i][j] == 'b')
        {
          player = search_player(liste_joueur, 'b');
          nom = search_char_number(liste_joueur, player, i, j);
          printf((FOND_BLUE" %c "RESET),nom);
        }
        else if (plateau[i][j] == 'v')
        {
          player = search_player(liste_joueur, 'v');
          nom = search_char_number(liste_joueur, player, i, j);
          printf((FOND_GREEN" %c "RESET),nom);
        }
        else if (plateau[i][j] == '0')
        {
          printf((FOND_BLACK"   "RESET));
        }
        else if (plateau[i][j] == '7')
         {
          printf((FOND_WHITE"   "RESET));
        }
        else if (plateau[i][j] == '8')
        {
          printf((FOND_PURPLE"   "RESET));
        }
        else if (plateau[i][j] == 'c')
        {
          printf((FOND_BLUE"   "RESET));
        }
        else if (plateau[i][j] == 's')
        {
          printf((FOND_RED"   "RESET));
        }
        else if (plateau[i][j] == 'w')
        {
          printf((FOND_GREEN"   "RESET));
        }
        else if (plateau[i][j] == 'k')
        {
          printf((FOND_YELLOW"   "RESET));
        }
        else
        {
          printf(" %c ", plateau[i][j]);
        }
    }
    printf("\n");
  }
  printf("\n\n");
}

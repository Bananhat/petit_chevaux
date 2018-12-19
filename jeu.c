#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headers/plateau.h"
#include "headers/jeu.h"
#include "headers/interface.h"
#include "headers/sauvegarde.h"

int lancer_de()
{
  int valeur_d = rand()%6 + 1;
  return valeur_d;
}


void jeu (joueur liste_joueur[], int nb_joueur, int liste_couleurs[], char plateau[][15])
{

    int indice_joueur = rand()%nb_joueur;
    int n_joueur=liste_couleurs[indice_joueur], val_D;
    int exit=0;

    etat_joueur etat_joueur = {0};
    char reponse;
    char couleur[][6] = {"JAUNE", "BLEU", "ROUGE", "VERT"};

    printf("LE JOUEUR %s COMMENCE \n", couleur[n_joueur]);
    joueur *joueur_courant = &liste_joueur[n_joueur];

     while(test_victoire(joueur_courant) != 4 && exit!=1) //condition gagner
    { // boucle principale du jeu;

        mettre_a_jour_etat_joueur(&etat_joueur, joueur_courant, plateau);



        val_D = lancer_de();

        printf("Le joueur %s a fais un %d\n", couleur[n_joueur], val_D);

        if(nb_chevaux(joueur_courant) == 0) // si le joueur qui doit jouer n'a aucun cheval sur le plateau ou sur les cases numerotées */
        {
          if(val_D == 6)
          {
              indice_joueur-=1;
              if(etat_joueur.impossible_sortir_chevaux == 0)
              {
                printf("Voulez vous sortir un nouveau cheval ? (o/n) : "); // PENSER A METTRE CE GENRE DE SCANF DANS UNE FONCTION DANS INTERFACE
                scanf("%c", &reponse);
                while(getchar() != '\n'); // vide le cache
                if(reponse == 'o')
                {
                  sortir_chevaux(joueur_courant, plateau, liste_joueur);
                }
              else
              {
                printf("Alors vous passez votre tour....\n");
              }
              // Update le plateau avec les chevaux dans les écuries.
              mettre_a_jour(plateau, liste_joueur);
              // Affiche le plateau
              rafraichir(liste_joueur, plateau);
            }
          }
          else
          {
              printf("Impossible de sortir un cheval.. Vous passez votre tour ! \n");
          }

        }
        else
        {

          if(val_D == 6) //si le joueur fait un 6
          {
            indice_joueur-=1; // rejoueras
            if(etat_joueur.impossible_sortir_chevaux == 0)
            {
                printf("Voulez vous sortir un nouveau cheval ? (o/n) : ");
                scanf("%c", &reponse);
                while(getchar() != '\n'); // vide le cache
                if(reponse == 'o')
                  {
                  sortir_chevaux(joueur_courant, plateau, liste_joueur);
                  }
                else // si il ne veut pas sortir de cheval, il se deplace donc..
                  {
                    deplacement_test(plateau, joueur_courant, val_D, liste_joueur);
                  }
              }
              else
              {
                printf("Tu ne peux pas sortir de cheval\n");
                deplacement_test(plateau, joueur_courant, val_D, liste_joueur);
              }
        }
        else // si le joueur fait autre chose que 6 il ne peut que se deplacer ou non en fonction de si ila  le droit (deplacement_test())
        {
          deplacement_test(plateau, joueur_courant, val_D, liste_joueur);
        }
        // Update le plateau avec les chevaux dans les écuries.
        mettre_a_jour(plateau, liste_joueur);
        // Affiche le plateau
        rafraichir(liste_joueur, plateau);

      }


        // On test si le joueur a gagné (possiblement à revoir)
        if(test_victoire(joueur_courant) == 4) {
          // A REVOIR (faire des conditions pour afficher la couleur complète)
          printf("Le joueur %s remporte la partie !\n", couleur[n_joueur]);
        }
        else {
          indice_joueur+=1;
          n_joueur=liste_couleurs[indice_joueur%nb_joueur];
          joueur_courant = &liste_joueur[n_joueur];

          printf("\nAu tour du joueur %s\n", couleur[n_joueur]);
        }

        printf("Lancer le dé ...");

        if(getchar() == 's')
        {
          exit=1;
        }
  }
char nom_fichier[15];
printf("Entrez le nom du fichier de sauvegarde : ");
scanf("%s", nom_fichier);
sauvegarde_partie(plateau, nom_fichier, liste_joueur, nb_joueur, liste_couleurs);
}

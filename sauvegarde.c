#include <stdio.h>
#include <stdlib.h>

#include "headers/joueur.h"
#include "headers/sauvegarde.h"

// cheval c1 = {liste_joueur[JAUNE].liste_chevaux[0].case_x, liste_joueur[JAUNE].liste_chevaux[0].case_y, 1, 6, 0, 2, 2, 7, 0, 'j', '1',0,0};

void sauvegarde_partie(char plateau[][15], char nom[30], joueur liste_joueur[], int nb_joueurs, int liste_couleurs[4]) {

    FILE *f = fopen(nom, "w");
    if (f == NULL)
    {
        printf("Le fichier n'existe pas!\n");
        // On stop le programme
        exit(1);
    }

    // Print les infos cheval dans le fichier
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].case_x);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].case_y);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].actif);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].final);
            fprintf(f, "\n");
        }
    }

    fprintf(f, " %d\n", nb_joueurs);

    for(int i = 0; i < nb_joueurs; i++) {
        fprintf(f, " %c %d\n", liste_joueur[liste_couleurs[i]].couleur, liste_couleurs[i]);
    }

    fclose(f);
}

int recup_sauvegarde(joueur liste_joueur[], char nom[30], char plateau[][15], int liste_couleurs[4]) {
    FILE *f = fopen(nom, "r");
    if (f == NULL)
    {
        printf("Le fichier n'existe pas!\n");
        // On stop le programme
        exit(1);
    }

    // Recup les pos du fichier
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            fscanf(f, " %d  %d  %d  %d", &(liste_joueur[i].liste_chevaux[j].case_x), &(liste_joueur[i].liste_chevaux[j].case_y), &(liste_joueur[i].liste_chevaux[j].actif), &(liste_joueur[i].liste_chevaux[j].final));
        }
    }

    int nb_joueurs;
    fscanf(f, " %d", &nb_joueurs);

    for(int i = 0; i < nb_joueurs; i++) {
        int e_couleur;
        char couleur;
        fscanf(f, " %c %d", &couleur, &e_couleur);
        liste_joueur[e_couleur].couleur = couleur;
        liste_couleurs[i] = e_couleur;
    }

    fclose(f);

    return nb_joueurs;
}

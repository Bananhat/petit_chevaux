#include "headers/joueur.h"
#include "headers/sauvegarde.h"

// cheval c1 = {liste_joueur[JAUNE].liste_chevaux[0].case_x, liste_joueur[JAUNE].liste_chevaux[0].case_y, 1, 6, 0, 2, 2, 7, 0, 'j', '1',0,0};

void sauvegarde_partie(char plateau[][15], char nom[30], joueur liste_joueur[]) {

    FILE *f = fopen(nom, "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        // We stop the programm
        exit(1);
    }

    // Print les infos cheval dans le fichier
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].case_x);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].case_y);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].case_debut_x);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].case_debut_y);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].case_ecurie_x);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].case_ecurie_y);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].case_fin_x);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].case_fin_y);
            fprintf(f, " %c ", liste_joueur[i].liste_chevaux[j].couleur);
            fprintf(f, " %c ", liste_joueur[i].liste_chevaux[j].nom);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].actif);
            fprintf(f, " %d ", liste_joueur[i].liste_chevaux[j].final);
            fprintf(f, "\n");
        }
    }
    fclose(f);
}

void recup_sauvegarde(joueur liste_joueur[], char nom[30], char plateau[][15]) {
    FILE *f = fopen(nom, "r");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        // We stop the programm
        exit(1);
    }

    // Recup les pos du fichier
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            fscanf(f, " %d  %d  %d  %d  %d  %d  %d  %d  %c  %c  %d  %d", &(liste_joueur[i].liste_chevaux[j].case_x), &(liste_joueur[i].liste_chevaux[j].case_y), &(liste_joueur[i].liste_chevaux[j].case_debut_x), &(liste_joueur[i].liste_chevaux[j].case_debut_y), &(liste_joueur[i].liste_chevaux[j].case_ecurie_x), &(liste_joueur[i].liste_chevaux[j].case_ecurie_y), &(liste_joueur[i].liste_chevaux[j].case_fin_x), &(liste_joueur[i].liste_chevaux[j].case_fin_y), &(liste_joueur[i].liste_chevaux[j].couleur), &(liste_joueur[i].liste_chevaux[j].nom), &(liste_joueur[i].liste_chevaux[j].actif), &(liste_joueur[i].liste_chevaux[j].final));
        }
    }

    int nb_joueurs;
    fscanf(f, "%d", &nb_joueurs);

    fclose(f);
}

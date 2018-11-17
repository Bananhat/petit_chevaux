#include <stdio.h>
#include <stdlib.h>
#include "headers/joueur.h"


int deplacement(int *coord_x, int *coord_y, int val_D, cheval cheval, char plateau[15][15])	{

	int droite, gauche, bas, haut;
	int incr=1;

	int valide = 1;

	int old_coord_x = *coord_x;
	int old_coord_y = *coord_y;

	while(incr <= val_D && valide != 0)
	{

		droite=0;
		gauche=0;
		bas=0;
		haut=0;

		if ( (*coord_y == 0 && 6 <= *coord_x&&*coord_x <=7) || (*coord_y==6 && 8 <= *coord_x&&*coord_x <= 13) || (0<=*coord_x&&*coord_x<= 5 && *coord_y == 6) )
		{
			droite=1;
		}
		else if ( (*coord_y == 8 &&  9 <= *coord_x&&*coord_x <= 14) || (*coord_y == 14 && 7<= *coord_x&&*coord_x<= 8) || (*coord_y == 8 && 1 <= *coord_x&&*coord_x <= 6) )
    {
			gauche=1;
		}
		else if ( (0 <= *coord_y&&*coord_y  <= 5 && *coord_x == 8) || (6<=*coord_y&&*coord_y <=7 && *coord_x == 14) || (*coord_x==8 &&  8 <= *coord_y&&*coord_y  <= 13) )
		{
			bas = 1;
		}
		else if( (9 <= *coord_y && *coord_y <= 14 && *coord_x == 6) || (*coord_x == 0 &&  7 <= *coord_y && *coord_y  <= 8) || (*coord_x == 6 && 0<= *coord_y && *coord_y  <=6) )
		{
    	haut=1;
		}

		if (droite==1)
		{
    	*coord_x+=1;
		}
		else if(gauche==1)
		{
    	*coord_x-=1;
		}
		else if(bas == 1)
		{
    	*coord_y+=1;
		}
		else if (haut==1)
		{
    	*coord_y-=1;
		}

		if (plateau[*coord_y][*coord_x] == '7') //on verifie qu'il n'y ai personne
		{
			incr++;
		}
		//else if (incr == Val_D) //si il ya quelqueun et qu'on a fini de se deplacer
		//{
		/* pion se fait ejecter developpe par arthur (en grso *coord_x = cheval.ecurie_val *coord_y = cheval.ecurie_val)*/
	//  }
	// else if (x= j.case_debut_x && y=case_debut_y)
	// x = x_case_numerote_init
		// y = y_case_numerote_init
		// valide=2
		else //si on a pas fini de se deplacer et que c'est pas sept c'est que on ne peut pas se deplacer
		{
			valide = 0;
			*coord_x = old_coord_x; // on revient au point initial
			*coord_y = old_coord_y;
		}

}


 return valide;

}
// a la fin plateau[*coord_y][*coord_x] = 'j';

void deplacement_test(char plateau[15][15], joueur * p_j, int val_D)
{
	int n_cheval, valide;

	if (nb_chevaux(p_j) > 1)
	{
		printf("Le quel voulez vous deplacer ? : (1,2,3,4)");
		scanf("%d", &n_cheval);
	}
	int old_y = p_j->liste_chevaux[n_cheval].case_x;
	int old_x = p_j->liste_chevaux[n_cheval].case_y;
	int coord_x = p_j->liste_chevaux[n_cheval].case_x;
	int coord_y = p_j->liste_chevaux[n_cheval].case_y;
	char val_init = plateau[old_y][old_x];
		// if cheval[n_cheval] est dans la liste des chevaux actif
	valide = deplacement(&coord_x, &coord_y, val_D, p_j->liste_chevaux[n_cheval], plateau); //int *coord_x, int *coord_y, int val_D, cheval cheval, char** plateau
	// else si il est dans la case numerote
	// valide = deplacement_case_numerote...
	if (valide == 0)
		{
			printf("Vous ne pouvez pas vous deplacer ..");
		}
	else if (valide == 2)
		{
			printf("Bien joué vous êtes dans les cases numerote !");
		}
	else
		{
			printf("Appuyez sur une touche pour vous deplaer de %d cases....", val_D);
			/* appuez sur entrer*/
			plateau[coord_y][coord_x] = p_j->liste_chevaux[n_cheval].nom;
			plateau[old_y][old_x] = val_init;
		}

}

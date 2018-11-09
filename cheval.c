#include <stdio.h>
#include <stdlib.h>
#include "headers/cheval.h"


int deplacement(int *coord_x, int *coord_y, int val_D)	{

	int droite, gauche, bas, haut;
	int incr=1;
	int pas_valide = 0;
	int old_coord_x = *coord_x;
	int old_coord_y = *coord_y;

	while(incr <= val_D && pas_valide != 1)
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

		if (plateau[y][x] == '7') //on verifie qu'il n'y ai personne
		{
			incre ++
		}
		//else if (incr == Val_D) //si il ya quelqueun et qu'on a fini de se deplacer
		//{
		/* pion se fait ejecter developpe par arthur */
	//  }
		else //si on a pas fini de se deplacer et que c'est pas sept c'est que on ne peut pas se deplacer
		{
			valide = 0
			*coord_x = old_coord_x; // on revient au point initial
			*coord_y = old_coord_y;
		}

}
	if (valide=1)
	{
	return 1;
	}
	else
	{
		return 0;
	}

}
// a la fin plateau[*coord_y][*coord_x] = 'j';

void deplacement_test(int size, int plateau[size][size], joueur * p_j, int val_D, int*coord_x, int* coord_y)
{
	int n_cheval;
	if (nb_chevaux(p_j) > 1)
	{
		printf("Le quel voulez vous deplacer ? : (1,2,3,4)");
		scanf("%d", n_cheval);
	}
	valide = deplacement(coord_x, coord_y, val_D);
	if (valide == 0)
		{
			printf("Vous ne pouvez pas vous deplacer ..")
		}
	else
		{
			printf("Appuyez sur une touche pour vous deplaer de 6 cases....");
			/* appuez sur entrer*/
			plateau[*coord_y][*coord_x] = p_j->liste_chevaux[n_cheval].nom;
		}

}

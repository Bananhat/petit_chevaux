#include <stdio.h>
#include <stdlib.h>
#include "headers/plateau.h"
#include "headers/interface.h"


int deplacement(int *coord_y, int *coord_x, int old_coord_y, int old_coord_x, int val_D, cheval cheval, char plateau[][15])
{
	int incr=1;
	int valide = 1;

	while(incr <= val_D && valide==1)
	{

		if ( (*coord_x == 0 && 6 <= *coord_y&&*coord_y <=7) || (*coord_x==6 && 8 <= *coord_y&&*coord_y <= 13) || (0<=*coord_y&&*coord_y<= 5 && *coord_x == 6) )
		{
			*coord_y+=1;
		}
		else if ( (*coord_x == 8 &&  9 <= *coord_y&&*coord_y <= 14) || (*coord_x == 14 && 7<= *coord_y&&*coord_y<= 8) || (*coord_x == 8 && 1 <= *coord_y&&*coord_y <= 6) )
    {
				*coord_y-=1;
		}
		else if ( (0 <= *coord_x&&*coord_x  <= 5 && *coord_y == 8) || (6<=*coord_x&&*coord_x <=7 && *coord_y == 14) || (*coord_y==8 &&  8 <= *coord_x&&*coord_x  <= 13) )
		{
				*coord_x+=1;
		}
		else if( (9 <= *coord_x && *coord_x <= 14 && *coord_y == 6) || (*coord_y == 0 &&  7 <= *coord_x && *coord_x  <= 8) || (*coord_y == 6 && 0<= *coord_x && *coord_x  <=6) )
		{
    		*coord_x-=1;
		}


		if (plateau[*coord_x][*coord_y] == '7' || plateau[*coord_x][*coord_y] == cheval.couleur) //on verifie qu'il n'y ai personne
		{
			incr++;
		}
		else if (incr == val_D) //si on doit ejecter quelqu'un
		{
			valide = 2;
			incr++;
	  	}
	// else if (x= j.case_debut_x && y=case_debut_y)
	// x = x_case_numerote_init
		// y = y_case_numerote_init
		// valide=2
		else//si on doit chevaucher un adversaire
		{
			printf("PAS BON!\n");
			valide = 0;
			*coord_y = old_coord_y; // on revient au point initial
			*coord_x = old_coord_x;
		}

}

 return valide;

}

void deplacement_test(char plateau[][15], joueur * p_j, int val_D, joueur liste_joueur[])
{

	int n_cheval = jouer_valide_numeroCheval(p_j);

	int old_x = p_j->liste_chevaux[n_cheval-1].case_x; // valeur de x avant le deplacement
	int old_y = p_j->liste_chevaux[n_cheval-1].case_y; // valeur de y avant le deplacement

	int *coord_x = &p_j->liste_chevaux[n_cheval-1].case_x;
	int *coord_y = &p_j->liste_chevaux[n_cheval-1].case_y;
		// if cheval[n_cheval] est dans la liste des chevaux actif
	int valide = deplacement(coord_y, coord_x, old_y, old_x, val_D, p_j->liste_chevaux[n_cheval-1], plateau); // deplacement et modifications des coordonnées

	// else si il est dans la case numerote
	// valide = deplacement_case_numerote...
	if (valide == 0) // si il ne peut pas se deplacer c'est déjà gerer
		{
			printf("Vous ne pouvez pas vous deplacer ..\n");
		}

	else //sinon on lui demande si il est sur de vouloir se deplacer en simulant son deplacement
	{
			plateau[old_x][old_y] = '7';
			if(joueur_valide_deplacement(plateau, liste_joueur)) // si c'est bon on fait les tests et on delace
			{
				if (valide == 2)
					{
						eject_cheval(plateau, plateau[*coord_x][*coord_y], *coord_x, *coord_y, liste_joueur);
						printf("Vous avez éjecté un cheval !\n");
					}
				// else if(valide == 3) {}
				else
					{
						printf("Vous vous êtes deplacer..\n");

					}
			}
			else // sinon on remet à 7 la ou la simulation a été faites, et on le deplace a la pos de départ
			{
				plateau[*coord_x][*coord_y] = '7';
				*coord_x = old_x;
				*coord_y = old_y;
			}

	}

}

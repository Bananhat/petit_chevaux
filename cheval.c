#include <stdio.h>
#include <stdlib.h>
#include "headers/plateau.h"
#include "headers/interface.h"

int validation_deplacement(int *coord_x, int *coord_y, int val_D, char plateau[][15],cheval cheval, int *incr, int old_coord_x, int old_coord_y, int*final)
{
	int valide=1;
	if (*coord_x == cheval.case_fin_x && *coord_y == cheval.case_fin_y)
	{
			*final = 1;
			valide = 3;
	}
	else if (plateau[*coord_x][*coord_y] == '7' || plateau[*coord_x][*coord_y] == cheval.couleur) //on verifie qu'il n'y ai personne
	{
		*incr+=1;
	}
	else if (*incr == val_D) //si on doit ejecter quelqu'un
	{
		valide = 2;
		*incr+=1;
		}
	else//si on doit chevaucher un adversaire
	{
		valide = 0;
		*coord_y = old_coord_y; // on revient au point initial
		*coord_x = old_coord_x;
	}
	return valide;
}
int deplacement(int *coord_y, int *coord_x, int old_coord_y, int old_coord_x, int val_D, cheval cheval, char plateau[][15], int* final)
{
	int incr=1;
	int valide = 1;

	while(incr <= val_D && valide==1)
	{

		if ( (*coord_x == 0 && 6 <= *coord_y && *coord_y <=7) || (*coord_x==6 && 8 <= *coord_y&&*coord_y <= 13) || (0<=*coord_y&&*coord_y<= 5 && *coord_x == 6) )
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

		valide = validation_deplacement(coord_x, coord_y, val_D, plateau,cheval, &incr, old_coord_x, old_coord_y, final);

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
	int *final = &p_j->liste_chevaux[n_cheval-1].final;
		// if cheval[n_cheval] est dans la liste des chevaux actif

	if (*final != 1 && *final != 2)
	{
		int valide = deplacement(coord_y, coord_x, old_y, old_x, val_D, p_j->liste_chevaux[n_cheval-1], plateau, final); // deplacement et modifications des coordonnées

		if (valide == 0) // si il ne peut pas se deplacer c'est déjà gerer
			{
				printf("Vous ne pouvez pas vous sauter par dessus un cheval..\n");
			}
		else //sinon on lui demande si il est sur de vouloir se deplacer en simulant son deplacement
			{
				plateau[old_x][old_y] = '7';
				if (valide == 2)
				{
					eject_cheval(plateau, plateau[*coord_x][*coord_y], *coord_x, *coord_y, liste_joueur);
					printf("Vous avez éjecté un cheval !\n");
				}
				else
				{
					if(joueur_valide_deplacement(plateau, liste_joueur) && valide) // si c'est bon on fait les tests et on delace
					{
						printf("Deplacement réalisé avec succès ! \n");
					}
					else // sinon on remet à 7 la ou la simulation a été faites, et on le deplace a la pos de départ
					{
						plateau[*coord_x][*coord_y] = '7';
						*coord_x = old_x;
						*coord_y = old_y;
						*final =0;
					}
				}
			}
	}
	else
	{
		deplacement_final(plateau, old_x, old_y, &(p_j->liste_chevaux[n_cheval-1]), val_D);
		// Le cheval a gagné :
		// FONCTION A MODIFIER POUR DESACTIVER LES CHEVAUX QUI NE PEUVENT PLUS BOUGER
	/*	if (p_j->liste_chevaux[n_cheval-1].case_x == 7 && p_j->liste_chevaux[n_cheval-1].case_y == 7) {
			cheval_victoire(plateau, &(p_j->liste_chevaux[n_cheval-1]));
		}*/
	}

}

void deplacement_final(char plateau[][15], int pos_x, int pos_y, cheval* cheval, int val_D)
{

  char tab_result[7] = {'7','1','2','3','4','5','6'};
  int num;

  if (check_cheval(plateau, pos_x, pos_y, cheval, val_D) == 0 && cheval_present(pos_x, pos_y, val_D, *cheval, plateau) == 0)
  {

    num = numero_case(*cheval, pos_x, pos_y);

    if(cheval->couleur == 'j')
    {
      plateau[pos_x][cheval->case_y+=val_D] = cheval->couleur;
      cheval_inactif_case_numerote(pos_y+val_D, cheval, val_D, num+val_D, pos_x, plateau);
    }

//-------------------
    else if(cheval->couleur == 'b')
    {
      plateau[cheval->case_x+=val_D][pos_y] = cheval->couleur;
      cheval_inactif_case_numerote(pos_x+val_D, cheval, val_D, num, pos_y, plateau);
    }
    else if(cheval->couleur == 'v')
    {
      plateau[cheval->case_x-=val_D][pos_y] = cheval->couleur;
      cheval_inactif_case_numerote(pos_x-val_D, cheval, val_D, num, pos_y, plateau);

    }
    else if(cheval->couleur == 'r')
    {
      plateau[pos_x][cheval->case_y-=val_D] = cheval->couleur;
      cheval_inactif_case_numerote(pos_y+val_D, cheval, val_D, num, pos_x, plateau);

    }

    plateau[pos_x][pos_y] = tab_result[num];
    cheval->final = 2;
  }

}

void sortir_chevaux(joueur *p_joueur, char plateau[][15], joueur liste_joueur[])
{

    int n_cheval;
    n_cheval = joueur_valide_cheval_sortir(*p_joueur);

    // ON EJECTE LES CHEVAUX PRESENTS SUR CETTE CASE SAUF SI C'EST SA COULEUR
    int debut_x = p_joueur->liste_chevaux[n_cheval-1].case_debut_x;
    int debut_y = p_joueur->liste_chevaux[n_cheval-1].case_debut_y;
    char couleur = p_joueur->liste_chevaux[n_cheval-1].couleur;
  /*  printf("Case debut x = %d\n", debut_x);
    printf("Case debut y = %d\n", debut_y);
    printf("Couleur = %d\n", couleur);
  */
    if(plateau[debut_x][debut_y] != couleur && plateau[debut_x][debut_y] != '7')
    {
      eject_cheval(plateau, plateau[debut_x][debut_y], debut_x, debut_y, liste_joueur);
    }
    // On ajoute le cheval sauf si il a gagné
    if (p_joueur->liste_chevaux[n_cheval-1].case_x != 7 && p_joueur->liste_chevaux[n_cheval-1].case_y != 7)
    {
      ajouter_cheval_actif(p_joueur, n_cheval, plateau);
      printf("Vous pouvez re-jouer !   \n");
    }
    else
    {
      printf("Vous avez déja gagné avec ce cheval !\n");
    }
}

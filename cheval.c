#include <stdio.h>
#include <stdlib.h>
#include "headers/cheval.h"


int deplacement(int *coord_x, int *coord_y, int val_D)	{
	int droite, gauche, bas, haut;
	int incr=1;
	int pas_valide = 0;

	while(incr <= val_D && pas_valide != 1) {

		droite=0;
		gauche=0;
		bas=0;
		haut=0;

		if ( (*coord_y == 0 && 6 <= *coord_x&&*coord_x <=7) || (*coord_y==6 && 8 <= *coord_x&&*coord_x <= 13) || (0<=*coord_x&&*coord_x<= 5 && *coord_y == 6) ){
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

		if (droite==1) {
            *coord_x+=1;
		}
		else if(gauche==1){
            *coord_x-=1;
		}
		else if(bas == 1){
            *coord_y+=1;
		}
		else if (haut==1){
            *coord_y-=1;
		}

		/* if (plateau[y][x] == 7) { incre ++ }  else if (incr == Val_D) { pion se fait ejecter} else{ valide = 0} ===> test valide ou pas */

		  incr++;

}
	/*	if valide=1{*/
	return 1;
	/*	else{
		return 0;
	} */

}
// a la fin plateau[*coord_y][*coord_x] = 'j';

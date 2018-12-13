C=gcc

main: joueur.o sauvegarde.o cheval.o jeu.o interface.o plateau.o main.c
	$(C) joueur.o sauvegarde.o cheval.o jeu.o interface.o plateau.o main.c -o petit_chevaux -Wall
joueur.o: headers/joueur.h joueur.c 
	$(C) -c joueur.c 
sauvegarde.o: headers/sauvegarde.h headers/joueur.h  sauvegarde.c
	$(C) -c sauvegarde.c
jeu.o: headers/jeu.h headers/interface.h headers/sauvegarde.h headers/plateau.h jeu.c
	$(C) -c jeu.c
interface.o: headers/interface.h headers/plateau.h headers/sauvegarde.h interface.c
	$(C) -c interface.c
plateau.o: headers/plateau.h  plateau.c 
	$(C) -c plateau.c
cheval.o: headers/plateau.h headers/interface.h cheval.c
	$(C) -c cheval.c 
clean:
	rm *.o

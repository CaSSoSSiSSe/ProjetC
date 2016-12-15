#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#define FRANCE +1
//#include "statique2.h"

/*void processusFils()
{
	Pbm image;
	pid_t pid_fils;
	pid_fils = fork();
	if (pid_fils == 0)
	{
		printf("\n Je suis le fils !\n");
		choixAleatoireImage(&image);
		exit(0);
	} else {
		printf("\n Je suis le père !\n");
	}
	wait(NULL);
	return EXIT_SUCCESS;
}*/

void definir_heure()
{
        time_t temps;			//
        struct tm date;			//

        time(&temps);			//
        date = *gmtime(&temps);		//

	FILE * historique;		//
	historique = fopen ("historique.txt", "a+");	//ouvre le fichier historique.txt et permet d'ecrire dedans

        fprintf(historique, "%s", ctime(&temps));	//ecrit l'heure dans le fichier dur
}

void choixAleatoireImage(/*Pbm* pointeur_structure*/)
{
	FILE * historique;
	historique = fopen ("historique.txt", "a+");    //ouvre le fichier historique.txt et permet d'ecrire dedans
	int nombre_aleatoire;
	int nombre2;
//	char *fichier_a_ouvrir[] = {"ex1.pbm", "ex2.pbm", "ex3.pbm", "j.pbm", "licorne.pbm", NULL};
	srand(time(NULL));				//initialise le random
	nombre_aleatoire = rand();			//notre variable prend une valeur aléatoire
	nombre2 = nombre_aleatoire %5;			//a l'aide du modulo, notre variable prend une valeur comprise entre 0 et 4
//	switch(nombre)

	if (nombre2 == 0)
	{
//		strcpy(pointeur_structure->nom_image, "ex1.pbm");
		fprintf(historique, "image1 ");		//ecrit le nom de l'image dans l'historique
		printf("image1 ");
	} else if (nombre2 == 1)
	{
//		strcpy(pointeur_structure->nom_image, "ex2.pbm");
		fprintf(historique, "image2 ");         //ecrit le nom de l'image dans l'historique
		printf("image2 ");
	}else if (nombre2 == 2)
	{
//		strcpy(pointeur_structure->nom_image, "ex3.pbm");
		fprintf(historique, "image3 ");         //ecrit le nom de l'image dans l'historique
		printf("image3 ");
	} else if (nombre2 == 3)
	{
//		strcpy(pointeur_structure->nom_image, "j.pbm");
		fprintf(historique, "image4 ");         //ecrit le nom de l'image dans l'historique
		printf("image4 ");
	} else if (nombre2 == 4)
	{
//		strcpy(pointeur_structure->nom_image, "licorne.pbm");
		fprintf(historique, "image5 ");         //ecrit le nom de l'image dans l'historique
		printf("image5 ");
	}
	fclose (historique);
}

int main()
{// ici le random de l'écran
	int nombre;
	int nombre_aleatoire;

//	char *programme[]={"test", NULL};

	FILE * historique;
	historique = fopen ("historique.txt", "a+");

	srand(time(NULL));				//initialise le random
	nombre_aleatoire = rand();                      // Notre variable prend une valeur aléatoire
	nombre = nombre_aleatoire %3;                   // A l'aide du modulo, notre variable prend une valeur comprise entre 0 et 4    switch(nombre)

	if (nombre == 0)
	{
//		processusFils();
//		execv("test", programme);
		printf("statique ");
		fprintf(historique, "%s","statique ");         //ecrit le type de l'ecran de veille, ici statique,  dans l'historique
		choixAleatoireImage();		//appel fonction qui permet de lancer un random sur l'image a lancer dans l'ecran de veille statique
		definir_heure();		//appel fonction qui permet d'afficher l'heure dans l'historique
	} else if (nombre == 1)
	{
		printf("dynamique ");
		fprintf(historique, "%s", "dynamique ");	//ecrit le type de l'ecran de veille, ici dynamique,  dans l'historique
		definir_heure();		//appel fonction qui permet d'afficher l'heure dans l'historique

	} else if (nombre == 2)
	{
		printf("interactif ");
		fprintf(historique, "%s", "interactif ");	//ecrit le type de l'ecran de veille, ici interactif,  dans l'historique
		definir_heure();		//appel fonction qui permet d'afficher l'heure dans l'historique
	}
	fclose (historique);
	return 0;
}

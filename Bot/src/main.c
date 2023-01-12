#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include "rlutil.h"
#define MAXWORDS 5
#define MAXCHARS 128

int main(){
	SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
	srand(time(NULL)); 
	static const char keywords[MAXWORDS][MAXCHARS] = {"exit","Putin","btc","iphone","game"};
	static const char btc1[MAXWORDS][MAXCHARS] = {"[Bot] :\tYou'll get rich if you get one of those. And you can share it with me"};
	char cadena[MAXCHARS]="";
	char *word;
	int i=0;
	bool find = false;


	printf("\tWelcome to the future my friend\n");
	printf("\t\tEduBot is Here\n");
	printf("------------------------------------------------\n\n");

	printf("Introduce una de estas palabras: exit, Putin, btc, iphone, game\n\n");

	printf("[USER]:\t");
	fgets(cadena, MAXCHARS, stdin);
	cadena[strcspn(cadena, "\n")] = 0; //Para limpiar el buffer

	word = strtok(cadena, " "); //? Fragmento la frase del usuario
	while (word != NULL) { //! Filtro para buscar una palabra en la frase de usuario
		find = false;
		i=0;
		while (i <= MAXWORDS){ //* Bucle para compara palabras
			if(strcmpi(keywords[i],word)==0){
				find = true;
				break;
			}
			i++;
		}
		if (find){break;}
		word = strtok(NULL, " ");
	}
	if(find)
	{
		setColor(RED);
		printf("%s\n",btc1);
	}else{
		printf("No se encontró\n");
	}

	getch();
	return 0;
}

//  && strstr(word,keywords[i])!=NULL

// fgets(cadena,llargada,stdin);
// cadena[strcspn(cadena, "\n")] = 0; Para limpiar el buffer


// strlen(cad) - Cuenta
// strcat(cad1,cad2) - Concatena
// strcpy(cad1,cad2) - Machaca
// strncpy(cad1,cad2,longitud) - Machaca controlando el tamaño de la palabra
// strcmp(cad1,cad2) - Compara (Case Sensitive)
// strcmpi(cad1,cad2) - Compara (Case Insesitive)
// strstr(cad1,cad2) - Busca dentro de la cadena principal
// strtok(cad1, dilimitador) - Sirve para separar las palabras. 
// Ej: word = strtok(cadena," ");
// while (word != NULL) {
//     printf("%s\n", word);
//     word = strtok(NULL, " ");
// }

//! Frases del BOT
//? BTC
// "[Bot] :\tYou'll get rich if you get one of those. And you can share it with me."
// "[Bot] :\tThe Bitcoin is a cryptocurrency that now has a value of 19.029,60 $"
// "[Bot] :\tAre you a cryptobro? Because I am..."
//? Iphone
// "[Bot] :\tThe iphone is a very overrated brand, and very expensive."
// "[Bot] :\tDo you hate apple people? Because I do."
// "[Bot] :\tI was created by someone who has an iphone. I hate him :)"
//? GAME
// "[Bot] :\tI love video games. My favorite is sekiro, I should try it."
// "[Bot] :\tI love video games. My favorite is sekiro, I should try it."
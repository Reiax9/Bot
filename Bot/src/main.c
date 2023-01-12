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
	char cadena[MAXCHARS]="";
	char *word, *Words;
	int i=0,length=0,lengthKey=0,resul=0;
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
			length = strlen(word);
			lengthKey = strlen(keywords[i]);
			if (length == lengthKey && (strcmpi(keywords[i],word)==0 || strcmpi(keywords[i],word)<0 || strcmpi(keywords[i],word)>0))
			{
				if(strstr(word,keywords[i])!=NULL){
					
					printf("EEES");
					find = true;
					// break;
				}
			}
			
			
			i++;
		}
		if (find){break;}
		word = strtok(NULL, " ");
	}
	if(find)
	{
		printf("Se encontró\n");
	}else{
		printf("No se encontró\n");
	}
	

	printf("\n\nFin\n\n");

	for ( i = 0; i < 3; i++)
	{
		
	}

	getch();
	return 0;
}

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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include "rlutil.h"
#define MAXWORDS 
#define MAXCHARS 
int main(){
	SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
	srand(time(NULL)); 

	static const char paraulesClau[MAXWORDS][MAXCHARS] = {"exit","Putin","btc"}; 

	printf("\tWelcome to the future my friend\n");
	printf("\t\tEduBot is Here\n");
	printf("------------------------------------------------");

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
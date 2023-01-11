#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include "rlutil.h"

int main(){
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	
	srand(time(NULL));

	printf("\tWelcome to the future my friend\n");
	printf("\t\tEduBot is Here\n");
	printf("------------------------------------------------");

	getch();
	return 0;
}

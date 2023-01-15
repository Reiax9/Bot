#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include "rlutil.h"
#define MAXPHRASES 3	
#define MAXWORDS 5
#define MAXRANDOM 5
#define MAXASKRANDOM 5
#define MAXCHARS 128

int main(){
	SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
	srand(time(NULL)); 
	static const char keywords[MAXWORDS][MAXCHARS] = {"exit","PC","btc","iphone","game"};
	//* Frases Bot
	static const char cadBtc[MAXPHRASES][MAXCHARS] = {  "[Bot] : You'll get rich if you get one of those. And you can share it with me.",
														"[Bot] : The Bitcoin is a cryptocurrency that now has a value of 19.029,60 $",
														"[Bot] : Are you a cryptobro? Because I am..."};
	static const char cadPc[MAXPHRASES][MAXCHARS] = {   "[Bot] : PCs are a great advance in technology, thanks to it I exist :D",
													    "[Bot] : I recommend a pc of the msi brand. Just like the same pc I was created.",
														"[Bot] : Speaking about PCs. Never buy a mac..."};
	static const char cadGame[MAXPHRASES][MAXCHARS]  = {"[Bot] : I love video games. My favorite is sekiro, I should try it.",
														"[Bot] : Games like 'Call of Duty' and 'FIFA' are dead. Assimilate it.",
														"[Bot] : I recommend you 'hollow knight' is a very nice indie game and its gameplay is very good."};
	static const char cadIphone[MAXPHRASES][MAXCHARS]= {"[Bot] : The iphone is a very overrated brand, and very expensive.",
														"[Bot] : Do you hate apple people? Because I do.",
														"[Bot] : I was created by someone who has an iphone. I hate him :)"};
	static const char cadExit[MAXPHRASES][MAXCHARS]  = {"[Bot] : Goodbye my friend! i hope to see you later. ;)",
														"[Bot] : see you later bro",
														"[Bot] : Goodbye, I hope you enjoyed talking to me"};
	static const char cadRandom[MAXRANDOM][MAXCHARS] = {"[Bot] : Mmm, maybe you're right but I'm not really sure.",
														"[Bot] : I'm not sure, but I'll do my best to help you.",
														"[Bot] : What you say is possible, but I need more information to continue.",
														"[Bot] : I don't know what to say about that.",
														"[Bot] : I don't know how to respond to that..."};
	static const char cadAsk[MAXASKRANDOM][MAXCHARS] = {"[Bot] : Well, how can I help you?",
														"[Bot] : Anything else you want to tell me?",
														"[Bot] : Do you want to ask me about something?",
														"[Bot] : What else do you want to know?",
														"[Bot] : What else?"};
	char cadena[MAXCHARS]="";
	char *word;
	int i=-1,random,noKnow,ask,length;
	bool find = false;


	printf("\tWelcome to the future my friend\n");
	printf("\t\tReiaxBot is Here\n");
	printf("------------------------------------------------\n\n");

	printf("Enter one of the following words: exit, PC, btc, iphone, game\n\n");
	setColor(RED);
	printf("[Bot] :\tI'm awake. I'm ReiaxBot. I don't know what you want but don't bother too much.\n");
	printf("[Bot] :\tWhat do you want?\n");
	do{
		setColor(CYAN);
		// Input de usuario
		printf("[USER]:\t");
		fgets(cadena, MAXCHARS, stdin);
		cadena[strcspn(cadena, "\n")] = 0; 
		// Elimina el ? para que el filtro pueda encontrar la palabra
		length = strlen(cadena);
		for ( int j = 0; j < length; j++){if (cadena[j] == '?'){ cadena[j] = ' ';}}
		//TODO Busqueda de la palabra
		find = false;
		word = strtok(cadena, " "); //? Fragmento la frase del usuario
		while (word != NULL) { //! Filtro para buscar una palabra en la frase de usuario
			i=0;
			while (i <= MAXWORDS){ //* Bucle para compara palabras
				if(strcmpi(keywords[i],word)==0){ //! Comprueba si es la misma palabra sin importar si es en minusculas o mayusculas
					find = true;
					break;
				}
				i++;
			}
			if (find){break;}
			word = strtok(NULL, " ");
		}
		setColor(RED);	
		if(find)
		{
			random = rand()% MAXPHRASES; // Cambiar numero a una constante de cadena REVISARRRR
			switch (i){
				case 0:printf("%s\n",cadExit[random]);break;//! Respuestas aleatorias de Exit
				case 1:printf("%s\n",cadPc[random]);break; //! Respuestas aleatorias de Pc
				case 2:printf("%s\n",cadBtc[random]);break; //! Respuestas aleatorias de BTC
				case 3:printf("%s\n",cadIphone[random]);break; //! Respuestas aleatorias de Iphone
				case 4:printf("%s\n",cadGame[random]);break; //! Respuestas aleatorias de GAME
			}
			
		}else{
			noKnow = rand()% MAXRANDOM;
			printf("%s\n",cadRandom[noKnow]);	
		}
		if (i != 0){	
			ask = rand()% MAXRANDOM;
			printf("%s\n",cadAsk[ask]);
		}
		
	}while(i != 0);
	getch();
	return 0;
}



//  && strstr(word,keywords[i])!=NULL

// random = rand()% 4; Hace random del 0 al 3

// fgets(cadena,llargada,stdin);
// cadena[strcspn(cadena, "\n")] = 0; Para limpiar el buffer


// strlen(cad) - Cuenta
// strcat(cad1,cad2) - Concatena
// strcpy(cad1,cad2) - Machaca
// strncpy(cad1,cad2,longitud) - Machaca controlando el tama�o de la palabra
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
// "[Bot] :\tGames like 'Call of Duty' and 'FIFA' are dead. Assimilate it."
// "[Bot] :\tI recommend you 'hollow knight' is a very nice indie game and its gameplay is very good."
//? PC
// "[Bot] :\tPCs are a great advance in technology, thanks to it I exist :D" df
// "[Bot] :\tI recommend a pc of the msi brand. Just like the same pc I was created." ed
// "[Bot] :\tSpeaking about PCs. Never buy a mac..."
//? EXIT
// "[Bot] :\tGoodbye my friend! i hope to see you later. ;)"
// "[Bot] :\tsee you later bro"
// "[Bot] :\tGoodbye, I hope you enjoyed talking to me"
//? RESPUEST RANDOM
// "[Bot] :\tMmm, maybe you're right but I'm not really sure."
// "[Bot] :\tI'm not sure, but I'll do my best to help you."
// "[Bot] :\tWhat you say is possible, but I need more information to continue."
// "[Bot] :\tI don't know what to say about that."
// "[Bot] :\tI don't know how to respond to that..."
//? PREGUNAS RANDOM
// "[Bot] :\tWell, how can I help you?"
// "[Bot] :\tAnything else you want to tell me?"
// "[Bot] :\tDo you want to ask me about something?"
// "[Bot] :\tWhat else do you want to know?"
// "[Bot] :\tWhat else?"
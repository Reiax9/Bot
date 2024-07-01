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
	static const char auxkeys[MAXWORDS][MAXCHARS] = {"no","help"};
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
	static const char cadHelp[MAXRANDOM][MAXCHARS] = {	"[Bot] :\tIf you wish to exit, type 'Exit'.",
														"[Bot] :\tIf you need help with pc, take it to a technician or watch a video tutorial.",
														"[Bot] :\tIf you need help with bitcoin, better to get out of the market.",
														"[Bot] :\tIf you need help with the purchase of an iphone, count me out.", 
														"[Bot] :\tIf you need help passing games, check out specialized guides on those games."
														};
	static const char cadNo[MAXRANDOM][MAXCHARS] = {	"[Bot] :\tIf you want to exit, then exit by typing 'Exit'.",
														"[Bot] :\tif it doesn't work, buy another PC.",
														"[Bot] :\tAnything that has to do with bitcoin, I disavow it .",
														"[Bot] :\tI don't know anything about iphone or apple.", 
														"[Bot] :\tif you don't want to talk about games, then let's not talk about them."
														};
														
	char cadena[MAXCHARS]="";
	char *word;
	int i=0,random,noKnow,ask,length;
	int z=0,y=-1; //? Para saber cuando encuentran la keyword. El -1 es para que el usuario pulsa enter no salga del programa.
	bool find = false;
	bool aux = false;
	bool exit = false;


	printf("\tWelcome to the future my friend\n");
	printf("\t\tReiaxBot is Here\n");
	printf("------------------------------------------------\n\n");

	printf("Enter one of the following words: exit, PC, btc, iphone, game\n\n");
	printf("With these words: No o help\n\n");
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
		for ( int j = 0; j < length; j++){if (cadena[j] == '?' || cadena[j] == '!'){ cadena[j] = ' ';}}
		//TODO Busqueda de la palabra
		find = false;
		aux = false;
		exit = false;
		word = strtok(cadena, " "); 
		while (word != NULL) { //! Filtro para buscar una palabra en la frase de usuario
			i=0;
			while (i <= MAXWORDS){ 
				if(strcmpi(keywords[i],word)==0){ 
					find = true;
					y=i; // Guardamos la vuelta para saber que frase escoger en los switchs
				}else if(strcmpi(auxkeys[i],word)==0){ //? Añadimos nueva linea para encontrar el help y no
					aux = true;
					exit = true; //? Esto impide mas adelatne que salga del programa
					z=i; // Guardamos la vuelta para saber que frase escoger en los switchs
				}
				i++;
			}
			//if (find){break;}
			word = strtok(NULL, " ");
		}
		//? Respuestas del Bot
		setColor(RED);	
		if(find && aux)
		{
			switch (z)
			{
			case 0:printf("%s\n",cadNo[y]);break; //! Respuestas con NO
			case 1:printf("%s\n",cadHelp[y]);break; //! Respuestas con HELP
			}
				
		}else if(find){
			random = rand()% MAXPHRASES; 
			switch (y){
				case 0:printf("%s\n",cadExit[random]);break;//! Respuestas aleatorias de Exit
				case 1:printf("%s\n",cadPc[random]);break; //! Respuestas aleatorias de Pc
				case 2:printf("%s\n",cadBtc[random]);break; //! Respuestas aleatorias de BTC
				case 3:printf("%s\n",cadIphone[random]);break; //! Respuestas aleatorias de Iphone
				case 4:printf("%s\n",cadGame[random]);break; //! Respuestas aleatorias de GAME
			}

		}else{
			noKnow = rand()% MAXRANDOM;
			printf("%s\n",cadRandom[noKnow]); //! Respuestas random
		}
		// Preguntas aleatorias
		if (y != 0 || exit){	
			ask = rand()% MAXRANDOM;
			printf("%s\n",cadAsk[ask]);
		}
		
	}while(y != 0 || exit);

	getch();
	return 0;
}

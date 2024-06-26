#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED

#include <stdio.h> 
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

typedef struct{ 

	SDL_Surface *background;
	SDL_Surface *question; 
	SDL_Surface *reponses[3]; 
	SDL_Surface *button;
	SDL_Surface *button_s;

	int pos_selected;
	SDL_Rect pos_question;
	SDL_Rect pos_reponse1;
	SDL_Rect pos_reponse2; 
	SDL_Rect pos_reponse3; 
	int num_question;
	
	SDL_Rect pos_reponse1txt; 
	SDL_Rect pos_reponse2txt;
	SDL_Rect pos_reponse3txt;


	int positionVraiReponse; 
	TTF_Font *police; 
	TTF_Font *police1;
	
		
	SDL_Surface *image_clock;  
	SDL_Rect pos_image_clock;
	SDL_Rect single_Clock;
	int clock_num;

}Enigme;
void afficherEnigme(Enigme e,SDL_Surface *ecran);
void genererEnigme(Enigme *e,char *nomfichier);
void animerEnigme(Enigme *e);

#endif

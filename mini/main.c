/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date may 9, 2024
*
* Testing program for background scrollilng
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#include "minimap.h"
int main(int argc, char *argv[])
{
    
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(SDL_INIT_AUDIO);
	 TTF_Init();
	 
	


	int temp;
	int run=1;
	int i;
	int redimensionnement=19;
	SDL_Event event;
	int det=-1;
	minimap m;
	char url[20];
	
	personne p;
	background b;

        
       int minimap_width = SCREEN_WIDTH;
       int minimap_height = SCREEN_HEIGHT;
	
	SDL_Surface *screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE);
	SDL_Surface *mask=IMG_Load("mask.jpg");
	SDL_Surface *back=IMG_Load("game.jpg");
	SDL_Surface *hero=IMG_Load("joueur.png");

	SDL_Rect PositionBack;
	PositionBack.x=0;
	PositionBack.y=0;
	PositionBack.w=back->w;
	PositionBack.h=back->h;

	SDL_Rect PositionHero ;
	PositionHero.x=0;
	PositionHero.y=550;
	PositionHero.w=hero->w;
	PositionHero.h=hero->h;
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	Mix_Music* music=Mix_LoadMUS("music.mp3"); 
	int volume;
	Mix_PlayMusic(music, -1);
		

	initmap(&m);
	SDL_EnableKeyRepeat(500, 30);	
	while(run!=0)
	{
	
		SDL_BlitSurface(mask,NULL,screen,&PositionBack);		
		SDL_BlitSurface(back,NULL,screen,&PositionBack);		
		afficherMinimap(m,screen);
		SDL_BlitSurface(hero,NULL,screen,&PositionHero);	
		temp=SDL_GetTicks();
		afficherTemps(temp,screen);
		SDL_Flip(screen);
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				
				case SDL_QUIT:
				run=0;
				break;
				case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_RIGHT:
					
					if (PositionHero.x<=screen->w-hero->w)
					{
						if(collision_parfaite(mask,PositionHero )!=3)
						PositionHero.x+=3;
					}	
					break;
					case SDLK_LEFT:
					
					
						if(collision_parfaite(mask,PositionHero )!=1)
						PositionHero.x-=3;
					

					break;
					case SDLK_UP:
					
						if(collision_parfaite(mask,PositionHero )!=2)
						PositionHero.y-=3;
						
					break;
					case SDLK_DOWN:
					
						if(collision_parfaite(mask,PositionHero )!=4)
						PositionHero.y+=3;
						
					break;
					case SDLK_ESCAPE:
					run=0;
					break;
					sauvegarder(p, b, "donnees.bin");
					charger(&p, &b, "donnees.bin");

				}	
			}
				MAJMinimap(PositionHero, &m, redimensionnement);
		}
		animateminimap(&m);
		
	}
 
       

	SDL_FreeSurface(m.image[0]);
	SDL_FreeSurface(back);
	SDL_FreeSurface(hero);
	SDL_FreeSurface(mask);

	Mix_CloseAudio();	
	TTF_Quit();
	SDL_Quit();
	return 0;
}



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "ES.h"


int main() {
	
	image  load_new;
	enemy adam;
	objet bonus;
	hero ahmed;
	SDL_Surface * ecran;
	SDL_Event event;
	int x=0,y=600;
	
	
    // Initialize SDL for video, audio, and text
if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    printf("Echec d'initialisation de SDL : %s\n", SDL_GetError());
    // Return or exit the program if SDL initialization fails
}

printf("SDL est initialisé avec succès.\n");

// Initialize SDL_ttf for text rendering
if (TTF_Init() != 0) {
    fprintf(stderr, "SDL_ttf initialization failed: %s\n", TTF_GetError());
    // Quit SDL and exit the program if SDL_ttf initialization fails
    SDL_Quit();

}

// Initialize SDL_mixer for sound
if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    fprintf(stderr, "SDL_mixer initialization failed: %s\n", Mix_GetError());
    // Quit SDL_ttf, SDL, and exit the program if SDL_mixer initialization fails
    TTF_Quit();
    SDL_Quit();
  
}
 ecran = SDL_SetVideoMode(1280,719,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
		if (ecran ==NULL)
		{
			fprintf(stderr, "Echec de creation de la fenetre de 300*300: %s.\n", SDL_GetError());
			
		}
int mouvment=-1;
int running=0;
printf("SDL initialized successfully.\n");
 
init_image(&load_new);


initialiser_objet(&bonus);
adam=InitEnemy( adam,x, y);
int a=0;
int b=0;
ahmed.image=IMG_Load("ahmed.png");
ahmed.pos.x=140;
ahmed.pos.y=600;
int k=0;
int coe=1;
int c=1;

while (running==0) {
   
    	
    	
	SDL_BlitSurface(load_new.img,NULL,ecran,&load_new.pos1);
	if(adam.catched==0)
		SDL_BlitSurface(ahmed.image,NULL,ecran,&ahmed.pos);
	
	afficher_objet(&bonus,ahmed,ecran,coe,adam);

	SDL_Delay(200);
	a+=1;
	while(SDL_PollEvent(&event))
	{
	
		switch (event.type)
        {
        case SDL_QUIT:
           running=1;
            break;
  	
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                running=1;
                break;
            
            case SDLK_RIGHT:
            	
            	
            	k=1;
		mouvment=0;
                break;
            case SDLK_UP: 
              
                mouvment=1;  
                 break;
            case SDLK_DOWN:
            mouvment=2;
            break;
            case SDLK_SPACE:
            
            
            mouvment=1;   
                 break;
            }
          break;
            }
             
            
            }
            if((mouvment==0)||(mouvment==1)||(mouvment==2)&&adam.catched==0)
            {
            adam=MoveEnemy(adam,ahmed,a);
             adam=AnimateEnemy(adam,ecran,&mouvment);
             
            }
            
             SDL_Delay(200);
            AfficherEnemy(adam,ecran);
             SDL_Flip(ecran);
          //afficher hero  
        if(adam.catched==0)
        {
    	if(mouvment==0)
    		{
    		ahmed.pos.x+=10;
    		}
    	else if(mouvment==1&&(15<=ahmed.pos.y))
    		{
    		ahmed.pos.y-=15;
    		}
    	else if(mouvment==2&&(15<=ahmed.pos.y))
    	{
    	ahmed.pos.y+=15;
    	mouvment=-1;
    	}
    	}
       int coe=Collision_Bounding_Box (ahmed,  bonus );
     
        
         diedennemi(adam,c);
            }
       free(load_new.img);
       liberer_entite(adam,bonus);
   
       
  return 0;
}

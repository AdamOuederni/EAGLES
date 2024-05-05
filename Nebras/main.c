#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"

int main()
{
	
	SDL_Surface * ecran=NULL;
	ecran = SDL_SetVideoMode(1000,1000, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	int continuer=1,winn=0;
	SDL_Event event;

	SDL_Surface *win;
	SDL_Surface *lost;
	SDL_Rect pos;
        pos.x=160;
        pos.y=330;
	 Enigme e;
	genererEnigme(&e,"questions.txt");
	win=IMG_Load("img/youwin.png");
	lost=IMG_Load("img/youlost.png");


	while(continuer){	
 		animerEnigme(&e);
		afficherEnigme(e,ecran);
	
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type)
			{
				case SDL_QUIT:
				{	
                                   continuer=0;

				}
				case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{	
					case SDLK_a:
					e.pos_selected=1;
					break ; 
					
					case SDLK_b:
					e.pos_selected=2;
					break ; 
					
					case SDLK_c:
					e.pos_selected=3;
					break ; 
					
					case SDLK_RETURN:


							if(winn==1){
							printf("You win\n");
							SDL_BlitSurface(win, NULL, ecran,&pos);
							SDL_Flip(ecran);
							
							}else{	
							SDL_BlitSurface(lost, NULL, ecran, &pos);
							SDL_Flip(ecran);
							printf("You lost\n");	
							}
							SDL_Delay(2000);
						return 0;
					break ; 

				}break;
				case SDL_MOUSEMOTION:
				{
					printf("Souris en position %d %d\n",event.motion.x, event.motion.y);
				}
			case SDL_MOUSEBUTTONUP:
				{
					if((event.motion.x>375 && event.motion.x<615)&&(event.motion.y>520 && event.motion.y<610))
					{
						e.pos_selected=1;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							if(winn==1){
							printf("You win\n");
							SDL_BlitSurface(win, NULL, ecran,&pos);
							SDL_Flip(ecran);
							
							}else{	
							SDL_BlitSurface(lost, NULL, ecran, &pos);
							SDL_Flip(ecran);
							printf("You lost\n");	
							}
							SDL_Delay(2000);

							return 0;
						} 	 
					}
					else if((event.motion.x>178 && event.motion.x<411)&&(event.motion.y>649 && event.motion.y<734))
					{
						e.pos_selected=2;
						if (event.button.button == SDL_BUTTON_LEFT)
						{	
							if(winn==1){
							printf("You win\n");
							SDL_BlitSurface(win, NULL, ecran,&pos);
							SDL_Flip(ecran);
							
							}else{
							SDL_BlitSurface(lost, NULL, ecran, &pos);
							SDL_Flip(ecran);
							printf("You lost\n");							
							}
							SDL_Delay(2000);

							return 0;
						} 
					}
					else if((event.motion.x>568 && event.motion.x<800)&&(event.motion.y>656 && event.motion.y<731))
					{
						e.pos_selected=3;
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							if(winn==1){
							printf("You win\n");
							SDL_BlitSurface(win, NULL, ecran,&pos);
							SDL_Flip(ecran);
							
							}else{
							SDL_BlitSurface(lost, NULL, ecran, &pos);
							SDL_Flip(ecran);
							printf("You lost\n");						
							}
							SDL_Delay(2000);

							return 0;
						} 					
					}
				}
				break;
			}
		}
		 
		if(e.positionVraiReponse==e.pos_selected)
		{
		winn=1;
		}
		else
		{
		winn=0;
		}
		}
		
}




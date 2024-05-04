#include "headers.h"

int main( int argc, char* args[] )
{
	int x,y,x1,y1,i,difficulty=0,share=0,speed=3,once=0;
	int level=0, delayonce=0, delayonce1=0;
	Uint32 current=0, delay_start_time, current1, delay_start_time1;		//delay on button selection
	int done=0;
	Mix_Music *easy, *medium, *hard;
	SDL_Surface *ecran;
	image bg, bg2,bg3,bg4,bg5,bg6, desert,desert1;
	SDL_Event event;
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == -1) {
		printf("Could not initialize SDL: %s.\n", SDL_GetError());
		return -1;
	}
	 
	ecran = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF );
	
	//image initialisation
	init_bg1(&bg,"./Media/bg1.png",800,2909);
	init_bg2(&bg2,"./Media/bg1.png",800,2909);
	init_bg1(&bg3,"./Media/bg2.png",1087,3840);
	init_bg2(&bg4,"./Media/bg2.png",1087,3840);
	init_bg1(&bg5,"./Media/bg3.png",1000,5596);
	init_bg2(&bg6,"./Media/bg3.png",1000,5596);
	init_img(&desert,"./Media/desert.png",0,HEIGHT-70,0,0,0,0,70,75);
	init_img(&desert1,"./Media/desert.png",WIDTH/2,HEIGHT-70,0,0,0,0,70,75);
	//audio initialisation
	initialise_audio();
	easy = Mix_LoadMUS("./Media/easy.wav");
	medium= Mix_LoadMUS("./Media/medium.wav");
	hard= Mix_LoadMUS("./Media/hard.wav");

	//game loop
	while(done!=1) {
		//Display	
		switch(level){
			case 0:
				if (share==1){
					afficher(bg,ecran);		
					afficher(bg2,ecran);	
					afficher(desert,ecran);
					afficher(desert1,ecran);
				}
				else
					afficher(bg,ecran);
					afficher(desert,ecran);
			break;
			case 1:
				if (share==1){
					afficher(bg3,ecran);		
					afficher(bg4,ecran);	
					afficher(desert,ecran);
					afficher(desert1,ecran);
				}
				else
					afficher(bg3,ecran);
					afficher(desert,ecran);
			break;
			case 2:
				if (share==1){
					afficher(bg5,ecran);		
					afficher(bg6,ecran);
					afficher(desert,ecran);	
					afficher(desert1,ecran);
				}
				else
					afficher(bg5,ecran);
					afficher(desert,ecran);
			break;
			
		}

		//events
		while(SDL_PollEvent(&event)) {
			switch(event.type){
				case SDL_KEYDOWN :
					switch(event.key.keysym.sym){
							case SDLK_LCTRL :
							speed=6;
							break;
						case SDLK_u :
							if (difficulty==0) {
								difficulty =1;
								once=0;
							}
							else if (difficulty==1) {
								difficulty =2;
								once=0;
							}
							break;
						case SDLK_i:
							if (difficulty==1) {
								difficulty =0;
								once=0;
							}
							else if (difficulty==2) {
								difficulty =1;		
								once=0;
							}		
							break ;
						case SDLK_UP:
							y=-1;
							break;
						case SDLK_DOWN:
							y=1;
							break;
						case SDLK_RIGHT:
							x=1;
							break;
						case SDLK_LEFT:
							x=-1;
							break;
						case SDLK_z:
							y1=-1;
							break;
						case SDLK_s:
							y1=1;
							break;
						case SDLK_d:
							x1=1;
							break;
						case SDLK_q:
							x1=-1;
							break;
						case SDLK_f :
							if (share==0){
								share=1;
							}
							else {
								share=0;
							}
							break;
						case SDLK_k :
							if (level==0) {
								level =1;
								share=0;
							}
							else if (level==1) {
								level =2;
								share=0;
							}
							break;
						case SDLK_j:
							if (level==1) {
								level =0;
								share=0;
							}
							else if (level==2) {
								level =1;	
								share=0;
							}		
							break ;
					}
					break;
				case SDL_KEYUP:
					switch(event.key.keysym.sym){
						case SDLK_RIGHT:
							x=0;
							break;
						case SDLK_LEFT:
							x=0;
							break;
						case SDLK_UP:
							y=0;
							break;
						case SDLK_DOWN:
							y=0;
							break;
						case SDLK_z:
							y1=0;
							break;
						case SDLK_s:
							y1=0;
							break;
						case SDLK_d:
							x1=0;
							break;
						case SDLK_q:
							x1=0;
							break;
						case SDLK_LCTRL :
							speed=3;
							break;
					}
					break;
				case SDL_QUIT:
					done = 1;
					break;
			}
		}
		play_music(difficulty,&once,easy,medium,hard);
		switch(share){
			case 0 :
				if(level == 0) {
					scroll(&bg,x,y,speed);
					animer(&desert, 6);
					if(desert.posscreen.x< WIDTH)
						desert.posscreen.x+=15;
					else if (delayonce == 0){
						current = SDL_GetTicks();
						delayonce = 1;
						delay_start_time = current;
					}
					else if(delay(3000,delay_start_time)==0){
							desert.posscreen.x=0;
							delayonce=0;
					}
				}
				if(level == 1) {
					scroll(&bg3,x,y,speed);
					animer(&desert, 6);
					if(desert.posscreen.x< WIDTH)
						desert.posscreen.x+=15;
					else if (delayonce == 0){
						current = SDL_GetTicks();
						delayonce = 1;
						delay_start_time = current;
					}
					else if(delay(3000,delay_start_time)==0){
							desert.posscreen.x=0;
							delayonce=0;
					}
				}
				if(level == 2) {
					scroll(&bg5,x,y,speed);
					animer(&desert, 6);
					if(desert.posscreen.x< WIDTH)
						desert.posscreen.x+=15;
					else if (delayonce == 0){
						current = SDL_GetTicks();
						delayonce = 1;
						delay_start_time = current;
					}
					else if(delay(3000,delay_start_time)==0){
							desert.posscreen.x=0;
							delayonce=0;
					}
				}
			break;
			
			case 1 :
				if(level == 0){	
					scroll(&bg,x,y,speed);
					scroll(&bg2,x1,y1,speed);
					animer(&desert, 6);
					animer1(&desert1, 6);
					if(desert.posscreen.x< (WIDTH/2)-160)
						desert.posscreen.x+=15;
					else if (delayonce == 0){
						current = SDL_GetTicks();
						delayonce = 1;
						delay_start_time = current;
					}
					else if(delay(3000,delay_start_time)==0){
							desert.posscreen.x=0;
							delayonce=0;
					}
					if(desert1.posscreen.x< WIDTH)
						desert1.posscreen.x+=15;
					else if (delayonce1 == 0){
						current1 = SDL_GetTicks();
						delayonce1 = 1;
						delay_start_time1 = current1;
					}
					else if(delay(3000,delay_start_time1)==0){
							desert1.posscreen.x=WIDTH/2;
							delayonce1=0;
					}
				}
				if(level == 1){	
					scroll(&bg3,x,y,speed);
					scroll(&bg4,x1,y1,speed);
					animer(&desert, 6);
					animer1(&desert1, 6);
					if(desert.posscreen.x< (WIDTH/2)-160)
						desert.posscreen.x+=15;
					else if (delayonce == 0){
						current = SDL_GetTicks();
						delayonce = 1;
						delay_start_time = current;
					}
					else if(delay(3000,delay_start_time)==0){
							desert.posscreen.x=0;
							delayonce=0;
					}
					if(desert1.posscreen.x< WIDTH)
						desert1.posscreen.x+=15;
					else if (delayonce1 == 0){
						current1 = SDL_GetTicks();
						delayonce1 = 1;
						delay_start_time1 = current1;
					}
					else if(delay(3000,delay_start_time1)==0){
							desert1.posscreen.x=WIDTH/2;
							delayonce1=0;
					}
				}
				if(level == 2){	
					scroll(&bg5,x,y,speed);
					scroll(&bg6,x1,y1,speed);
					animer(&desert, 6);
					animer1(&desert1, 6);
					if(desert.posscreen.x< (WIDTH/2)-160)
						desert.posscreen.x+=15;
					else if (delayonce == 0){
						current = SDL_GetTicks();
						delayonce = 1;
						delay_start_time = current;
					}
					else if(delay(3000,delay_start_time)==0){
							desert.posscreen.x=0;
							delayonce=0;
					}
					if(desert1.posscreen.x< WIDTH)
						desert1.posscreen.x+=15;
					else if (delayonce1 == 0){
						current1 = SDL_GetTicks();
						delayonce1 = 1;
						delay_start_time1 = current1;
					}
					else if(delay(3000,delay_start_time1)==0){
							desert1.posscreen.x=WIDTH/2;
							delayonce1=0;
					}
				}
			break;
		}
		SDL_Flip(ecran);
	}
	SDL_FreeSurface(ecran);
	SDL_FreeSurface(bg.img);
	SDL_FreeSurface(bg2.img);
	SDL_FreeSurface(bg3.img);
	SDL_FreeSurface(bg4.img);
	SDL_FreeSurface(bg5.img);
	SDL_FreeSurface(bg6.img);
	SDL_FreeSurface(desert.img);
	SDL_FreeSurface(desert1.img);
	Mix_FreeMusic(easy);
	Mix_FreeMusic(medium);
	Mix_FreeMusic(hard);
	Mix_CloseAudio();
	SDL_Quit();
	return 0;
}





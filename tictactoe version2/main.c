#include"tictactoe.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
int main()
{
	int boocle=1, nbTentative=3,nbJoueur=0,nbMachine=0 ;
	SDL_Surface *screen;
	SDL_Event event;
	xo t;
	int mat[3][3];
	background back;
	image table;
	rotozoom z;
	Mix_Music *son;
	srand(time(NULL));
	TTF_Init();
	 // Initialisation background du jeu 
	InitialiserBackground(&back);
	InitiliserTable(&table);
	 // Initialisation du jeu Tic Tac Toe
	InitialiserXO(&t);
	Init_rotozoom(&z);
	// Initialisation de la fenêtre SDL
	screen = SDL_SetVideoMode( 900 ,600 , 32 , SDL_HWSURFACE | SDL_DOUBLEBUF );
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
	son=Mix_LoadMUS("song/Y2meta.app - موسيقى بيانو - لو كنت نغمض عينيا _ عزف فاطمة الزبيدي (128 kbps).mp3");
	Mix_PlayMusic(son,-1);
	if(screen != NULL ) printf("helloo\n");
	while(boocle == 1 ){
			// Affichage de l'arrière-plan
			AfficherBackground(screen , back);
			AfficherTable(screen , table);
			AfficherXO( screen , t ); // Affichage du jeu Tic Tac Toe
			AfficheNavigation(screen , t);
			Annimation(&back);// Affichage de l'animation de l'arrière-plan
			AfficherRoto(screen,&z);
			if(Atilganger(t.tab) == 1 )
			{	
				nbJoueur++;
				nbTentative--;
				clearTable(&t);
			}
			else if(Atilganger(t.tab) == 2 )
			{	nbMachine++;
				nbTentative--;
				clearTable(&t);
			}
			else if(egalite(t.tab)==1)
			{
				nbTentative--;
				clearTable(&t);
			}
			if(nbTentative==0){
				if(nbJoueur > nbMachine){
					z.t=1;
					
						clearTable(&t);
					}
				else if(nbJoueur < nbMachine)
				{
					z.t=2;
	
						clearTable(&t);
				}
				else
				{
					z.t=3;
					clearTable(&t);
				}
			}
			printf("joueur : %d\n",nbJoueur);
			printf("machine : %d\n",nbMachine);
			printf("nbTentative : %d\n",nbTentative);
			while( SDL_PollEvent (&event) ){
				// Gestion du clic de souris
				switch(event.type){
					
					case SDL_QUIT:
						boocle = 0;
					break;
					case SDL_MOUSEBUTTONUP:
						for(int i=0; i<3;i++){
							for(int j=0;j<3;j++){
								if(event.motion.x > t.pos[i][j].x && event.motion.x < t.pos[i][j].x + t.pos[i][j].w
								&&event.motion.y > t.pos[i][j].y && event.motion.y < t.pos[i][j].y + t.pos[i][j].h ){
									
									if(t.tab[i][j] == 0){
										if(t.n==0){
											t.tab[i][j] = 1;//X
											t.n=1;
										}
									}
											
									
								}
							}
						}
						// Si c'est le tour de l'IA, elle joue
						if(t.n==1){
							ia(&t);
							t.n=0;
						}
						
					break;
					case SDL_KEYDOWN:
						
						if(event.key.keysym.sym == SDLK_RIGHT ){
								
							t.selection++;
							if( t.selection == 9 ){
								t.selection = 0;
							}
						}
						else if(event.key.keysym.sym == SDLK_LEFT ){
								
							t.selection--;
							if( t.selection <= -1 ){
								t.selection = 8;
							}
						}
						else if(event.key.keysym.sym == SDLK_DOWN ){
								
							t.selection += 3 ;
							if( t.selection == 9   ){
								t.selection -= 9 ;
							}
						}
						else if(event.key.keysym.sym == SDLK_UP ){
								
							t.selection -= 3 ;
							if( t.selection <= -1   ){
								t.selection += 9 ;
							}
						}
					else if(event.key.keysym.sym == SDLK_RETURN){
						
						if(t.selection >= 0 && t.selection <= 2 ){
							if( t.tab[0][t.selection] == 0 ){
								t.tab[0][t.selection] = t.n+1;
								if(t.n==0){
									t.n=1;
								}
								
							}
							
						}
						else if(t.selection >= 3 && t.selection <= 5){
							
							if( t.tab[1][t.selection -3 ] == 0 ){
								t.tab[1][t.selection - 3 ] = t.n+1;
								if(t.n==0){
									t.n=1;
								}
								
							}
							

						}
						else {
							if( t.tab[2][t.selection - 6 ] == 0 ){
								t.tab[2][t.selection - 6 ] = t.n+1;
								if(t.n==0){
									t.n=1;
								}
								
							}
							
						}
					}
											
					if(t.n==1){
							ia(&t);
							t.n=0;
					}
					break;

				}				
				
			}
	
		SDL_Flip(screen);
		SDL_Delay(70);// Délai pour contrôler la vitesse de l'animation

	}
	SDL_FreeSurface(screen);
	LibererTous(&back,&table);

}

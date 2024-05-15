#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <SDL/SDL_rotozoom.h>
#include <time.h>
typedef struct
{
	SDL_Surface *img[10];
	SDL_Rect pos;
	int nbmax;
	int index;
}background;
typedef struct
{
	int x,y,w,h;	
}position;

typedef struct 
{
	SDL_Surface *img;
	SDL_Rect pos;
}image;

typedef struct
{
	SDL_Surface *img[2];
	SDL_Rect pos[3][3];
	int tab[3][3];
	int n;
	int selection;
}xo;
typedef struct
{
	SDL_Surface *txt;
	char ch[20];
	SDL_Rect posText;
	SDL_Color couleur;
	TTF_Font *police;
}text;
typedef struct
{
	SDL_Surface *zoom[10];
	SDL_Surface *rotation[10];
	text goodjob;
	text hardluck;
	int t,d,r;
}rotozoom;
void InitialiserBackground(background *b);
void AfficherBackground(SDL_Surface *screen , background b);
void Annimation(background *b);

void InitiliserTable(image *im);
void AfficherTable(SDL_Surface *screen , image im);
void clearTable(xo *t);
void LibererTous(background *b,image *im);


void InitialiserXO(xo *t);
void AfficherXO(SDL_Surface *screen , xo t);
void AfficheNavigation(SDL_Surface *screen , xo t);
int Atilganger(int tab[3][3]);
void ia(xo *t);
int egalite(int tab[3][3]); 
void Init_Good(text *good);
void Init_Hard(text *hard);
void Init_rotozoom(rotozoom *zoom);
void AfficherRoto(SDL_Surface *screen , rotozoom *z);


#endif

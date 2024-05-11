#ifndef HEADERS_H
#define HEADERS_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define HEIGHT 719
#define WIDTH 1290
#define SPEED 	2
#define ACCELERATION 4

typedef struct{
	SDL_Rect cam;
	SDL_Rect posscreen;
	SDL_Surface *img;
}image;
typedef struct
{
	SDL_Surface *txt;
	SDL_Rect pos;
	SDL_Color color;
	TTF_Font *police;
} text;

typedef struct{
	int value;
	Uint32 time;
	char name[20];
	text txt;
}score;

//images
void init_bg1(image *img, char* path, int h, int w);
void init_bg2(image *img, char* path, int h, int w);
void init_img(image *img, char* path, int x, int y, int a, int b, int h, int w, int h1,int w1);
void animer(image *img, int frames);
void animer1(image *img, int frames);
void afficher(image img, SDL_Surface *ecran);
void play_music(int difficulty, int *once, Mix_Music *easy, Mix_Music *medium, Mix_Music *hard);
void scroll(image *bg,int x,int y, int speed);
void scroll1(image *bg,int x,int y, int speed);
void initialise_audio();
void initialise_text(text *txt, char* path, int size, int r, int g, int b,int x, int y);
void display_text(SDL_Surface *screen, text txt, char *str);
void release_text(text *txt);
void init_score(score *s);
void displayscore(score s, SDL_Surface *ecran);
void save_score( const score *data) ;
score get_highest_score() ;
int PointInRect(int px, int py, SDL_Rect r) ;
int delay(int ms, Uint32 debut);


#endif

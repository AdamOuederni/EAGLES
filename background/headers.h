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


//images
void init_bg1(image *img, char* path, int h, int w);
void init_bg2(image *img, char* path, int h, int w);
void init_img(image *img, char* path, int x, int y, int a, int b, int h, int w, int h1,int w1);
void animer(image *img, int frames);
void animer1(image *img, int frames);
void afficher(image img, SDL_Surface *ecran);
void play_music(int difficulty, int *once, Mix_Music *easy, Mix_Music *medium, Mix_Music *hard);
void scroll(image *bg,int x, int y, int speed);
void initialise_audio();

int delay(int ms, Uint32 debut);


#endif
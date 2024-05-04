#include "headers.h"

void init_bg1(image *img, char* path, int h, int w)
{
	img->img = IMG_Load(path);
	if (img->img == NULL)
	{
		printf("Unable to load background image %s\n", SDL_GetError());
		return;
	}
	
	img->posscreen.x = 0;
	img->posscreen.y = 0;
	img->posscreen.h= h;
	img->posscreen.w= w;
	img->cam.x = 0;
	img->cam.y = h-HEIGHT;
	img->cam.h = HEIGHT;
	img->cam.w = WIDTH;
}
void init_bg2(image *img, char* path, int h, int w)
{
	img->img = IMG_Load(path);
	if (img->img == NULL)
	{
		printf("Unable to load background image %s\n", SDL_GetError());
		return;
	}
	
	img->posscreen.x = WIDTH/2;
	img->posscreen.y = 0;
	img->posscreen.h= h;
	img->posscreen.w= w;
	img->cam.x = 0;
	img->cam.y = h-HEIGHT;
	img->cam.h = HEIGHT;
	img->cam.w = WIDTH;
}

void init_img(image *img, char* path, int x, int y, int a, int b, int h, int w, int h1,int w1)
{
	img->img = IMG_Load(path);
	if (img->img == NULL)
	{
		printf("Unable to load background image %s\n", SDL_GetError());
		return;
	}
	
	img->posscreen.x = x;
	img->posscreen.y = y;
	img->posscreen.h= h;
	img->posscreen.w = w;
	img->cam.x = a;
	img->cam.y = b;
	img->cam.h = h1;
	img->cam.w = w1;
}
 
void afficher(image img, SDL_Surface *ecran)
{
	SDL_BlitSurface(img.img, &img.cam, ecran, &img.posscreen);
}

void play_music(int difficulty, int *once, Mix_Music *easy, Mix_Music *medium, Mix_Music *hard)
{
	if (difficulty==0 && *once==0){
		Mix_HaltMusic();
		Mix_PlayMusic(easy, -1);
		*once=1;
	}
	else if (difficulty==1 && *once==0){
		Mix_HaltMusic();
		Mix_PlayMusic(medium, -1);
		*once=1;
	}
	else if (difficulty==2 && *once==0){
		Mix_HaltMusic();
		Mix_PlayMusic(hard, -1);
		*once=1;
	}
}
void scroll(image *bg, int x,int y , int speed)
{
    // Scroll the background image
  switch (x) {
    case 1:
      if (bg->cam.x <= bg->posscreen.w -(WIDTH+ speed)) {
        bg->cam.x += speed;
      }
      break;
    case -1:
      if (bg->cam.x >= speed) {
        bg->cam.x -= speed;
      }
      break;
  }
  switch (y) {
    case 1:
      if (bg->cam.y <= bg->posscreen.h -(HEIGHT+ speed)) {
        bg->cam.y += speed;
      }
      break;
    case -1:
      if (bg->cam.y >= speed) {
        bg->cam.y -= speed;
      }
      break;
  }
}

void animer(image *img, int frames)
{
    static Uint32 last_time = 0; // initialize last_time to 0 on first call
    Uint32 current_time = SDL_GetTicks();
    if (current_time - last_time > 160) {
        last_time = current_time;
        if (img->cam.x <= frames * img->cam.w) {
            img->cam.x += img->cam.w;
        } else {
            img->cam.x = 0;
        }
    }
}
void animer1(image *img, int frames)
{
    static Uint32 last_time = 0; // initialize last_time to 0 on first call
    Uint32 current_time = SDL_GetTicks();
    if (current_time - last_time > 160) {
        last_time = current_time;
        if (img->cam.x <= frames * img->cam.w) {
            img->cam.x += img->cam.w;
        } else {
            img->cam.x = 0;
        }
    }
}

void initialise_audio()
{
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		printf("%s\n", SDL_GetError());
	}
}

int delay(int ms,Uint32 debut) {
    Uint32 fin = SDL_GetTicks();
    if(fin-debut>ms)
    	return 0;
    else return 1;
}








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
void scroll1(image *bg, int x,int y , int speed)
{
    // Scroll the background image
  switch (x) {
    case 1:
      if (bg->cam.x <= bg->posscreen.w -((WIDTH/2)+ speed)) {
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

void initialise_text(text *txt, char* path, int size, int r, int g, int b,int x, int y)
{
	txt->police = TTF_OpenFont(path, size);
	txt->color.r = r;
	txt->color.g = g;
	txt->color.b = b;
	txt->pos.x = x;
	txt->pos.y = y;
}
void display_text(SDL_Surface *screen, text txt, char str[] )
{
	txt.txt = TTF_RenderText_Blended(txt.police, str, txt.color);
	SDL_BlitSurface(txt.txt, NULL, screen, &txt.pos);
}
void release_text(text *txt)
{
	TTF_CloseFont(txt->police);
	TTF_Quit();
}

void init_score(score *score){
	score->value=0;
	initialise_text(&score->txt, "./Media/arial.ttf", 50, 255, 255, 255,0, 0);
}

void displayscore(score score, SDL_Surface *ecran) {
    char output[100]; // Make sure the buffer is large enough to hold the concatenated string
    sprintf(output, "Name: %s - Score: %d", score.name, score.value);
    display_text(ecran, score.txt, output);
}
void save_score(const score *data) {
    FILE *file = fopen("scores.txt", "a"); // Open the file in append mode (creates the file if it doesn't exist)

    if (file == NULL) {
        printf("Error opening file scores.txt for writing.\n");
        return;
    }

    // Write score data to the file in text format
    fprintf(file, "%d %s %u\n", data->value, data->name, data->time);

    fclose(file); // Close the file
}

score get_highest_score() {
    FILE *file = fopen("scores.txt", "r"); // Open the file in read mode

    if (file == NULL) {
        printf("Error opening file scores.txt for reading.\n");
        score error_info = {-1, 0}; // Return error information if file opening fails
        strcpy(error_info.name, "Error");
        return error_info;
    }

    int highest_score = -1; // Initialize the highest score to a negative value

    score current_score;
    score result = {-1, 0}; // Return error information if file opening fails
	 strcpy(result.name, "");

    // Read each entry from the file and compare scores to find the highest one
    while (fscanf(file, "%d %s %u", &current_score.value, current_score.name, &current_score.time) == 3) {
        if (current_score.value > highest_score) {
            highest_score = current_score.value; // Update the highest score
            result = current_score;
        }
    }

    fclose(file); // Close the file
    score res;
	init_score(&res);
	res.value=result.value;
	res.time=result.time;
	strcpy(res.name, result.name);
    return res;
}
int PointInRect(int px, int py, SDL_Rect r) {
    int result = (px >= r.x && px < r.x + r.w && py >= r.y && py < r.y + r.h);
    return result;
}







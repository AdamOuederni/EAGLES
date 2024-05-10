#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_W 1920
#define SCREEN_H 1080
typedef struct enemy
{
  SDL_Surface *image[2][4];
  SDL_Surface *image2;
  SDL_Surface *catche;
  SDL_Surface *imageActuel;
  SDL_Rect positionO;
  SDL_Rect position;
  int etat;
  int catched;
  int frame;
  int died;

}enemy;


typedef struct hero
{
  SDL_Surface *image; 
  SDL_Rect pos;
  int heromoved;
}hero;

typedef struct objet
{
SDL_Surface *image;
SDL_Rect pos;
}objet;
typedef struct{
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Surface *img;
}image;
void init_image(image * a);
void initialiser_objet(objet *bonus);
void afficher_objet(objet *bonus, hero ahmed,SDL_Surface *ecran,int coe,enemy adam);
enemy InitEnemy(enemy ennemi,int x, int y);
void  AfficherEnemy(enemy ennemi,SDL_Surface *ecran);
enemy AnimateEnemy(enemy ennemi,SDL_Surface *ecran,int *b);
enemy MoveEnemy(enemy ennemi,hero ahmed,int a);
int Collision_Bounding_Box (hero ahmed , objet bonus );
enemy diedennemi(enemy ennemi,int c);
void liberer_entite(enemy adam,objet bonus);

#endif




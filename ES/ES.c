#include <SDL/SDL.h>//inclure SDL.h  pour permettre au programme d'être portable sur tous les systèmes.
#include <SDL/SDL_image.h>//Pour manipuler des images ayants des types autre que bmp
 #include <SDL/SDL_mixer.h> //Pour manipuler de l’audio.
#include <SDL/SDL_ttf.h>//Pour manipuler des textes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "ES.h"


void init_image(image * a) {
    a->img = IMG_Load("load_new.jpg");
    if (a->img == NULL) {
        printf("Error loading image\n");
        return;
    }
    
    a->pos1.x = 0;
    a->pos1.y = 0;
    a->pos1.w = a->img->w;
    a->pos1.h = a->img->h;
     a->pos2.x = 0;
    a->pos2.y = 0;
    a->pos2.w =(SCREEN_W);
    a->pos2.h = (SCREEN_H);
}

void initialiser_objet(objet *bonus)
{
bonus->image=NULL;
bonus->image=IMG_Load("money.png");
bonus->pos.x=800;
bonus->pos.y=0;
}
void afficher_objet(objet *bonus, hero ahmed ,SDL_Surface *ecran,int coe,enemy adam) {
if(coe==1&&(adam.catched==0))
{
	srand(time(NULL));
        bonus->pos.x = rand() % (1280 - bonus->pos.w); 
        bonus->pos.y = rand() % (719 - bonus->pos.h);
    
    

    if (bonus->pos.x + bonus->pos.w > 1280) {
        bonus->pos.x = 1280 - bonus->pos.w;
    }
    if (bonus->pos.y + bonus->pos.h > 719) {
        bonus->pos.y = 719- bonus->pos.h;
    }
    

    SDL_BlitSurface(bonus->image, NULL, ecran, &(bonus->pos));
    

    
}

}



enemy InitEnemy(enemy ennemi,int x, int y)
{
  ennemi.image[0][0]=IMG_Load("run1.png");
  ennemi.image[0][1]=IMG_Load("run2.png");
  ennemi.image[0][2]=IMG_Load("run3.png");
  ennemi.image[0][3]=IMG_Load("run4.png");
  

  
   
  ennemi.imageActuel=ennemi.image[0][0];
  ennemi.image[1][0]=IMG_Load("jump1.png");
  ennemi.image[1][1]=IMG_Load("jump2.png");
  ennemi.image[1][2]=IMG_Load("jump3.png");
  ennemi.image[1][3]=IMG_Load("jump4.png");
  ennemi.catche=IMG_Load("catch.png");
  ennemi.imageActuel=ennemi.image[0][0];
  ennemi.position.x=x;
  ennemi.position.y=y;
  ennemi.positionO=ennemi.position;
  ennemi.frame=0;
  ennemi.died=0;
  ennemi.catched=0;
  return ennemi;
}

void  AfficherEnemy(enemy adam ,SDL_Surface *ecran )
{

  SDL_BlitSurface(adam.imageActuel,NULL,ecran,&adam.position);

}
enemy AnimateEnemy(enemy ennemi,SDL_Surface *ecran,int *b )
{
int mouvment=ennemi.etat;
{
if(mouvment==2)
	{
	ennemi.imageActuel=ennemi.image[0][0];
}
else{
if(ennemi.frame==3)
{
ennemi.frame=0;
ennemi.imageActuel=ennemi.image[mouvment][ennemi.frame];
ennemi.etat=-1;
*b=-1;
}
else
{
ennemi.frame++;
ennemi.imageActuel=ennemi.image[mouvment][ennemi.frame];
}
}
 }
 

  if(ennemi.catched==1)  {     
    ennemi.imageActuel=ennemi.catche;
   }
   
  return ennemi;

}



enemy MoveEnemy(enemy ennemi,hero ahmed,int a)
{

int distance,c;
    distance=ahmed.pos.x-ennemi.position.x;
 if(ennemi.catched==0)
if(distance<70&&(ennemi.position.y<ahmed.pos.y+ahmed.pos.h))
	ennemi.catched=1;
else 
	ennemi.catched=0;
if(140<=distance)
{
printf("a");
c=rand()%3+2;

switch(c)
{

break;
case 2:if (4<=ennemi.position.x)
	{ennemi.position.x-=rand()%10+5;
	ennemi.etat=0;
	}
break;
case 3:ennemi.position.y-=rand()%3+1;
ennemi.etat=1;
break;
}
}


if(100<=distance<140)
{
printf("b");
c=rand()%2+1;

switch(c)
{
case 1:ennemi.position.x+=rand()%15+10;
ennemi.etat=0;
break;
case 2:if(590<ennemi.position.y){
ennemi.position.y-=rand()%4+1;
ennemi.etat=1;
}
else 

{
ennemi.position.y+=rand()%4+1;
ennemi.etat=1;
}
break;
}
}


if(75<distance<100)
{
printf("c");
c=rand()%2+1;

switch(c)
{
case 1:ennemi.position.y-=rand()%4+1;
ennemi.etat=1;
break;
case 2:if (4<=ennemi.position.x)
	{ennemi.position.x+=rand()%15+10;
	ennemi.etat=0;
	}
break;

}
}
if(70<distance<=75)
{
c=rand()%2+1;

switch(c)
{
case 1://printf("same position");

break;
case 2:if (4<=ennemi.position.x)
	{ennemi.position.x+=rand()%5+1;
	ennemi.etat=0;
	}
break;

}
}
return ennemi;

}
enemy diedennemi(enemy ennemi,int c){

  if (c==0){

    ennemi.image[0][0]=NULL;
    ennemi.image[0][1]=NULL;
    ennemi.image[0][2]=NULL;
    ennemi.imageActuel=NULL;
    ennemi.catche=NULL;

    ennemi.image[1][0]=NULL;
    ennemi.image[1][1]=NULL;
    ennemi.image[1][2]=NULL;
    ennemi.died=1;
  }
  return ennemi;
}
int Collision_Bounding_Box (hero ahmed , objet bonus )
{
int coe;
if((ahmed.pos.x<=bonus.pos.x)&&(bonus.pos.x<=ahmed.pos.x+ahmed.pos.w))
	if((ahmed.pos.y<=bonus.pos.y)&&(bonus.pos.y<=ahmed.pos.y+ahmed.pos.h))
	    {coe=0;
	    
	    }
else 
	coe=1;

return coe;
}
void liberer_entite(enemy adam,objet bonus)
{
  free(adam.image[0][0]);
       free(adam.image[0][1]);
       free(adam.image[0][2]);
       free(adam.image[0][3]);
       free(adam.image[1][0]);
       free(adam.image[1][1]);
       free(adam.image[1][2]);
       free(adam.image[1][3]);
       free(adam.catche);
       free(bonus.image);
       

}

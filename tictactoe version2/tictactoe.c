#include "tictactoe.h"


void InitialiserBackground(background *b)
{
	b->nbmax=6;

	b->img[0] = IMG_Load("image/0.jpg");
	b->img[1] = IMG_Load("image/1.jpg");
	b->img[2] = IMG_Load("image/2.jpg");
	b->img[3] = IMG_Load("image/3.jpg");
	b->img[4] = IMG_Load("image/4.jpg");
	b->img[5] = IMG_Load("image/5.jpg");

	for(int i=0;i< b->nbmax ;i++){
		if(b->img[i]==NULL) {printf("Erreur \n");}
		else printf("CV !! \n");	
	}
	b->pos.x=0;
	b->pos.y=0;
	b->pos.w=1200;
	b->pos.h=600;

	b->index=0;
}
void AfficherBackground(SDL_Surface *screen , background b)
{
	SDL_BlitSurface(b.img[b.index] , NULL , screen , &b.pos);
}
void Annimation(background *b)
{
	b->index++;
	if(b->index == b->nbmax) b->index=0;
}

void InitiliserTable(image *im)
{
	im->img = IMG_Load ("image/table.png");
	if(im->img!=NULL) printf("CV !!\n");
	im->pos.x=200;
	im->pos.y=70;
	im->pos.w=813;
	im->pos.h=572;
}
void AfficherTable(SDL_Surface *screen , image im)
{
	SDL_BlitSurface(im.img , NULL , screen , &im.pos);
}
void LibererTous(background *b,image *im)
{
	for(int i=0;i<b->nbmax;i++){
		SDL_FreeSurface(b->img[i]);
	}
	SDL_FreeSurface(im->img);
}


void InitialiserXO(xo *t)
{
	t->img[0] = IMG_Load("image/x.png");
	t->img[1] = IMG_Load("image/o.png");
	t->n=0;
	t->selection=-1;
	
	position p;
	p.x=200;
	p.y=150;
	p.w=150;
	p.h=150;
	
	for(int i=0; i<3;i++){
		p.x=250;
		for(int j=0;j<3;j++){
			t->pos[i][j].x=p.x;
			t->pos[i][j].y=p.y;
			t->pos[i][j].w=p.w;
			t->pos[i][j].h=p.h;
			
			t->tab[i][j]=0;
		p.x=p.x+p.w;
		}
	p.y=p.y+p.h;
	}
	
}


void AfficherXO(SDL_Surface *screen , xo t)
{
	for(int i=0 ; i<3 ; i++){
		for(int j=0 ; j<3 ; j++){
	
			if(t.tab[i][j]!=0){

				SDL_BlitSurface(t.img[t.tab[i][j]-1] , NULL , screen , &t.pos[i][j]);
			}
		}
	}
}
void AfficheNavigation(SDL_Surface *screen , xo t)
{
	if(t.selection >= 0 && t.selection <= 2 ){
	
		SDL_BlitSurface(t.img[t.n] , NULL , screen , &t.pos[0][t.selection]);
	
	}
	else if(t.selection >= 3 && t.selection <= 5){

		SDL_BlitSurface(t.img[t.n] , NULL , screen , &t.pos[1][t.selection]-3);

	}
	else {
		SDL_BlitSurface(t.img[t.n] , NULL , screen , &t.pos[2][t.selection]-6);
	}
}

int Atilganger(int tab[3][3])
{
	for (int i=0 ; i<2 ; i++) {
		if(tab[0][0]==i+1 && tab[0][1]==i+1 && tab[0][2]==i+1 ||
		   tab[1][0]==i+1 && tab[1][1]==i+1 && tab[1][2]==i+1 ||
		   tab[2][0]==i+1 && tab[2][1]==i+1 && tab[2][2]==i+1 ||
		   tab[0][0]==i+1 && tab[1][0]==i+1 && tab[2][0]==i+1 ||
		   tab[0][1]==i+1 && tab[1][1]==i+1 && tab[2][1]==i+1 ||
		   tab[0][2]==i+1 && tab[1][2]==i+1 && tab[2][2]==i+1 ||
		   tab[0][0]==i+1 && tab[1][1]==i+1 && tab[2][2]==i+1 ||
		   tab[0][2]==i+1 && tab[1][1]==i+1 && tab[2][0]==i+1 )
		{
		
			return ( i+1 ) ;
		}

	}
	return 0;

}

void Init_Good(text *good)
{
	good->police = TTF_OpenFont ("Ubuntu-Bold.ttf" , 20);
	good->couleur.r=0;good->couleur.g=0;good->couleur.b=0;
	strcpy(good->ch , "Good Job !!!");
	good->posText.x=0;
	good->posText.y=0;
	good->txt = TTF_RenderText_Blended(good->police,good->ch,good->couleur);
}
void Init_Hard(text *hard)
{
	hard->police = TTF_OpenFont ("Ubuntu-Bold.ttf" , 10);
	hard->couleur.r=0;hard->couleur.g=0;hard->couleur.b=0;
	strcpy(hard->ch , "Hard Luck !!!");
	hard->posText.x=0;
	hard->posText.y=0;
	hard->txt = TTF_RenderText_Blended(hard->police,hard->ch,hard->couleur);
}
void Init_rotozoom(rotozoom *zoom)
{
	Init_Good(&zoom->goodjob);
	Init_Hard(&zoom->hardluck);
	for(int i=0;i<10;i++){
		zoom->zoom[i] = rotozoomSurface(zoom->goodjob.txt , 0 , i+1 , 1);
		zoom->rotation[i] = rotozoomSurface(zoom->hardluck.txt , 25*i , 1 ,1);
	}
	zoom->t=0;
	zoom->d=0;
	zoom->r=0;
}
void clearTable(xo *t)
{
	for(int i=0 ; i<3 ; i++){
		for(int j=0 ; j<3 ; j++){
			t->tab[i][j]=0;
			
		}
	}
}
int egalite(int tab[3][3])
{
	for(int i=0 ; i<3 ; i++){
		for(int j=0 ; j<3 ; j++){
			if(tab[i][j]==0){
				return 0;
			}
		}
	}
	return 1;
}
void ia(xo *t)
{
	int choix=1;
	while(choix==1 && !egalite(t->tab))
	{
		int i = rand()% 3;
		int j = rand()% 3;
		if(t->tab[i][j] == 0) 
		{
			t->tab[i][j] = 2;//O
			choix=0;
		}
	}

}
void AfficherRoto(SDL_Surface *screen , rotozoom *z)
{
	if(z->t!=0){
		if(z->t == 1 ){
			SDL_BlitSurface(z->zoom[z->d] , NULL , screen , &z->goodjob.posText);
		}
		else SDL_BlitSurface(z->rotation[z->d] , NULL , screen , &z->hardluck.posText);
		if(z->r ==0){
			z->d++;
			if(z->d ==9){
				z->r=1;
			}
		}
		else
		{
			z->d--;
			if(z->d == 0){
				z->r=0;
			}
		}
	}
}


























































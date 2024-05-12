#include "enigme.h"


void genererEnigme(Enigme *e,char *nomfichier){   
 

       	srand(time(NULL)); 

	FILE *fquestion=NULL;
	FILE *freponse=NULL;
	FILE *fvraireponse=NULL;
	
	e->pos_selected=0;
	e->background= IMG_Load("img/background.png");
	e->button= IMG_Load("img/button.png");
	e->button_s= IMG_Load("img/button_s.png");

	TTF_Init();


	SDL_Color couleur;      
	couleur.r=0;
	couleur.g=0;
	couleur.b=0;

	e->police = TTF_OpenFont("arial.ttf", 30);
	e->police1 = TTF_OpenFont("arial.ttf", 20);
	  
	char questionn[55];
	

	e->num_question=rand()%4;   

	while(e->num_question==0){

		e->num_question=rand()%4;
	}
	 


	fquestion=fopen(nomfichier,"r");
	if(fquestion!=NULL){

		int test=1;
		while (fgets(questionn, 55, fquestion) &&(test!=e->num_question)){ 
			test++;
		}
		
		fclose(fquestion);
	}
	
	char reponse[15];

	int debut,fin;
    switch(e->num_question)
    {
    	case 1:
    	{
    		debut=0;
    		fin=2;
    		break;
    	}
    	case 2:
    	{
    		debut=3;
    		fin=5;
    		break;
    	}
    	case 3:
    	{
    		debut=6;
    		fin=8;
    		break;
    	}
    }


	freponse=fopen("reponses.txt","r");
	if(freponse!=NULL){

		int test=0;
		while (fgets((reponse), 15, freponse) &&(test<fin)){	
			
			if(test>=debut){
				e->reponses[test-debut]=TTF_RenderText_Blended(e->police1, reponse, couleur);  
			}
			test++;
		}	
		
		fclose(freponse);
	}
	
 
	


	
	fvraireponse=fopen("vraireponses.txt","r+");
	if(fvraireponse!=NULL){
		
		int test=1;
		while (fgets((reponse), 15, fvraireponse)){
			
			if(test==e->num_question){ 
				printf("%s\n",reponse);
				e->reponses[2]=TTF_RenderText_Blended(e->police1, reponse, couleur); 
			}
			test++;
		}
		fclose(freponse);
	}

	e->positionVraiReponse=rand()%4; 

	while(e->positionVraiReponse==0){
		e->positionVraiReponse=rand()%4;
	}
	printf("%d\n",e->positionVraiReponse);

	e->question = TTF_RenderText_Blended(e->police, questionn, couleur);

	e->pos_question.x=270;
	e->pos_question.y=270;
 
	e->pos_reponse1.x=375;
	e->pos_reponse1.y=522;


	e->pos_reponse2.x=177;
	e->pos_reponse2.y=648;

	e->pos_reponse3.x=566;
	e->pos_reponse3.y=651;

	e->pos_reponse1txt.x=375+50;
	e->pos_reponse1txt.y=522+30;

	e->pos_reponse2txt.x=177+50;
	e->pos_reponse2txt.y=648+30;

	e->pos_reponse3txt.x=566+50;
	e->pos_reponse3txt.y=651+30;
	
	
	(*e).image_clock=IMG_Load("clock1.png");  

	e->pos_image_clock.x=500;
	e->pos_image_clock.y=100;
	
	e->single_Clock.w=57;
	e->single_Clock.h=81;
	e->single_Clock.x=0;
	e->single_Clock.y=0;

	e->clock_num=0;

 

}

void afficherEnigme(Enigme e,SDL_Surface *ecran){

	
		
	SDL_BlitSurface(e.background, NULL, ecran, NULL);
 	SDL_BlitSurface(e.image_clock,&(e.single_Clock), ecran, &e.pos_image_clock);
	SDL_BlitSurface(e.question, NULL, ecran, &e.pos_question); 

	

	switch(e.positionVraiReponse){
		case 1:{

			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);
				
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);


			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);

			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);

	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);

				}
			}	
			break;
		}
		case 2:{
			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);


			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);

			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);

	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);

				}
			}
			break;
		}
		case 3:{
			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);


			}
			break;
			case 2:                       
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);

			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);

	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);

				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);


				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);

				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);

				}
			}

			break;
		}
	}
		SDL_Flip(ecran);
	SDL_Delay(100);
}


void animerEnigme(Enigme *e){
		 	
	if (e->clock_num >=0 && e->clock_num <8) {
	e->single_Clock.x=e->clock_num * e->single_Clock.w;
	e->clock_num++;
	}
	
	if ( e->clock_num == 8) {
	e->single_Clock.x=e->clock_num * e->single_Clock.w;
	e->clock_num=0;
	}
 
	 
}

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include"backg.h"


	void initialiser_background(background *backg)
	{
        backg->bg= IMG_Load("Map/map.png");
	backg->mask= IMG_Load("Map/mask.png");
        backg->pos_bg.x=0;
        backg->pos_bg.y=0;       	       
        backg->camera.x=0;
        backg->camera.y=0;
        backg->camera.w=1280;
        backg->camera.h=720;
	backg->direction=0;
	}
	void afficher_background(background backg,SDL_Surface *screen)
	{
	SDL_BlitSurface(backg.bg,&backg.camera,screen,&backg.pos_bg);			
	}	            
	 void scrolling(background *backg,Personne p,int col,int col2,int col3,int col4)
	 {
	 if(backg->direction==2) 
	 {
	if(backg->camera.x>0 && p.pos.pos_Perso.x<=4800 && col==0 && col2==0 && col3==0 && col4==0 && p.up==3) backg->camera.x=backg->camera.x-60;
	if(backg->camera.x>p.pos.pos_Perso.x-640)
	{
	 if(backg->camera.x>0 && p.pos.pos_Perso.x<=4800 && col==0 && col2==0 && col3==0 && col4==0)
	 backg->camera.x=backg->camera.x-10;
	 else if (backg->camera.x>0 && p.pos.pos_Perso.x>4800 && col==0 && col2==0 && col3==0 && col4==0) backg->camera.x=backg->camera.x-1;
	}
	 }
	 else if(backg->direction==1) 
	 {
	if(backg->camera.x<3820 && p.pos.pos_Perso.x>=300 && col==0 && col2==0 && col3==0 && col4==0 && p.up==2)
	 backg->camera.x=backg->camera.x+60;
	if(backg->camera.x+640<p.pos.pos_Perso.x)
	{
	 if(backg->camera.x<3820 && p.pos.pos_Perso.x>=300 && col==0 && col2==0 && col3==0 && col4==0)
	 backg->camera.x=backg->camera.x+10;
	else if (backg->camera.x<3820 && p.pos.pos_Perso.x<300 && col==0 && col2==0 && col3==0 && col4==0) backg->camera.x=backg->camera.x+1;
	
	}
	 }
	 }	 

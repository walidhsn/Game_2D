/**
* @file perso.c
*/
#include <stdio.h>
#include <stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include "perso.h"

void init (Personne * p, int numperso);
/** 
* @brief To initialize the Perso . 
* @param p the Personne
* @return Nothing 
*/ 
void initPerso(Personne *p)
{
    /*//Init score
    p->score.score_Perso=0;
    p->score.barre_score=IMG_Load("Images/Vie/Barre score.png");

    //Init position Barre_score
    p->score.pos_barreScore.x=400;
    p->score.pos_barreScore.y=50;*/

    //Init vie
    p->vie.vie_Perso=100;
    p->vie.nb_vies_Perso=3;
    p->vie.barre_vie=IMG_Load("Images/Vie/Barre Vie.png");
	
    //Init position Barre_vie
    p->vie.pos_viePerso.x=1350;
    p->vie.pos_viePerso.y=50;

    //Init images perso

    //Init image perso mvt droit
    p->img.img_Perso[0][0]=IMG_Load("Mouvement/Droite/mvt_right1.png");
    p->img.img_Perso[0][1]=IMG_Load("Mouvement/Droite/mvt_right2.png");
    p->img.img_Perso[0][2]=IMG_Load("Mouvement/Droite/mvt_right3.png");
    p->img.img_Perso[0][3]=IMG_Load("Mouvement/Droite/mvt_right4.png");
    p->img.img_Perso[0][4]=IMG_Load("Mouvement/Droite/mvt_right5.png");
    p->img.img_Perso[0][5]=IMG_Load("Mouvement/Droite/mvt_right6.png");
    //Init image perso mvt gauche
    p->img.img_Perso[1][0]=IMG_Load("Mouvement/Gauche/mvt_left1.png");
    p->img.img_Perso[1][1]=IMG_Load("Mouvement/Gauche/mvt_left2.png");
    p->img.img_Perso[1][2]=IMG_Load("Mouvement/Gauche/mvt_left3.png");
    p->img.img_Perso[1][3]=IMG_Load("Mouvement/Gauche/mvt_left4.png");
    p->img.img_Perso[1][4]=IMG_Load("Mouvement/Gauche/mvt_left5.png");
    p->img.img_Perso[1][5]=IMG_Load("Mouvement/Gauche/mvt_left6.png");
    //Init image perso mvt saut
    p->img.img_Perso[2][0]=IMG_Load("Mouvement/Haut/mvt_saut2.png");
    //Init image perso mvt bas
    p->img.img_Perso[3][0]=IMG_Load("Mouvement/Bas/mvt_bas.png");
    //Init image perso immobile
    p->img.img_Perso[4][0]=IMG_Load("Mouvement/Idle/Right/Idle_right.png");
    p->img.img_Perso[5][0]=IMG_Load("Mouvement/Idle/Left/Idle_left.png");
    p->img.img_PersoActuel=p->img.img_Perso[4][0];
    //Init position perso
    p->pos.pos_Perso.x=150;
    p->pos.pos_Perso.y=490;
    p->pos.pos_Perso.w=26;
    p->pos.pos_Perso.h=48; 
    p->vitesse=5;
    p->acceleration=0;
    p->up=0;
}
/** 
* @brief To Display the Perso . 
* @param p the Personne
* @param screen the Screen
* @return Nothing 
*/ 
void afficherPerso(Personne p, SDL_Surface * screen_p)
{
        SDL_BlitSurface(p.img.img_PersoActuel,NULL,screen_p,&p.pos.pos_Perso);	
}
/** 
* @brief To move the Perso . 
* @param p the Personne
* @param dt the Uint32
* @param posinit the int
* @return Nothing 
*/ 
void deplacerPerso (Personne *p,Uint32 dt,int posinit)
{
		int dx;				
		
		if(p->img.direction==0)
                {
                    	p->pos.pos_Perso.x+=10;
			if(p->acceleration>0)
		{
		    	dx=(0.5*p->acceleration*(dt*dt))+p->vitesse*dt;
			p->vitesse=dx/dt;			
			p->pos.pos_Perso.x+=p->vitesse;
		}			
                }
		else if(p->img.direction==1)
		{
			p->pos.pos_Perso.x-=10;
			if(p->acceleration>0)
			{			
				dx=(0.5*p->acceleration*(dt*dt))+p->vitesse*dt;
				p->vitesse=dx/dt;			
				p->pos.pos_Perso.x-=p->vitesse;
			}
		
		}
		
}		
/** 
* @brief To Annimate the Perso . 
* @param p the Personne
* @return Nothing 
*/ 
void animerPerso (Personne* p)
{
	if(p->img.direction==0 || p->img.direction==1)
	{
		if(p->img.num==5)
		{
			p->img.num=0;
		}
		else
		{
			p->img.num++;
		}
	}
	else if( p->img.direction==2 || p->img.direction==3 || p->img.direction==4) //
	{
		if(p->img.num>0)
		{
			p->img.num=0;
		}
	}
	
	p->img.img_PersoActuel=p->img.img_Perso[p->img.direction][p->img.num];
}
/** 
* @brief To jump the Perso . 
* @param p the Personne
* @param posinit the int
* @return Nothing 
*/ 
void saut (Personne* p,int dt,int posinit,int s_jump,int col)
{
	int seuil;
	seuil=280;
	
	if(p->up==2)
{
	if(p->up==2 && p->pos.pos_Perso.y>seuil && p->img.direction!=3 && s_jump && (!col || (col && s_jump)))
	{
		p->pos.pos_Perso.y-=100;
		p->pos.pos_Perso.x+=70;
		return;
	}
	
		if(p->pos.pos_Perso.y!=posinit && p->pos.pos_Perso.y<posinit && col )
		{
			p->pos.pos_Perso.y+=(100/20);
			p->pos.pos_Perso.x+=4;		
		}
	
	if(p->pos.pos_Perso.y>=posinit)
				{
					p->pos.pos_Perso.y=posinit;
				}
	if(p->pos.pos_Perso.y==posinit)
	{
		p->up=0;
	}
}
if(p->up==3)
{
	if(p->up==3 && p->pos.pos_Perso.y>seuil && p->img.direction!=3 && s_jump && (!col || (col && s_jump)) )
	{
		p->pos.pos_Perso.y-=100;
		p->pos.pos_Perso.x-=70;
		return;
	}
	
		if(p->pos.pos_Perso.y!=posinit && p->pos.pos_Perso.y<posinit && col )
		{
			p->pos.pos_Perso.y+=(100/20);
			p->pos.pos_Perso.x-=4;		
		}
	
	if(p->pos.pos_Perso.y>=posinit)
				{
					p->pos.pos_Perso.y=posinit;
				}
	if(p->pos.pos_Perso.y==posinit)
	{
		p->up=0;
	}
}

	if(p->up==1 && p->pos.pos_Perso.y>seuil && p->img.direction!=3 && s_jump )
	{
		p->pos.pos_Perso.y-=100;
		return;
	}
			
			if(p->pos.pos_Perso.y!=posinit && p->pos.pos_Perso.y<posinit && !col )
			{
				p->pos.pos_Perso.y+=(100/20);
			}	
		if(p->pos.pos_Perso.y>=posinit)
				{
					p->pos.pos_Perso.y=posinit;
				}
	if(p->pos.pos_Perso.y==posinit)
	{
		p->up=0;
	}


}

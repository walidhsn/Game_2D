/**
* @file ennemi.c
*/
#include "ennemi.h"
/** 
* @brief To initialize and Stock the position of the image of the Ennemi . 
* @param e the Ennemi
* @param e2 the ennemi
* @return Nothing 
*/ 
void initEnnemi(ennemi *e,ennemi *e2)
{
	int i;
	
	e->image_e_d=IMG_Load("ennemi/2.png");
	e->image_e_g=IMG_Load("ennemi/1.png");
	e2->image_e2_d=IMG_Load("ennemi/3.png");
	e2->image_e2_g=IMG_Load("ennemi/4.png");
	e->death=IMG_Load("ennemi/die.png");
	e2->death2=IMG_Load("ennemi/die2.png");
	e->die=0;
	e2->die=0;
	e->posxmin=0;
	e->posxmax=0;
	e2->posymin2=480;
	e2->posymax2=290;
	e->frame=0;
	e2->frame2=0;
	e->pos_eni.x=1680;
	e->pos_eni.y=480;
	e->pos_eni.w=80;
	e->pos_eni.h=60;
	e2->pos_eni2.x=980;
	e2->pos_eni2.y=480;
	e2->pos_eni2.w=80;
	e2->pos_eni2.h=66;
	e->direction=0;	
	e2->direction=0;
	e->pas_d=5;
	e2->pas_d=5;
	for(i=0;i<9;i++)
	{
		e->annim_e1[i].x=0+i*80;
		e->annim_e1[i].y=0;
		e->annim_e1[i].w=80;
		e->annim_e1[i].h=60;
	}
	for(i=0;i<10;i++)
	{
		e2->annim_e2[i].x=0+i*80;
		e2->annim_e2[i].y=0;
		e2->annim_e2[i].w=80;
		e2->annim_e2[i].h=66;
	}
}
void initboss(boss *alien)
{
	alien->image_boss_d=IMG_Load("ennemi/boss.png");
	alien->image_boss_g=IMG_Load("ennemi/boss2.png");
	alien->arrow=IMG_Load("ennemi/arrow1.png");
	alien->frame=0;
	alien->frame1=0;
	alien->frame2=0;
	alien->frame3=0;
	alien->frame4=0;
	alien->pos_boss.x=3300;
	alien->pos_boss.y=465;
	alien->pos_boss.w=45;
	alien->pos_boss.h=55;
	alien->pas_d=5;
	alien->nb_hit=0;
	alien->direction_boss=0;
	alien->state=WAITING;
	alien->pos_arrow.w=36;
	alien->pos_arrow.h=16;
	for(int i=0;i<6;i++) //waiting
	{
		alien->annim_boss_d[0][i].x=4+i*118;
		alien->annim_boss_d[0][i].y=3;
		alien->annim_boss_d[0][i].w=114;
		alien->annim_boss_d[0][i].h=76;
	}
	for(int i=0;i<10;i++) //walking
	{
		alien->annim_boss_d[1][i].x=4+i*118;
		alien->annim_boss_d[1][i].y=85;
		alien->annim_boss_d[1][i].w=114;
		alien->annim_boss_d[1][i].h=76;
	}
	for(int i=0;i<10;i++) //attacking
	{
		alien->annim_boss_d[2][i].x=4+i*118;
		alien->annim_boss_d[2][i].y=167;
		alien->annim_boss_d[2][i].w=114;
		alien->annim_boss_d[2][i].h=76;
	}
	for(int i=0;i<4;i++) //getting hit
	{
		alien->annim_boss_d[3][i].x=4+i*118;
		alien->annim_boss_d[3][i].y=249;
		alien->annim_boss_d[3][i].w=114;
		alien->annim_boss_d[3][i].h=76;
	}
	for(int i=0;i<15;i++) //die
	{
		alien->annim_boss_d[4][i].x=5+i*118;
		alien->annim_boss_d[4][i].y=331;
		alien->annim_boss_d[4][i].w=113;
		alien->annim_boss_d[4][i].h=76;
	}
	//*************************************************************
		for(int i=0;i<5;i++) //waiting
	{
		alien->annim_boss_g[0][i].x=594-i*118;
		alien->annim_boss_g[0][i].y=3;
		alien->annim_boss_g[0][i].w=114;
		alien->annim_boss_g[0][i].h=76;
	}
	for(int i=0;i<10;i++) //walking
	{
		alien->annim_boss_g[1][i].x=1067-i*118;
		alien->annim_boss_g[1][i].y=85;
		alien->annim_boss_g[1][i].w=113;
		alien->annim_boss_g[1][i].h=76;
	}
	for(int i=0;i<10;i++) //attacking
	{
		alien->annim_boss_g[2][i].x=1067-i*118;
		alien->annim_boss_g[2][i].y=167;
		alien->annim_boss_g[2][i].w=114;
		alien->annim_boss_g[2][i].h=76;
	}
	for(int i=0;i<4;i++) //getting hit
	{
		alien->annim_boss_g[3][i].x=358-i*118;
		alien->annim_boss_g[3][i].y=249;
		alien->annim_boss_g[3][i].w=114;
		alien->annim_boss_g[3][i].h=76;
	}
	for(int i=0;i<15;i++) //die
	{
		alien->annim_boss_g[4][i].x=1657-i*118;
		alien->annim_boss_g[4][i].y=331;
		alien->annim_boss_g[4][i].w=113;
		alien->annim_boss_g[4][i].h=76;
	}
}
void afficherboss(boss alien, SDL_Surface * screen)
{
	if(alien.direction_boss==0 && alien.state==WAITING) SDL_BlitSurface(alien.image_boss_d,&alien.annim_boss_d[WAITING][alien.frame],screen,&alien.pos_boss);
	else if(alien.direction_boss==0 && alien.state==FOLLOWING) SDL_BlitSurface(alien.image_boss_d,&alien.annim_boss_d[FOLLOWING][alien.frame1],screen,&alien.pos_boss);
	else if(alien.direction_boss==0 && alien.state==ATTACKING)
	{
		 SDL_BlitSurface(alien.image_boss_d,&alien.annim_boss_d[ATTACKING][alien.frame2],screen,&alien.pos_boss);
		 SDL_BlitSurface(alien.arrow,NULL,screen,&alien.pos_arrow);
	}
	else if(alien.direction_boss==0 && alien.state==HIT) SDL_BlitSurface(alien.image_boss_d,&alien.annim_boss_d[HIT][alien.frame3],screen,&alien.pos_boss);
	else if(alien.direction_boss==0 && alien.state==DIE) SDL_BlitSurface(alien.image_boss_d,&alien.annim_boss_d[DIE][alien.frame4],screen,&alien.pos_boss);	
	//*************
	if(alien.direction_boss==1 && alien.state==WAITING) SDL_BlitSurface(alien.image_boss_g,&alien.annim_boss_g[WAITING][alien.frame],screen,&alien.pos_boss);
	else if(alien.direction_boss==1 && alien.state==FOLLOWING) SDL_BlitSurface(alien.image_boss_g,&alien.annim_boss_g[FOLLOWING][alien.frame1],screen,&alien.pos_boss);
	else if(alien.direction_boss==1 && alien.state==ATTACKING) 
	{
		SDL_BlitSurface(alien.image_boss_g,&alien.annim_boss_g[ATTACKING][alien.frame2],screen,&alien.pos_boss);
		SDL_BlitSurface(alien.arrow,NULL,screen,&alien.pos_arrow);
	}
	else if(alien.direction_boss==1 && alien.state==HIT) SDL_BlitSurface(alien.image_boss_g,&alien.annim_boss_g[HIT][alien.frame3],screen,&alien.pos_boss);
	else if(alien.direction_boss==1 && alien.state==DIE) SDL_BlitSurface(alien.image_boss_g,&alien.annim_boss_g[DIE][alien.frame4],screen,&alien.pos_boss);
	
}	
void animerboss(boss *alien)
{
	
	alien->pos_arrow.y=alien->pos_boss.y+35;
	if((alien->direction_boss==0 ) && alien->state==WAITING)
	{
		alien->frame++;
		if(alien->frame==5)
		alien->frame=0;
		alien->pos_arrow.x=alien->pos_boss.x;
	}
	if((alien->direction_boss==1) && alien->state==WAITING)
	{
		alien->frame++;
		if(alien->frame==5)
		alien->frame=0;
		alien->pos_arrow.x=alien->pos_boss.x+alien->pos_boss.w+20;
	}
	if((alien->direction_boss==0) && alien->state==FOLLOWING)
	{
		alien->frame1++;
		if(alien->frame1==9)
		alien->frame1=0;
		alien->pos_arrow.x=alien->pos_boss.x;
	}
	if((alien->direction_boss==1) && alien->state==FOLLOWING)
	{
		alien->frame1++;
		if(alien->frame1==9)
		alien->frame1=0;
		alien->pos_arrow.x=alien->pos_boss.x+alien->pos_boss.w+20;
	}
	if(alien->direction_boss==0 && alien->state==ATTACKING)
	{
		alien->frame2++;
		if(alien->frame2==9)
		alien->frame2=0;
	   alien->pos_arrow.x-=7;
	}
	if( alien->direction_boss==1 && alien->state==ATTACKING)
	{
		alien->frame2++;
		if(alien->frame2==9)
		alien->frame2=0;
	   alien->pos_arrow.x+=7;
	}
	
	if((alien->direction_boss==0 || alien->direction_boss==1) && alien->state==HIT)
	{
		alien->frame3++;
		if(alien->frame3==3)
		alien->frame3=0;
	}
	if((alien->direction_boss==0 || alien->direction_boss==1) && alien->state==DIE)
	{
		if(alien->frame4<14)
		alien->frame4++;
		if(alien->frame4==14)
		alien->frame4=14;
	}
}

/** 
* @brief To Display the Ennemi . 
* @param e the ennemi 
* @param e2 the ennemi  
* @param screen the screen
* @return Nothing 
*/ 
void afficherEnnemi(ennemi e,ennemi e2, SDL_Surface * screen)
{

      
	if(e.direction==0 &&e.die==0)
	SDL_BlitSurface(e.image_e_d,&e.annim_e1[e.frame],screen,&e.pos_eni);
        if(e.direction==1&& e.die==0)
	SDL_BlitSurface(e.image_e_g,&e.annim_e1[e.frame],screen,&e.pos_eni);

	 if(e.die==1)
	{
	SDL_BlitSurface(e.death,NULL,screen,&e.pos_eni);
	}
      if(e2.die==0)
	{
	if(e2.direction==0)
	SDL_BlitSurface(e2.image_e2_d,&e2.annim_e2[e2.frame2],screen,&e2.pos_eni2);
	if(e2.direction==1)
	SDL_BlitSurface(e2.image_e2_g,&e2.annim_e2[e2.frame2],screen,&e2.pos_eni2);
	}
	else
	SDL_BlitSurface(e2.death2,NULL,screen,&e2.pos_eni2);
}

/** 
* @brief To move the Frame of the Image of the Ennemi . 
* @param e the ennemi 
* @param e2 the ennemi  
* @return Nothing 
*/ 
void animerEnnemi(ennemi *e,ennemi *e2)
{
	//ennemi 1 :
	
	if( e->direction==0)
	{
    	 	e->frame++;    
    		if(e->frame==8)
      		e->frame=0;    
	}
	if( e->direction==1)
	{
    	 	e->frame++;    
    		if(e->frame==8)
      		e->frame=0;    
	}

	//ennemi 2 :

	if( e2->direction==0)
	{
    	 	e2->frame2++;    
    		if(e2->frame2==9)
      		e2->frame2=0;    
	}
	if( e2->direction==1) 
	{
    	 	e2->frame2++;    
    		if(e2->frame2==9)
      		e2->frame2=0;    
	}
}

/** 
* @brief To move The ennemi on the Screen. 
* @param e the ennemi 
* @param e2 the ennemi  
* @return Nothing 
*/ 
void deplacer(ennemi *e,ennemi *e2)
{
	//***eni_1:
	if(e->die==0)
   {
	if(e->pos_eni.x>e->posxmax)
	{	
		e->direction=1;	
	}
	if(e->pos_eni.x<e->posxmin)
	{	
		e->direction=0;
	}
		//***eni_1:
	if(e->direction==0)
	{
		e->pos_eni.x+=e->pas_d;
	}
	if(e->direction==1)
	{
		e->pos_eni.x-=e->pas_d;
	}
   }
	
	//***eni_2:
   if(e2->die==0)
 {
	if(e2->pos_eni2.y<e2->posymax2)
	{	
		e2->direction=1;	
	}
	if(e2->pos_eni2.y>e2->posymin2)
	{	
		e2->direction=0;
	}

	//***eni_2:
	if(e2->direction==0)
	{
		e2->pos_eni2.y-=e2->pas_d;
	}
	if(e2->direction==1)
	{
		e2->pos_eni2.y+=e2->pas_d;
	}
 }

}
/** 
* @brief To test the Collision between The ennemi & Perso . 
* @param e the ennemi 
* @param p the Personne  
* @return int 
*/ 
int collisionBB(Personne p,ennemi e)
{
	int col=0;
	if( ((p.pos.pos_Perso.x+p.pos.pos_Perso.w)<=e.pos_eni.x+26) || (p.pos.pos_Perso.x+26>=(e.pos_eni.x+e.pos_eni.w)) ||(p.pos.pos_Perso.y>=(e.pos_eni.y+e.pos_eni.h)) ||((p.pos.pos_Perso.y+p.pos.pos_Perso.h)<=e.pos_eni.y))
	{
		return col;
	}	
	else return (col=1);

}
/** 
* @brief To test the Collision between The ennemi2 & Perso . 
* @param e2 the ennemi 
* @param p the Personne  
* @return int
*/ 
int collisionBB2(Personne p,ennemi e)
{
	int col=0;
	if( ((p.pos.pos_Perso.x+p.pos.pos_Perso.w)<=e.pos_eni2.x+26) || (p.pos.pos_Perso.x+26>=(e.pos_eni2.x+e.pos_eni2.w)) ||(p.pos.pos_Perso.y>=(e.pos_eni2.y+e.pos_eni2.h))||((p.pos.pos_Perso.y+p.pos.pos_Perso.h)<=e.pos_eni2.y))
	{
		return col;
	}	
	else return (col=1);
}
int collisionboss(Personne p,boss alien)
{
	int col=0;
	if( ((p.pos.pos_Perso.x+p.pos.pos_Perso.w)<=alien.pos_boss.x+47) || (p.pos.pos_Perso.x>=(alien.pos_boss.x+alien.pos_boss.w+24)) ||(p.pos.pos_Perso.y>=(alien.pos_boss.y+alien.pos_boss.h))||((p.pos.pos_Perso.y+p.pos.pos_Perso.h)<=alien.pos_boss.y+21))
	{
		return col;
	}	
	else return (col=1);
}
int collision_arrow(Personne p,boss alien)
{
	int col=0;
	if( ((p.pos.pos_Perso.x+p.pos.pos_Perso.w)<=alien.pos_arrow.x) || (p.pos.pos_Perso.x>=(alien.pos_arrow.x+alien.pos_arrow.w)) ||(p.pos.pos_Perso.y>=(alien.pos_arrow.y+alien.pos_arrow.h))||((p.pos.pos_Perso.y+p.pos.pos_Perso.h)<=alien.pos_arrow.y))
	{
		return col;
	}	
	else return (col=1);
}
void deplacerIA(boss *alien,Personne p)
{
	if(alien->nb_hit<21)
	{
	if((p.pos.pos_Perso.x+p.pos.pos_Perso.w)>alien->pos_boss.x-300 && p.pos.pos_Perso.x+170<alien->pos_boss.x+alien->pos_boss.w) 
	{
		alien->direction_boss=0;
		alien->state=FOLLOWING;
	}
	else if(p.pos.pos_Perso.x<(alien->pos_boss.x+alien->pos_boss.w+300) && p.pos.pos_Perso.x>alien->pos_boss.x+alien->pos_boss.w+170)
	{
		alien->direction_boss=1;
		alien->state=FOLLOWING;
	}
	else if(p.pos.pos_Perso.x+120<alien->pos_boss.x+alien->pos_boss.w && (p.pos.pos_Perso.x+p.pos.pos_Perso.w)>alien->pos_boss.x-400)
	{
		alien->direction_boss=0;
		alien->state=ATTACKING;
	}
	else if(p.pos.pos_Perso.x>alien->pos_boss.x+alien->pos_boss.w+120 && p.pos.pos_Perso.x<(alien->pos_boss.x+alien->pos_boss.w+400))
	{
		alien->direction_boss=1;
		alien->state=ATTACKING;	
	}
	else 
	{
		alien->state=WAITING;
		if(p.pos.pos_Perso.x+p.pos.pos_Perso.w-5<alien->pos_boss.x+alien->pos_boss.w) alien->direction_boss=0;
		else if(p.pos.pos_Perso.x+p.pos.pos_Perso.w>alien->pos_boss.x+alien->pos_boss.w+20) alien->direction_boss=1;
	}
	if(alien->state==FOLLOWING && alien->direction_boss==0) alien->pos_boss.x-=alien->pas_d;
	else if(alien->state==FOLLOWING && alien->direction_boss==1) alien->pos_boss.x+=alien->pas_d;
	}
}







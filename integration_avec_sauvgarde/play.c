#include "play.h"
#include "sauvgarde.h"
#include <SDL/SDL_ttf.h>
int game_win(SDL_Surface *screen_s,int *v,int score,temps t)
{
	SDL_Surface *back_g =NULL,*next=NULL,*restart=NULL,*exit_game,*flip=NULL,*sco=NULL,*txt=NULL,*tmp=NULL;
	SDL_Event event;
	TTF_Init();
	TTF_Font *police1;
	Mix_Chunk *son;
	SDL_Rect pos_bg,pos_co,pos_a,pos_flip,pos_q,pos_score,pos_txt,pos_tmp;
	int c=1,d,pos_b=-1,quit=-1;
	char tab[40];
	SDL_Color yellow ={255,191,0};
	SDL_Init(SDL_INIT_VIDEO);
	if(screen_s==NULL)
	{
	  printf("Unable to Set video mode :%s \n",SDL_GetError());
	  return 1;
	}
	police1= TTF_OpenFont("text/spacerangeracad.ttf",100);
	txt=TTF_RenderText_Blended(police1,"YOU-WIN",yellow);
	sprintf(t.entree,"-Time : %02d:%02d",t.min,t.sec);
	t.texte = TTF_RenderText_Blended(t.police,t.entree,yellow);
	
	sprintf(tab,"-Score: %d",score);
	son =Mix_LoadWAV("son/swipe.wav");
	back_g=IMG_Load("pic/win.png");
	next =IMG_Load("pic/next_level.png");
	restart=IMG_Load("pic/restart.png");
	exit_game=IMG_Load("pic/exit_menu.png");
	flip =IMG_Load("pic/flip.png");
	tmp=IMG_Load("enigme_pic/tmp.png");
	sco=TTF_RenderText_Blended(t.police,tab,yellow);
	pos_score.x=910;
	pos_score.y=570;
	pos_tmp.x=860;
	pos_tmp.y=550;
	pos_txt.x=450;
	pos_txt.y=35;
	t.position.x=910;
	t.position.y=620;
	while(c)
	{
	SDL_WM_SetCaption("WIN",NULL);
	SDL_EnableKeyRepeat(0,10);
	if(d && pos_b!=-1) pos_b=-1;
	d=0;
			pos_bg.x=0;
			pos_bg.y=0;
			SDL_BlitSurface(back_g,NULL,screen_s,&pos_bg);
			pos_co.x=428.5;
			pos_co.y=150;
			SDL_BlitSurface(next,NULL,screen_s,&pos_co);
			pos_a.x=428.5;
			pos_a.y=300;
			SDL_BlitSurface(restart,NULL,screen_s,&pos_a);
			pos_q.x=428.5;
		        pos_q.y=450;
	 	        SDL_BlitSurface(exit_game,NULL,screen_s,&pos_q);
			SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
			SDL_BlitSurface(tmp,NULL,screen_s,&pos_tmp);	
			SDL_BlitSurface(t.texte, NULL,screen_s,&t.position);
			SDL_BlitSurface(sco, NULL,screen_s,&pos_score);
				SDL_WaitEvent(&event);
				switch(event.type)
				{
					case SDL_QUIT:
					c=0;
					break;
					case SDL_MOUSEBUTTONUP :
					if(event.button.button == SDL_BUTTON_LEFT )
					{
					if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=150 && event.button.y<=250) //next_level
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=150;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;
							quit=1;
							
						}
					else if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=300 && event.button.y<=400) //restart
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=300;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;
							quit=2;
						}
					else if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=450 && event.button.y<=550) //exit
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=450;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							quit=0;
							c=0;
							
						}
					}
					break;
					case SDL_MOUSEMOTION :
					if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=150 && event.motion.y<=250) //next_level
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=150;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=300 && event.motion.y<=400) //restart
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=300;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=450 && event.motion.y<=550) //exit
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=450;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					break;	
					case SDL_KEYDOWN:
					 {
                				switch (event.key.keysym.sym)
             					   {
             						   
							   case SDLK_DOWN:
								if(d==0)
								{
									if(pos_b==2)
									{
									pos_b=-1;
									}
									pos_b++;
								}
								Mix_PlayChannel(-1,son,0);
								break;
						       	    case SDLK_UP:
								if(d==0)
								{
									if(pos_b==-1)
									  {
										pos_b=1;
									  }
									if(pos_b==0)
									  {
										pos_b=3;
									  }
									  pos_b--;
								}
								Mix_PlayChannel(-1,son,0);
								break;
								case SDLK_RETURN:
								if(pos_b==0)
								{
			  					pos_flip.x=428.5;
	  							pos_flip.y=150;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
              		           	  	        	Mix_PlayChannel(-1,son,0);
								quit=1;
								c=0;
								}
								if(pos_b==1)
								{
								pos_flip.x=428.5;
	  							pos_flip.y=300;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
			   					Mix_PlayChannel(-1,son,0);
								quit=2;
								c=0;
								}
								if(pos_b==2)
								{
								pos_flip.x=428.5;
	  							pos_flip.y=450;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
			   					Mix_PlayChannel(-1,son,0);
								c=0;
								quit=0;
								}		
             							break;
						    }
					  break;	
					 }	
				}//switch
		
		if(!d && pos_b==0)
   		{
		pos_flip.x=428.5;
	  	pos_flip.y=150;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		}
   		if(!d && pos_b==1)
   		{
		pos_flip.x=428.5;
	  	pos_flip.y=300;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		}
		if(!d && pos_b==2)
   		{
		pos_flip.x=428.5;
	  	pos_flip.y=450;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		}
  
	SDL_Flip(screen_s);
        Mix_VolumeMusic(0);
	Mix_VolumeChunk(son,(*v));
	}//while(c)
	Mix_FreeChunk(son);
 	SDL_FreeSurface(back_g); 
	SDL_FreeSurface(restart);
	SDL_FreeSurface(next);
	SDL_FreeSurface(exit_game);
	SDL_FreeSurface(txt);
	SDL_FreeSurface(tmp);
	SDL_FreeSurface(sco);
	SDL_FreeSurface(flip);
	return quit;
}
int game_over(SDL_Surface *screen_s,int *v)
{
	SDL_Surface *back_g =NULL,*continu=NULL,*exit_game,*flip=NULL;
	SDL_Event event;
	Mix_Chunk *son;
	SDL_Rect pos_bg,pos_co,pos_a,pos_flip,pos_q;
	int c=1,d,pos_b=-1,quit=1;
	SDL_Init(SDL_INIT_VIDEO);
	if(screen_s==NULL)
	{
	  printf("Unable to Set video mode :%s \n",SDL_GetError());
	  return 1;
	}
	son =Mix_LoadWAV("son/swipe.wav");
	back_g=IMG_Load("pic/game_over.png");
	continu =IMG_Load("pic/continue.png");
	exit_game=IMG_Load("pic/exit_menu.png");
	flip =IMG_Load("pic/flip.png");
	while(c)
	{
	SDL_WM_SetCaption("GAME-OVER",NULL);
	SDL_EnableKeyRepeat(0,10);
	if(d && pos_b!=-1) pos_b=-1;
	d=0;
			pos_bg.x=0;
			pos_bg.y=0;
			SDL_BlitSurface(back_g,NULL,screen_s,&pos_bg);
			pos_co.x=428.5;
			pos_co.y=450;
			SDL_BlitSurface(continu,NULL,screen_s,&pos_co);
			pos_q.x=428.5;
		        pos_q.y=600;
	 	        SDL_BlitSurface(exit_game,NULL,screen_s,&pos_q);	
			while(SDL_PollEvent(&event)){
				switch(event.type)
				{
					case SDL_QUIT:
					c=0;
					break;
					case SDL_MOUSEBUTTONUP :
					if(event.button.button == SDL_BUTTON_LEFT )
					{
					if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=450 && event.button.y<=550) //continue
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=450;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;
						}
					else if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=600 && event.button.y<=700) //exit
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=600;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;
							quit=0;
						}
					}
					break;
					case SDL_MOUSEMOTION :
					if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=450 && event.motion.y<=550) //continue
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=450;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=600 && event.motion.y<=700) //exit
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=600;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					break;	
					case SDL_KEYDOWN:
					 {
                				switch (event.key.keysym.sym)
             					   {
             						   case SDLK_ESCAPE:
               						       c=0;
             						       break;
							   case SDLK_DOWN:
								if(d==0)
								{
									if(pos_b==1)
									{
									pos_b=-1;
									}
									pos_b++;
								}
								Mix_PlayChannel(-1,son,0);
								break;
						       	    case SDLK_UP:
								if(d==0)
								{
									if(pos_b==-1)
									  {
										pos_b=1;
									  }
									if(pos_b==0)
									  {
										pos_b=2;
									  }
									  pos_b--;
								}
								Mix_PlayChannel(-1,son,0);
								break;
								case SDLK_RETURN:
								if(pos_b==0)
								{
			  					pos_flip.x=428.5;
	  							pos_flip.y=450;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
              		           	  	        	Mix_PlayChannel(-1,son,0);
								c=0;
								}
								if(pos_b==1)
								{
								pos_flip.x=428.5;
	  							pos_flip.y=600;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
			   					Mix_PlayChannel(-1,son,0);
								c=0;
								quit=0;
								}		
             							break;
						    }
					  break;	
					 }	
				}//switch
		}
		if(!d && pos_b==0)
   		{
		pos_flip.x=428.5;
	  	pos_flip.y=450;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		}
   		if(!d && pos_b==1)
   		{
		pos_flip.x=428.5;
	  	pos_flip.y=600;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		}
		
  
	SDL_Flip(screen_s);
        Mix_VolumeMusic(0);
	Mix_VolumeChunk(son,(*v));
	}//while(c)
	Mix_FreeChunk(son);
 	SDL_FreeSurface(back_g); 
	SDL_FreeSurface(continu);
	SDL_FreeSurface(exit_game);
	SDL_FreeSurface(flip);
	return quit;
}
int pause_game(SDL_Surface *screen_s,Personne p,ennemi e[],ennemi e2[],boss bo,int *v)
{
	SDL_Surface *back_g =NULL,*resume =NULL,*save_game=NULL,*exit_game,*flip=NULL;
	SDL_Event event;
	Mix_Chunk *son;
	SDL_Rect pos_bg,pos_co,pos_a,pos_flip,pos_q;
	int c=1,d,pos_b=-1,quit=1;
	SDL_Init(SDL_INIT_VIDEO);
	if(screen_s==NULL)
	{
	  printf("Unable to Set video mode :%s \n",SDL_GetError());
	  return 1;
	}
	
	
	son =Mix_LoadWAV("son/swipe.wav");
	back_g=IMG_Load("pic/pause.png");
	resume =IMG_Load("pic/resume.png");
	save_game=IMG_Load("pic/save-game.png");
	exit_game=IMG_Load("pic/exit_menu.png");
	flip =IMG_Load("pic/flip.png");
	
	while(c)
	{
	SDL_WM_SetCaption("PAUSE",NULL);
	SDL_EnableKeyRepeat(0,10);
	if(d && pos_b!=-1) pos_b=-1;
	d=0;
			pos_bg.x=0;
			pos_bg.y=0;
			SDL_BlitSurface(back_g,NULL,screen_s,&pos_bg);
			pos_co.x=428.5;
			pos_co.y=150;
			SDL_BlitSurface(resume,NULL,screen_s,&pos_co);
			pos_a.x=428.5;
			pos_a.y=300;
			SDL_BlitSurface(save_game,NULL,screen_s,&pos_a);
			pos_q.x=428.5;
		        pos_q.y=450;
	 	        SDL_BlitSurface(exit_game,NULL,screen_s,&pos_q);	
		
				SDL_WaitEvent(&event);
				switch(event.type)
				{
					case SDL_QUIT:
					c=0;
					break;
					case SDL_MOUSEBUTTONUP :
					if(event.button.button == SDL_BUTTON_LEFT )
					{
					if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=150 && event.button.y<=250) //resume
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=150;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;
						}
					else if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=300 && event.button.y<=400) //save_game
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=300;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;
							quit=2;
						}
					else if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=450 && event.button.y<=550) //exit
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=450;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;
							quit=0;
						}
					}
					break;
					case SDL_MOUSEMOTION :
					if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=150 && event.motion.y<=250) //resume
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=150;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=300 && event.motion.y<=400) //save_game
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=300;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=450 && event.motion.y<=550) //exit
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=450;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					break;	
					case SDL_KEYDOWN:
					 {
                				switch (event.key.keysym.sym)
             					   {
             						   case SDLK_ESCAPE:
               						       c=0;
             						       break;
							   case SDLK_DOWN:
								if(d==0)
								{
									if(pos_b==2)
									{
									pos_b=-1;
									}
									pos_b++;
								}
								Mix_PlayChannel(-1,son,0);
								break;
						       	    case SDLK_UP:
								if(d==0)
								{
									if(pos_b==-1)
									  {
										pos_b=1;
									  }
									if(pos_b==0)
									  {
										pos_b=3;
									  }
									  pos_b--;
								}
								Mix_PlayChannel(-1,son,0);
								break;
								case SDLK_RETURN:
								if(pos_b==0)
								{
			  					pos_flip.x=428.5;
	  							pos_flip.y=150;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
              		           	  	        	Mix_PlayChannel(-1,son,0);
								c=0;
								}
								if(pos_b==1)
								{
								pos_flip.x=428.5;
	  							pos_flip.y=300;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
			   					Mix_PlayChannel(-1,son,0);
								c=0;
								quit=2;
								}
								if(pos_b==2)
								{
								pos_flip.x=428.5;
	  							pos_flip.y=450;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
			   					 Mix_PlayChannel(-1,son,0);
								c=0;
								quit=0;
								}		
             							break;
						    }
					  break;	
					 }	
				}//switch
		
		if(!d && pos_b==0)
   		{
		pos_flip.x=428.5;
	  	pos_flip.y=150;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		}
   		if(!d && pos_b==1)
   		{
		pos_flip.x=428.5;
	  	pos_flip.y=300;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		}
		if(!d && pos_b==2)
   		{
		pos_flip.x=428.5;
	  	pos_flip.y=450;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		}
  
	SDL_Flip(screen_s);
        Mix_VolumeMusic(0);
	Mix_VolumeChunk(son,(*v));
	}//while(c)
	Mix_FreeChunk(son);
 	SDL_FreeSurface(back_g); 
	SDL_FreeSurface(resume);
	SDL_FreeSurface(save_game);
	SDL_FreeSurface(exit_game);
	SDL_FreeSurface(flip);
	return quit;
}
int play_game(SDL_Surface *screen,int *v,int touche_state,int load_n)
{
   SDL_Surface *map,*d_rocket=NULL,*rocket_fin=NULL,*barre_score=NULL,*flag=NULL,*vie[5];
   SDL_Rect pos_r,pos_r1,pos_score,pos_flag,pos_flag2,pos_vie,pos_map;
   SDL_Event event;
   effect son;
   int c=1,collision,collision2,col_boss,col_arrow,score=0,nb_hit_p=0,frame_vie=0,col_up,col_down,col_right,col_left,sec_jump,verif=-1,next=0,pause_return=-1;
   Uint32 start;
	TTF_Font *police=NULL;
	TTF_Init();
	SDL_Color yellow ={255,191,0};
   char tab[40];
   pos poss[8];
//***
   int posinit,enigme_1=-1,open=0,fin=0,enigme_2=-1,open1=0;
   Uint32 dt,t_prev;
   Personne p;
  const int FPS=15;
  background backg;
   SDL_Init(SDL_INIT_VIDEO);	
   ennemi e[5],e2[5];
   boss alien;
   temps t;
   minimap mini_map;
	save s;
  SDL_WM_SetCaption("PLAY",NULL);
police= TTF_OpenFont("text/spacerangeracad.ttf",45);
   if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
	  printf("Unable to initialize SDL :%s \n",SDL_GetError());
	  return 1;
	}
	screen =SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	if(screen==NULL)
	{
	  printf("Unable to Set video mode :%s \n",SDL_GetError());
	  return 1;
	}
	init_save(&s);
	init_sound(&son);
	initPerso(&p);
	initboss(&alien);
	initialiser_background(&backg);
	initialiser_temps(&t);
   	initialiser_minimap(&mini_map,p.pos.pos_Perso);
	update_collision(poss,p.pos.pos_Perso);
	map=IMG_Load("Map/map.png");
	d_rocket=IMG_Load("Map/d_rocket.png");
	rocket_fin=IMG_Load("Map/rocket.png");
	flag=IMG_Load("pic/flag.png");
	
	vie[0]=IMG_Load("pic/health/vie3.png");
	vie[1]=IMG_Load("pic/health/vie2.png");
	vie[2]=IMG_Load("pic/health/vie1.png");
	vie[3]=IMG_Load("pic/health/vie0.png");
	vie[4]=IMG_Load("pic/health/vie0.png");
	pos_vie.x=10;
	pos_vie.y=100;

	posinit=p.pos.pos_Perso.y;	
	
	for(int j=0;j<5;j++)
	{
	initEnnemi(&e[j],&e2[j]);
	}
	e[0].pos_eni.x=1680;
	e[1].pos_eni.x=1880;
	e[2].pos_eni.x=2680;
	e[3].pos_eni.x=2880;
	e[4].pos_eni.x=4010;

	e2[0].pos_eni2.x=980;
	e2[1].pos_eni2.x=1445;
	e2[2].pos_eni2.x=2005;
	e2[3].pos_eni2.x=2250;
	e2[4].pos_eni2.x=4225;
	
	e2[3].posymin2=375;
	e2[3].posymax2=225;
	//***********************************************
	if(load_n==2)
	{
		s=recuperer(s);
		p.pos.pos_Perso=s.pos_perso;
		for(int i=0;i<5;i++)
		{
			e[i].pos_eni=s.posennemi1[i];
			e2[i].pos_eni=s.posennemi1[i];
		}
		alien.state=s.alien_state;
		backg.camera=s.pos_cam;
		open=s.open_enigme1;
		open1=s.open_enigme2;
		
		nb_hit_p=s.p_nb_hit;
		score=s.score_p;
	}
	
	
	
	//***********************************************//
	pos_r.x=0;
	pos_r.y=245;
	pos_r1.x=4800;
	pos_r1.y=175;
	
	/*pos_score.x=10;
	pos_score.y=10;*/
	pos_flag.x=1230;
	pos_flag.y=450;
	pos_flag2.x=2350;
	pos_flag2.y=450;
	SDL_EnableKeyRepeat(10,10);
	play_son(0,son);
	pos_map.x=0;
	pos_map.y=0;
	while(c)
	{
	if(p.pos.pos_Perso.x>=1240 && p.pos.pos_Perso.x<=1260 && !open)
	{
		enigme_1=enigme_sf(v,screen);
		open=1;
		
		if(enigme_1==1) 
		{
		score+=450;
		enigme_1=-1;	
		p.pos.pos_Perso.x=1245;
		SDL_EnableKeyRepeat(10,10);
		play_son(3,son);
		}
	else if(enigme_1==0) 
		{
		score-=50;
		enigme_1=-1;
		p.pos.pos_Perso.x=1245;
		SDL_EnableKeyRepeat(10,10);
		play_son(4,son);
		}
	   play_son(0,son);	
	}
	if(p.pos.pos_Perso.x>=2345 && p.pos.pos_Perso.x<=2425 && !open1 && (p.pos.pos_Perso.y>449))
	{
		enigme_2=enigme_avec_f(v,screen);
		open1=1;
		
		if(enigme_2==1) 
		{
		score+=500;
		enigme_2=-1;	
		p.pos.pos_Perso.x=2375;
		SDL_EnableKeyRepeat(10,10);
		play_son(3,son);
		}
	else if(enigme_2==0) 
		{
		score-=100;
		enigme_2=-1;
		p.pos.pos_Perso.x=2375;
		SDL_EnableKeyRepeat(10,10);
		play_son(4,son);
		}
	   play_son(0,son);	
	}
	if(p.pos.pos_Perso.x>=4860 && p.pos.pos_Perso.x<=4900 && alien.state==DIE && open && open1)
	{
		p.pos.pos_Perso.x=4915;
		fin=1;
		play_son(8,son);
		verif=game_win(screen,v,score,t);
		
		if(verif==1) //next_level
		{
			c=0;
			next=1;
		}
		if(verif==0) c=0;
		if(verif==2) 
		{
		SDL_EnableKeyRepeat(10,10);
		Mix_VolumeMusic((*v));
		play_son(0,son);
		initPerso(&p);
		initboss(&alien);
		initialiser_temps(&t);	
		initialiser_background(&backg);
		for(int j=0;j<5;j++)
		{
			initEnnemi(&e[j],&e2[j]);
		}
		e[0].pos_eni.x=1680;
		e[1].pos_eni.x=1880;
		e[2].pos_eni.x=2680;
		e[3].pos_eni.x=2880;
		e[4].pos_eni.x=4010;

		e2[0].pos_eni2.x=980;
		e2[1].pos_eni2.x=1445;
		e2[2].pos_eni2.x=2005;
		e2[3].pos_eni2.x=2250;
		e2[4].pos_eni2.x=4225;
		e2[3].posymin2=375;
		e2[3].posymax2=225;
		score=0;
		frame_vie=0;
		nb_hit_p=0;
		open=0;
		open1=0;
		fin=0;
		update_collision(poss,p.pos.pos_Perso);
		}
	}
	if(nb_hit_p>=20)
	{
		
		play_son(9,son);
		c=game_over(screen,v);
		if(c==1)
		{
		SDL_EnableKeyRepeat(10,10);
		play_son(0,son);
		initPerso(&p);
		initboss(&alien);
		initialiser_temps(&t);	
		initialiser_background(&backg);
		for(int j=0;j<5;j++)
		{
			initEnnemi(&e[j],&e2[j]);
		}
		e[0].pos_eni.x=1680;
		e[1].pos_eni.x=1880;
		e[2].pos_eni.x=2680;
		e[3].pos_eni.x=2880;
		e[4].pos_eni.x=4010;

		e2[0].pos_eni2.x=980;
		e2[1].pos_eni2.x=1445;
		e2[2].pos_eni2.x=2005;
		e2[3].pos_eni2.x=2250;
		e2[4].pos_eni2.x=4225;
		e2[3].posymin2=375;
		e2[3].posymax2=225;
		score=0;
		frame_vie=0;
		nb_hit_p=0;
		open=0;
		open1=0;
		update_collision(poss,p.pos.pos_Perso);
		}
	}
	if(collisionParfaite_down(backg.mask,poss)==2)
	{
		nb_hit_p=40;
	}
	
	//********************************************
	srand(time(NULL));
	e[0].posxmin=(rand()%(1600-1550+1))+1500;
	e[0].posxmax=(rand()%(1800-1750+1))+1750;

	e[1].posxmin=(rand()%(1830-1810+1))+1810;
	e[1].posxmax=(rand()%(2080-2050+1))+2050;
	
	e[2].posxmin=(rand()%(2450-2430+1))+2430;
	e[2].posxmax=(rand()%(2700-2690+1))+2690;
	
	e[3].posxmin=(rand()%(2780-2750+1))+2750;
	e[3].posxmax=(rand()%(2900-2890+1))+2890;
	
	e[4].posxmin=(rand()%(3890-3880+1))+3880;
	e[4].posxmax=(rand()%(4120-4100+1))+4100;
	
	//********************************************
	start= SDL_GetTicks();
	t_prev=SDL_GetTicks();
	 
	 while(SDL_PollEvent(&event)){
		switch(event.type)
	   {
		case SDL_QUIT:
		c=0;
		break;
	//****
		case SDL_KEYDOWN:
			{
				if(event.key.keysym.sym==SDLK_ESCAPE)
					{
						pause_return=pause_game(screen,p,e,e2,alien,v);
						if(pause_return==0) c=0;
						else if(pause_return==1) c=1;
						else if (pause_return==2)
						{
							enregistrer(s);
						}
						
					}
				//if(!touche_state)
			    // {
				 if(event.key.keysym.sym==SDLK_RIGHT && p.up!=2 && p.up!=3)
				{
					p.img.direction=0;
					backg.direction=1;
					scrolling(&backg,p,collision,collision2,col_boss,col_arrow);
					score++;
				}
				 if(event.key.keysym.sym==SDLK_RIGHT && (p.up==2 || p.up==3))
				{
					p.img.direction=0;
					score++;
				}
				else if(event.key.keysym.sym==SDLK_LEFT  && p.up!=2 && p.up!=3)
				{
					p.img.direction=1;
					backg.direction=2;
					scrolling(&backg,p,collision,collision2,col_boss,col_arrow);
				}
				else if(event.key.keysym.sym==SDLK_LEFT  && (p.up==2 || p.up==3))
				{
					p.img.direction=1;
				}
				else if(event.key.keysym.sym==SDLK_UP  )
				{
					p.img.direction=2;
					p.up=1;
					sec_jump=1;
					saut(&p,dt,posinit,sec_jump,col_down);
					play_son(1,son);
					
				}
				else if(event.key.keysym.sym==SDLK_DOWN)
				{
					p.img.direction=3;
				}
			//}
				else
				{
					 if(event.key.keysym.sym==SDLK_d && p.up!=2 && p.up!=3)
				{
					p.img.direction=0;
					backg.direction=1;
					scrolling(&backg,p,collision,collision2,col_boss,col_arrow);
					score++;
				}
				 if(event.key.keysym.sym==SDLK_d && (p.up==2 || p.up==3))
				{
					p.img.direction=0;
					score++;
				}
				else if(event.key.keysym.sym==SDLK_q  && p.up!=2 && p.up!=3)
				{
					p.img.direction=1;
					backg.direction=2;
					scrolling(&backg,p,collision,collision2,col_boss,col_arrow);
				}
				else if(event.key.keysym.sym==SDLK_q && (p.up==2 || p.up==3))
				{
					p.img.direction=1;
				}
				else if(event.key.keysym.sym==SDLK_z  )
				{
					p.img.direction=2;
					p.up=1;
					sec_jump=1;
					saut(&p,dt,posinit,sec_jump,col_down);
					play_son(1,son);
					
				}
				else if(event.key.keysym.sym==SDLK_s)
				{
					p.img.direction=3;
				}
				}
				if(event.key.keysym.sym==SDLK_SPACE)
				{
					p.up=2;
					sec_jump=1;
					saut(&p,dt,posinit,sec_jump,col_down);
					backg.direction=1;
					scrolling(&backg,p,collision,collision2,col_boss,col_arrow);
					score+=5;
					play_son(2,son);
					
				}
				else if(event.key.keysym.sym==SDLK_LCTRL)
				{
					p.up=3;
					sec_jump=1;
					saut(&p,dt,posinit,sec_jump,col_down);
					backg.direction=2;
					scrolling(&backg,p,collision,collision2,col_boss,col_arrow);
					play_son(2,son);	
				}
				else if(event.key.keysym.sym==SDLK_a)
				{
					p.acceleration+=0.005;
				}
				else if(event.key.keysym.sym==SDLK_e)
				{
					p.acceleration-=0.01;
				}
				
			}
			break;
			
			default:
			{
				p.img.direction=4;
									
			}
			break;
	   }
	}
	
	  sprintf(tab,"-Score: %d",score);
	barre_score=TTF_RenderText_Blended(police,tab,yellow);
	  sec_jump=0;
//*****
		update_collision(poss,p.pos.pos_Perso);
	   dt=SDL_GetTicks()-t_prev;
	   p.acceleration-=0.001;
	   deplacerPerso (&p,dt,posinit);		
	   animerPerso (&p);
//****
	backg.bg=IMG_Load("Map/map.png");
	SDL_BlitSurface(map,NULL,backg.bg,&pos_map);
	animerboss(&alien);
	afficherboss(alien,backg.bg);
	deplacerIA(&alien,p);
	
	for(int j=0;j<5;j++)
	{
	animerEnnemi(&e[j],&e2[j]);
	  deplacer(&e[j],&e2[j]);	
	afficherEnnemi(e[j],e2[j],backg.bg);
	}	
		SDL_BlitSurface(d_rocket,NULL,backg.bg,&pos_r);
	SDL_BlitSurface(rocket_fin,NULL,backg.bg,&pos_r1);
	 
	SDL_BlitSurface(flag,NULL,backg.bg,&pos_flag);
	SDL_BlitSurface(flag,NULL,backg.bg,&pos_flag2);
	
	//afficherPerso(&p,backg.bg);	
	 afficher_background(backg,screen);
	SDL_BlitSurface(vie[frame_vie],NULL,screen,&pos_vie);
	  afficher_minimap(mini_map,p.pos.pos_Perso,screen);
          afficher_temps(&t,screen);
	SDL_BlitSurface(barre_score,NULL,screen,&pos_score);
	  SDL_Flip(screen);//////////*****************************************
	if(!fin) Mix_VolumeMusic((*v));
	else Mix_VolumeMusic(0);
	Mix_VolumeChunk(son.lvl_up,(*v));
	Mix_VolumeChunk(son.lvl_down,(*v));
	Mix_VolumeChunk(son.jump,(*v));
	Mix_VolumeChunk(son.long_jump,(*v));
	Mix_VolumeChunk(son.health_down,(*v));
	Mix_VolumeChunk(son.ennemi_hit,(*v));
	Mix_VolumeChunk(son.perso_hit,(*v));
	Mix_VolumeChunk(son.finish,(*v));
	Mix_VolumeChunk(son.game_over,(*v));
	Mix_VolumeChunk(son.boss_death,(*v));
col_down=0;
saut(&p,dt,posinit,sec_jump,col_down);
col_arrow=collision_arrow(p,alien);
if(col_arrow==1) 
	{
	if(alien.state!=WAITING && alien.state!=HIT && alien.state!=DIE)
	{
	p.pos.pos_Perso.y-=85;
	if(alien.direction_boss==0)
	p.pos.pos_Perso.x-=19;
	else p.pos.pos_Perso.x+=19;
	play_son(7,son);
	nb_hit_p++;
	if(!(nb_hit_p%5))
		{
		frame_vie++;
		if(frame_vie>3) frame_vie=4;
		}
	}
	}
  for(int j=0;j<5;j++) 
{
collision=collisionBB(p,e[j]);
	if(collision==1)
	{
		if(p.pos.pos_Perso.y!=posinit && (p.pos.pos_Perso.y+p.pos.pos_Perso.h)<=e[j].pos_eni.y+10 ) 
		{
			play_son(6,son);
			e[j].die=1;
			score+=50;
		}
		 if(((p.pos.pos_Perso.y==e[j].pos_eni.y+10) && (p.pos.pos_Perso.y==posinit) ) && (e[j].die==0) && ((p.pos.pos_Perso.x+p.pos.pos_Perso.w)>e[j].pos_eni.x) && (e[j].direction==1)) 
	{
	p.pos.pos_Perso.x-=55;
	play_son(7,son);
	nb_hit_p++;
	if(!(nb_hit_p%5))
	{
		play_son(5,son);
		frame_vie++;
		if(frame_vie>3) frame_vie=4;
	}
	}

		else if(((p.pos.pos_Perso.y==e[j].pos_eni.y+10) || (p.pos.pos_Perso.y==posinit) ) &&(e[j].die==0) && (p.pos.pos_Perso.x<(e[j].pos_eni.x+e[j].pos_eni.w)) && (e[j].direction==0 )) 
		{
		p.pos.pos_Perso.x+=55;
		play_son(7,son);
		nb_hit_p++;
		if(!(nb_hit_p%5))
		{
		play_son(5,son);
		frame_vie++;
		if(frame_vie>3) frame_vie=4;
		}
		}
	}
  }
for(int j=0;j<5;j++)
{
collision2=collisionBB2(p,e2[j]);
	if(collision2==1)
	{
		if(p.pos.pos_Perso.y!=posinit && (p.pos.pos_Perso.y+p.pos.pos_Perso.h)<e2[j].pos_eni2.y+10 && ((p.pos.pos_Perso.y)!=(e2[j].pos_eni2.y+e2[j].pos_eni2.h)) ) 
		{
			e2[j].die=1;
			play_son(6,son);
			score+=20;
		}
		 if((e2[j].die==0) &&(e2[j].direction==1)) 
		{
			p.pos.pos_Perso.x-=60;
			play_son(7,son);
			nb_hit_p++;
			if(!(nb_hit_p%5))
			{
				play_son(5,son);
				frame_vie++;
				if(frame_vie>3) frame_vie=4;
			}
		}
		else if((e2[j].die==0) && (e2[j].direction==0 ))
		{
			 p.pos.pos_Perso.x+=60;
			play_son(7,son);
			nb_hit_p++;
			if(!(nb_hit_p%5))
			{
				play_son(5,son);
				frame_vie++;
				if(frame_vie>3) frame_vie=4;
			}
		}
	}
}
col_boss=collisionboss(p,alien);
if(col_boss==1)	
{
	if(alien.state!=DIE)
	{
		if(p.pos.pos_Perso.y!=posinit && (p.pos.pos_Perso.y+p.pos.pos_Perso.h)>=alien.pos_boss.y+21) 
		{
			alien.state=HIT;
			p.pos.pos_Perso.y-=40;
			play_son(6,son);
			alien.nb_hit++;
			if(!(alien.nb_hit%3))
			{
				if(alien.direction_boss==0)
				 p.pos.pos_Perso.x-=75;
				else if(alien.direction_boss==1) p.pos.pos_Perso.x+=75;
				play_son(7,son);
			}
			if(alien.nb_hit>=21)
			{
				alien.state=DIE;
				play_son(10,son);
				score+=1000;
			}
		}
		else
			{
				if(alien.direction_boss==0)
				 {
					p.pos.pos_Perso.x-=55;
					play_son(7,son);
					nb_hit_p++;
					if(!(nb_hit_p%5))
					{
					play_son(5,son);
					frame_vie++;
					if(frame_vie>3) frame_vie=4;
					}
				 }
				else if (alien.direction_boss==1)
				{
				 p.pos.pos_Perso.x+=55;
				play_son(7,son);
				nb_hit_p++;
				if(!(nb_hit_p%5))
				{	
				play_son(5,son);
				frame_vie++;
				if(frame_vie>3) frame_vie=4;
				}
				}
			}
	}
}
if(collisionParfaite_down(backg.mask,poss)==1 && p.up!=0 && p.up!=1 && p.up!=2 && p.up!=3) 
	{
		p.pos.pos_Perso.y+=(p.vitesse/20);
		
	}
else 
{
	if(collisionParfaite_down(backg.mask,poss)==1 && p.up!=0) 
	{
		p.pos.pos_Perso.y-=5;
		col_down=1;
	}
}
if(collisionParfaite_left(backg.mask,poss)) p.pos.pos_Perso.x+=20;
else p.pos.pos_Perso.x-=1;
if(collisionParfaite_right(backg.mask,poss)) p.pos.pos_Perso.x-=20;
else p.pos.pos_Perso.x+=1;
update_save (&s,p.pos.pos_Perso,e,e2,alien.state,backg.camera,nb_hit_p,t,score,open,open1,touche_state);

	if(1000/FPS > SDL_GetTicks()-start) 
	{
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
	}
 free_temps(&t,screen);
return next;
}

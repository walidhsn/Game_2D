#include "menu.h"
#include "play.h"
void credit_menu(SDL_Surface *screen_c,int etat)
{
	SDL_Surface *back_g=NULL,*name=NULL,*name2=NULL,*name3=NULL,*name4=NULL,*name5=NULL,*name6=NULL,*quit=NULL,*quitf=NULL,*back_g2=NULL;
	SDL_Event event;
	Mix_Chunk *son;
	int i=1;
	TTF_Font *police=NULL;
	TTF_Init();
	SDL_Color yellow ={255,191,0};
	SDL_Rect pos_name,pos_bg,pos_ex,pos_q,pos_clic,pos_flip,pos_name2,pos_name3,pos_name4,pos_name5,pos_name6;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("Credits",NULL);
	police= TTF_OpenFont("text/spacerangeracad.ttf",45);

	if(screen_c==NULL)
	{
	  printf("Unable to Set video mode :%s \n",SDL_GetError());
	  return 1;
	}
//***********************************************************
	back_g=IMG_Load("pic/creditmenu.png");
	back_g2=IMG_Load("pic/creditmenu_resize.png");
	son =Mix_LoadWAV("son/button-3.wav");
	name=TTF_RenderText_Blended(police,"-Fadi Kharroubi",yellow);
	name2=TTF_RenderText_Blended(police,"-Med Amin Lamloum",yellow);
	name3=TTF_RenderText_Blended(police,"-Med Aziz Houas",yellow);
	name4=TTF_RenderText_Blended(police,"-Med Khalil Mzali",yellow);
	name5=TTF_RenderText_Blended(police,"-Syrine Azzouz",yellow);
	name6=TTF_RenderText_Blended(police,"-Walid Ben Hassouna",yellow);
	quit =	IMG_Load("pic/exit.png");
	quitf = IMG_Load("pic/flipq.png");
	while(i)
	{
		if(!etat){
		pos_bg.x=0;
		pos_bg.y=0;
		SDL_BlitSurface(back_g,NULL,screen_c,&pos_bg);
		pos_name.x=60;
		pos_name.y=120;
		SDL_BlitSurface(name,NULL,screen_c,&pos_name);
		pos_name2.x=60;
		pos_name2.y=170;
		SDL_BlitSurface(name2,NULL,screen_c,&pos_name2);
		pos_name3.x=60;
		pos_name3.y=220;
		SDL_BlitSurface(name3,NULL,screen_c,&pos_name3);
		pos_name4.x=60;
		pos_name4.y=270;
		SDL_BlitSurface(name4,NULL,screen_c,&pos_name4);
		pos_name5.x=60;
		pos_name5.y=320;
		SDL_BlitSurface(name5,NULL,screen_c,&pos_name5);
		pos_name6.x=60;
		pos_name6.y=370;
		SDL_BlitSurface(name6,NULL,screen_c,&pos_name6);
		pos_q.x=1150;
	  	pos_q.y=10;
	  	SDL_BlitSurface(quit,NULL,screen_c,&pos_q);
		SDL_WaitEvent(&event);
		switch(event.type)
	   {
		case SDL_QUIT:
		i=0;
		break;
		case SDL_MOUSEBUTTONUP :
		if(event.button.button == SDL_BUTTON_LEFT )
		{
			pos_clic.x=event.button.x;
			pos_clic.y=event.button.y;
			 if(event.button.x>=1150 && event.button.x<=1268 && event.button.y>=10 && event.button.y<=125) //quit
			{
				
				pos_flip.x=1153;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_c,&pos_flip);
				SDL_Flip(screen_c);
				Mix_PlayChannel(-1,son,0);
				i=0;
			}								
		}
		break;
		case SDL_MOUSEMOTION :
		if(event.motion.x>=1150 && event.motion.x<=1268 && event.motion.y>=10 && event.motion.y<=125) //quit
			{
				
				pos_flip.x=1153;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_c,&pos_flip);
				SDL_Flip(screen_c);
				//Mix_PlayChannel(-1,son,0);

			}
		break;
	case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
				pos_flip.x=1153;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_c,&pos_flip);
				SDL_Flip(screen_c);
				Mix_PlayChannel(-1,son,0);
				i=0;
            }
	break;
	    }//switch
	}
	//********************************************************************************************Resize
	else if(etat){
		police= TTF_OpenFont("text/spacerangeracad.ttf",51);
		pos_bg.x=0;
		pos_bg.y=0;
		SDL_BlitSurface(back_g2,NULL,screen_c,&pos_bg);
		pos_name.x=90;
		pos_name.y=250;
		SDL_BlitSurface(name,NULL,screen_c,&pos_name);
		pos_name2.x=90;
		pos_name2.y=300;
		SDL_BlitSurface(name2,NULL,screen_c,&pos_name2);
		pos_name3.x=90;
		pos_name3.y=350;
		SDL_BlitSurface(name3,NULL,screen_c,&pos_name3);
		pos_name4.x=90;
		pos_name4.y=400;
		SDL_BlitSurface(name4,NULL,screen_c,&pos_name4);
		pos_name5.x=90;
		pos_name5.y=450;
		SDL_BlitSurface(name5,NULL,screen_c,&pos_name5);
		pos_name6.x=90;
		pos_name6.y=500;
		SDL_BlitSurface(name6,NULL,screen_c,&pos_name6);
		pos_q.x=1766;
	  	pos_q.y=10;
	  	SDL_BlitSurface(quit,NULL,screen_c,&pos_q);
		SDL_WaitEvent(&event);
		switch(event.type)
	   {
		case SDL_QUIT:
		i=0;
		break;
		case SDL_MOUSEBUTTONUP :
		if(event.button.button == SDL_BUTTON_LEFT )
		{
			pos_clic.x=event.button.x;
			pos_clic.y=event.button.y;
			 if(event.button.x>=1766 && event.button.x<=1884 && event.button.y>=10 && event.button.y<=125) //quit
			{
				
				pos_flip.x=1769;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_c,&pos_flip);
				SDL_Flip(screen_c);
				Mix_PlayChannel(-1,son,0);
				i=0;
			}								
		}
		break;
		case SDL_MOUSEMOTION :
		if(event.motion.x>=1766 && event.motion.x<=1884 && event.motion.y>=10 && event.motion.y<=125) //quit
			{
				
				pos_flip.x=1769;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_c,&pos_flip);
				SDL_Flip(screen_c);
				//Mix_PlayChannel(-1,son,0);

			}
		break;
	case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
				pos_flip.x=1769;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_c,&pos_flip);
				SDL_Flip(screen_c);
				Mix_PlayChannel(-1,son,0);
				i=0;
            }
	break;
	    }//switch
	}
	SDL_Flip(screen_c);
      }//whi
	Mix_FreeChunk(son);
 	SDL_FreeSurface(back_g); 
 	SDL_FreeSurface(back_g2);
	SDL_FreeSurface(name);
	SDL_FreeSurface(name2);
	SDL_FreeSurface(name3);
	SDL_FreeSurface(name4);
	SDL_FreeSurface(name5);
	SDL_FreeSurface(name6);
	SDL_FreeSurface(quit);
	SDL_FreeSurface(quitf);
	TTF_CloseFont(police);
	TTF_Quit();
 
}//func
	
void choix_jouer(SDL_Surface *screen_s,int *v,int *etat,int touche_state)
{
	SDL_Surface *back_g =NULL,*back_gfs=NULL,*single_player =NULL,*multi_player=NULL,*flip=NULL,*quit=NULL,*quitf=NULL;
	SDL_Event event;
	Mix_Chunk *son;
	Mix_Music *music;
	SDL_Rect pos_bg,pos_co,pos_a,pos_flip,pos_q;
	int c=1,d,pos_b=-1,next_level=-1;
	SDL_Init(SDL_INIT_VIDEO);
	if(screen_s==NULL)
	{
	  printf("Unable to Set video mode :%s \n",SDL_GetError());
	  return 1;
	}
	
	music = Mix_LoadMUS("son/song.mp3");
	son =Mix_LoadWAV("son/swipe.wav");
	back_g=IMG_Load("pic/menu_perso.png");
	back_gfs=IMG_Load("pic/menu_perso_fs.png");
	single_player =IMG_Load("pic/single_player.png");
	multi_player=IMG_Load("pic/multi_player.png");
	flip =IMG_Load("pic/flip.png");
	quit=IMG_Load("pic/exit.png");
	quitf=IMG_Load("pic/flipq.png");
	while(c)
	{
	SDL_WM_SetCaption("CHOOSE-PLAYER",NULL);
	SDL_EnableKeyRepeat(0,10);
	if(d && pos_b!=-1) pos_b=-1;
	d=0;
		if(!(*etat))
		{
			
			pos_bg.x=0;
			pos_bg.y=0;
			SDL_BlitSurface(back_g,NULL,screen_s,&pos_bg);
			pos_co.x=428.5;
			pos_co.y=350;
			SDL_BlitSurface(single_player,NULL,screen_s,&pos_co);
			pos_a.x=428.5;
			pos_a.y=500;
			SDL_BlitSurface(multi_player,NULL,screen_s,&pos_a);
			pos_q.x=1150;
		        pos_q.y=10;
	 	        SDL_BlitSurface(quit,NULL,screen_s,&pos_q);	
		
				SDL_WaitEvent(&event);
				switch(event.type)
				{
					case SDL_QUIT:
					c=0;
					break;
					case SDL_MOUSEBUTTONUP :
					if(event.button.button == SDL_BUTTON_LEFT )
					{
					if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=350 && event.button.y<=450) //CHOIX single
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=350;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							next_level=play_game(screen_s,v,touche_state,0);
							Mix_PlayMusic(music,-1);
						}
					else if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=500 && event.button.y<=600) //choix multi
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=500;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							next_level=multi_game(screen_s,v,touche_state);
							Mix_PlayMusic(music,-1);
						}
					else if(event.button.x>=1150 && event.button.x<=1268 && event.button.y>=10 && event.button.y<=125) //quit
						{
				
							pos_flip.x=1153;
	  						pos_flip.y=11;
	  						SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;
						}
					}
					break;
					case SDL_MOUSEMOTION :
					if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=350 && event.motion.y<=450) //CHOIX single
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=350;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=500 && event.motion.y<=600) //choix multi
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=500;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=1150 && event.motion.x<=1268 && event.motion.y>=10 && event.motion.y<=125) //quit
					{
						d=1;
						pos_flip.x=1153;
	  					pos_flip.y=11;
	  					SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					break;	
					case SDL_KEYDOWN:
					 {
                				switch (event.key.keysym.sym)
             					   {
             						   case SDLK_ESCAPE:
								pos_flip.x=1153;
	  							pos_flip.y=11;
	  							SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
								Mix_PlayChannel(-1,son,0);
               						       c=0;
             						       break;
							   case SDLK_UP:
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
						       	    case SDLK_DOWN:
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
	  							pos_flip.y=350;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
              		           	  	        	Mix_PlayChannel(-1,son,0);
								next_level=play_game(screen_s,v,touche_state,0);
								Mix_PlayMusic(music,-1);
								}
								if(pos_b==1)
								{
								pos_flip.x=428.5;
	  							pos_flip.y=500;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
			   					 Mix_PlayChannel(-1,son,0);
                           					next_level=multi_game(screen_s,v,touche_state);
								Mix_PlayMusic(music,-1);
								}		
             							break;
						    }
					  break;	
					 }	
				}//switch
		}//if(etat)
		else if((*etat)==1)
		{
			pos_bg.x=0;
			pos_bg.y=0;
			SDL_BlitSurface(back_gfs,NULL,screen_s,&pos_bg);
			pos_co.x=747;
			pos_co.y=350;
			SDL_BlitSurface(single_player,NULL,screen_s,&pos_co);
			pos_a.x=747;
			pos_a.y=500;
			SDL_BlitSurface(multi_player,NULL,screen_s,&pos_a);
			pos_q.x=1766;
		        pos_q.y=10;
	 	        SDL_BlitSurface(quit,NULL,screen_s,&pos_q);	
			
				SDL_WaitEvent(&event);
				switch(event.type)
				{
					case SDL_QUIT:
					c=0;
					break;
					case SDL_MOUSEBUTTONUP :
					if(event.button.button == SDL_BUTTON_LEFT )
					{
					if(event.button.x>=747 && event.button.x<=1173 && event.button.y>=350 && event.button.y<=450) //CHOIX single
						{
				
							pos_flip.x=747;
	  						pos_flip.y=350;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							next_level=play_game(screen_s,v,touche_state,0);
							Mix_PlayMusic(music,-1);
							screen_s=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
						}
					else if(event.button.x>=747 && event.button.x<=1173 && event.button.y>=500 && event.button.y<=600) //choix multi
						{
				
							pos_flip.x=747;
	  						pos_flip.y=500;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							next_level=multi_game(screen_s,v,touche_state);
							Mix_PlayMusic(music,-1);
							screen_s=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
						}
					else if(event.button.x>=1766 && event.button.x<=1884 && event.button.y>=10 && event.button.y<=125) //quit
						{
				
							pos_flip.x=1769;
	  						pos_flip.y=11;
	  						SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;				
						}	
					}
					break;
					case SDL_MOUSEMOTION :
					if(event.motion.x>=747 && event.motion.x<=1173 && event.motion.y>=350 && event.motion.y<=450) //CHOIX single
					{
						d=1;
						pos_flip.x=747;
	  					pos_flip.y=350;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=747 && event.motion.x<=1173 && event.motion.y>=500 && event.motion.y<=600) //choix multi
					{
						d=1;
						pos_flip.x=747;
	  					pos_flip.y=500;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=1766 && event.motion.x<=1884 && event.motion.y>=10 && event.motion.y<=125) //quit
					{
						d=1;
						pos_flip.x=1769;
	  					pos_flip.y=11;
	  					SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					break;	
					case SDL_KEYDOWN:
					 {
                				switch (event.key.keysym.sym)
             					   {
             						   case SDLK_ESCAPE:
								pos_flip.x=1769;
	  							pos_flip.y=11;
	  							SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
								Mix_PlayChannel(-1,son,0);
               						       c=0;
             						       break;
							   case SDLK_UP:
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
						       	    case SDLK_DOWN:
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
			  					pos_flip.x=747;
	  							pos_flip.y=350;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
              		           	  	        	Mix_PlayChannel(-1,son,0);
								next_level=play_game(screen_s,v,touche_state,0);
								Mix_PlayMusic(music,-1);
								screen_s=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
								}
								if(pos_b==1)
								{
								pos_flip.x=747;
	  							pos_flip.y=500;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
			   					 Mix_PlayChannel(-1,son,0);
                           					 next_level=multi_game(screen_s,v,touche_state);
								Mix_PlayMusic(music,-1);
								screen_s=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
								}		
             							break;
						    }
					  break;	
					 }	
				}//switch
		}
	if(!d && pos_b==0)
   		{
		if(!(*etat)) pos_flip.x=428.5;
		else pos_flip.x=747;
	  	pos_flip.y=350;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		
   		}
   		if(!d && pos_b==1)
   		{
		if(!(*etat)) pos_flip.x=428.5;
		else pos_flip.x=747;
	  	pos_flip.y=500;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		}
  
	SDL_Flip(screen_s);
        Mix_VolumeMusic((*v));
	Mix_VolumeChunk(son,(*v));
	}//while(c)
	Mix_FreeChunk(son);
 	SDL_FreeSurface(back_g); 
 	SDL_FreeSurface(back_gfs);
	SDL_FreeSurface(single_player);
	SDL_FreeSurface(multi_player);
	SDL_FreeSurface(flip);
	SDL_FreeSurface(quit);
	SDL_FreeSurface(quitf);
}

void sous_option(SDL_Surface *screen_s,int *v,int *etat,int *touche_state)
{
	SDL_Surface *back_g =NULL,*back_gfs=NULL,*controls =NULL,*advance=NULL,*flip=NULL,*quit=NULL,*quitf=NULL;
	SDL_Event event;
	Mix_Chunk *son;
	SDL_Rect pos_bg,pos_co,pos_a,pos_flip,pos_q;
	int c=1,d,pos_b=-1;
	SDL_Init(SDL_INIT_VIDEO);
	if(screen_s==NULL)
	{
	  printf("Unable to Set video mode :%s \n",SDL_GetError());
	  return 1;
	}
	

	son =Mix_LoadWAV("son/button-3.wav");
	back_g=IMG_Load("pic/option_1.png");
	back_gfs=IMG_Load("pic/option_1_fs.png");
	controls =IMG_Load("pic/controls.png");
	advance=IMG_Load("pic/advance.png");
	flip =IMG_Load("pic/flip.png");
	quit=IMG_Load("pic/exit.png");
	quitf=IMG_Load("pic/flipq.png");
	while(c)
	{
	SDL_WM_SetCaption("OPTIONS",NULL);
	if(d && pos_b!=-1) pos_b=-1;
	d=0;
		if(!(*etat))
		{
			
			pos_bg.x=0;
			pos_bg.y=0;
			SDL_BlitSurface(back_g,NULL,screen_s,&pos_bg);
			pos_co.x=428.5;
			pos_co.y=350;
			SDL_BlitSurface(controls,NULL,screen_s,&pos_co);
			pos_a.x=428.5;
			pos_a.y=500;
			SDL_BlitSurface(advance,NULL,screen_s,&pos_a);
			pos_q.x=1150;
		        pos_q.y=10;
	 	        SDL_BlitSurface(quit,NULL,screen_s,&pos_q);	
		
				SDL_WaitEvent(&event);
				switch(event.type)
				{
					case SDL_QUIT:
					c=0;
					break;
					case SDL_MOUSEBUTTONUP :
					if(event.button.button == SDL_BUTTON_LEFT )
					{
					if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=350 && event.button.y<=450) //CHOIX DE TOUCHE
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=350;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							choix_touche_menu(screen_s,v,etat,touche_state);
						}
					else if(event.button.x>=428.5 && event.button.x<=854.5 && event.button.y>=500 && event.button.y<=600) //ADVANCE OPTIONS
						{
				
							pos_flip.x=428.5;
	  						pos_flip.y=500;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							option_menu(screen_s,v,etat);
						}
					else if(event.button.x>=1150 && event.button.x<=1268 && event.button.y>=10 && event.button.y<=125) //quit
						{
				
							pos_flip.x=1153;
	  						pos_flip.y=11;
	  						SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;
						}
					}
					break;
					case SDL_MOUSEMOTION :
					if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=350 && event.motion.y<=450) //CHOIX DE TOUCHE
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=350;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=428.5 && event.motion.x<=854.5 && event.motion.y>=500 && event.motion.y<=600) //ADVANCE OPTION
					{
						d=1;
						pos_flip.x=428.5;
	  					pos_flip.y=500;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=1150 && event.motion.x<=1268 && event.motion.y>=10 && event.motion.y<=125) //quit
					{
						d=1;
						pos_flip.x=1153;
	  					pos_flip.y=11;
	  					SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					break;	
					case SDL_KEYDOWN:
					 {
                				switch (event.key.keysym.sym)
             					   {
             						   case SDLK_ESCAPE:
								pos_flip.x=1153;
	  							pos_flip.y=11;
	  							SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
								Mix_PlayChannel(-1,son,0);
               						       c=0;
             						       break;
							   case SDLK_UP:
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
						       	    case SDLK_DOWN:
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
	  							pos_flip.y=350;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
              		           	  	        	Mix_PlayChannel(-1,son,0);
								choix_touche_menu(screen_s,v,etat,touche_state);
								}
								if(pos_b==1)
								{
								pos_flip.x=428.5;
	  							pos_flip.y=500;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
			   					 Mix_PlayChannel(-1,son,0);
                           					 option_menu(screen_s,v,etat);
								}		
             							break;
						    }
					  break;	
					 }	
				}//switch
		}//if(etat)
		else if((*etat)==1)
		{
			pos_bg.x=0;
			pos_bg.y=0;
			SDL_BlitSurface(back_gfs,NULL,screen_s,&pos_bg);
			pos_co.x=747;
			pos_co.y=350;
			SDL_BlitSurface(controls,NULL,screen_s,&pos_co);
			pos_a.x=747;
			pos_a.y=500;
			SDL_BlitSurface(advance,NULL,screen_s,&pos_a);
			pos_q.x=1766;
		        pos_q.y=10;
	 	        SDL_BlitSurface(quit,NULL,screen_s,&pos_q);	
			
				SDL_WaitEvent(&event);
				switch(event.type)
				{
					case SDL_QUIT:
					c=0;
					break;
					case SDL_MOUSEBUTTONUP :
					if(event.button.button == SDL_BUTTON_LEFT )
					{
					if(event.button.x>=747 && event.button.x<=1173 && event.button.y>=350 && event.button.y<=450) //CHOIX DE TOUCHE
						{
				
							pos_flip.x=747;
	  						pos_flip.y=350;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							choix_touche_menu(screen_s,v,etat,touche_state);
						}
					else if(event.button.x>=747 && event.button.x<=1173 && event.button.y>=500 && event.button.y<=600) //ADVANCE OPTIONS
						{
				
							pos_flip.x=747;
	  						pos_flip.y=500;
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							option_menu(screen_s,v,etat);
						}
					else if(event.button.x>=1766 && event.button.x<=1884 && event.button.y>=10 && event.button.y<=125) //quit
						{
				
							pos_flip.x=1769;
	  						pos_flip.y=11;
	  						SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;				
						}	
					}
					break;
					case SDL_MOUSEMOTION :
					if(event.motion.x>=747 && event.motion.x<=1173 && event.motion.y>=350 && event.motion.y<=450) //CHOIX DE TOUCHE
					{
						d=1;
						pos_flip.x=747;
	  					pos_flip.y=350;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=747 && event.motion.x<=1173 && event.motion.y>=500 && event.motion.y<=600) //ADVANCE OPTION
					{
						d=1;
						pos_flip.x=747;
	  					pos_flip.y=500;
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=1766 && event.motion.x<=1884 && event.motion.y>=10 && event.motion.y<=125) //quit
					{
						d=1;
						pos_flip.x=1769;
	  					pos_flip.y=11;
	  					SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					break;	
					case SDL_KEYDOWN:
					 {
                				switch (event.key.keysym.sym)
             					   {
             						   case SDLK_ESCAPE:
								pos_flip.x=1769;
	  							pos_flip.y=11;
	  							SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
								Mix_PlayChannel(-1,son,0);
               						       c=0;
             						       break;
							   case SDLK_UP:
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
						       	    case SDLK_DOWN:
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
			  					pos_flip.x=747;
	  							pos_flip.y=350;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
              		           	  	        	Mix_PlayChannel(-1,son,0);
								choix_touche_menu(screen_s,v,etat,touche_state);
								}
								if(pos_b==1)
								{
								pos_flip.x=747;
	  							pos_flip.y=500;
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
			   					 Mix_PlayChannel(-1,son,0);
                           					 option_menu(screen_s,v,etat);
								}		
             							break;
						    }
					  break;	
					 }	
				}//switch
		}
	if(!d && pos_b==0)
   		{
		if(!(*etat)) pos_flip.x=428.5;
		else pos_flip.x=747;
	  	pos_flip.y=350;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		
   		}
   		if(!d && pos_b==1)
   		{
		if(!(*etat)) pos_flip.x=428.5;
		else pos_flip.x=747;
	  	pos_flip.y=500;
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_Flip(screen_s);
   		}
  
	SDL_Flip(screen_s);
        Mix_VolumeMusic((*v));
	Mix_VolumeChunk(son,(*v));
	}//while(c)
	Mix_FreeChunk(son);
 	SDL_FreeSurface(back_g); 
 	SDL_FreeSurface(back_gfs);
	SDL_FreeSurface(advance);
	SDL_FreeSurface(controls);
	SDL_FreeSurface(flip);
	SDL_FreeSurface(quit);
	SDL_FreeSurface(quitf);
}

void choix_touche_menu(SDL_Surface *screen_s,int *v,int *etat,int *touche_state)
{
SDL_Surface *back_g=NULL,*back_gfs=NULL,*flip =NULL,*keys=NULL,*letters=NULL,*quit=NULL,*quitf=NULL,*text=NULL,*txt=NULL;
SDL_Event event;
Mix_Chunk *son;
TTF_Font *police=NULL;
TTF_Init();
SDL_Color yellow ={255,191,0};
SDL_Rect pos_bg,pos_flip,pos_key,pos_l,pos_q,pos_txt;
int c=1,d,pos_b=-1;
	SDL_Init(SDL_INIT_VIDEO);
	if(screen_s==NULL)
	{
	  printf("Unable to Set video mode :%s \n",SDL_GetError());
	  return 1;
	}
	SDL_WM_SetCaption("CONTROLS",NULL);
	police= TTF_OpenFont("text/spacerangeracad.ttf",45);
	son =Mix_LoadWAV("son/button-3.wav");
	back_g=IMG_Load("pic/option_1.png");
	back_gfs=IMG_Load("pic/option_1_fs.png");
	letters=IMG_Load("pic/letters.png");
	keys=IMG_Load("pic/keys.png");
	flip =IMG_Load("pic/flip_t.png");
	quit=IMG_Load("pic/exit.png");
	quitf=IMG_Load("pic/flipq.png");
	while(c)
	{
	if(d && pos_b!=-1) pos_b=-1;
	d=0;
		if(!(*etat))
		{
			
			pos_bg.x=0;
			pos_bg.y=0;
			SDL_BlitSurface(back_g,NULL,screen_s,&pos_bg);
			if((*touche_state)==1) 
			{
				text=TTF_RenderText_Blended(police,"- HERO moves with (Z,S,D,Q).",yellow);
				pos_txt.x=30;
				pos_txt.y=30;
				SDL_BlitSurface(text,NULL,screen_s,&pos_txt);
			}
			else if (!(*touche_state))
			{
				text=TTF_RenderText_Blended(police,"- HERO moves with ( Up, Down, Right, Left ).",yellow);
				pos_txt.x=30;
				pos_txt.y=30;
				SDL_BlitSurface(text,NULL,screen_s,&pos_txt);
			}
			pos_key.x=100;
			pos_key.y=200;
			SDL_BlitSurface(keys,NULL,screen_s,&pos_key);
			pos_l.x=700;
			pos_l.y=200;
			SDL_BlitSurface(letters,NULL,screen_s,&pos_l);
			pos_q.x=1150;
		        pos_q.y=10;
	 	        SDL_BlitSurface(quit,NULL,screen_s,&pos_q);	
		
				SDL_WaitEvent(&event);
				switch(event.type)
				{
					case SDL_QUIT:
					c=0;
					break;
					case SDL_MOUSEBUTTONUP :
					if(event.button.button == SDL_BUTTON_LEFT )
					{
					if(event.button.x>=100 && event.button.x<=600 && event.button.y>=200 && event.button.y<=577) //keys
						{
				
							pos_flip.x=80;
	  						pos_flip.y=190;
							txt=TTF_RenderText_Blended(police,"(Up,Down,Right,Left)",yellow);
							pos_txt.x=120;
							pos_txt.y=650;
							SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							(*touche_state)=0;
							
						}
					else if(event.button.x>=700 && event.button.x<=1200 && event.button.y>=200 && event.button.y<=577) //letters
						{
				
							pos_flip.x=680;
	  						pos_flip.y=190;
							txt=TTF_RenderText_Blended(police,"(Z,S,D,Q)",yellow);
							pos_txt.x=880;
							pos_txt.y=650;
							SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							(*touche_state)=1;
							
						}
					else if(event.button.x>=1150 && event.button.x<=1268 && event.button.y>=10 && event.button.y<=125) //quit
						{
				
							pos_flip.x=1153;
	  						pos_flip.y=11;
	  						SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;
						}
					}
					break;
					case SDL_MOUSEMOTION :
					if(event.motion.x>=100 && event.motion.x<=600 && event.motion.y>=200 && event.motion.y<=577) //keys
					{
						d=1;
						pos_flip.x=80;
	  					pos_flip.y=190;
						txt=TTF_RenderText_Blended(police,"(Up,Down,Right,Left)",yellow);
						pos_txt.x=120;
						pos_txt.y=650;
						SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=700 && event.motion.x<=1200 && event.motion.y>=200 && event.motion.y<=577) //letters
					{
						d=1;
						pos_flip.x=680;
	  					pos_flip.y=190;
						txt=TTF_RenderText_Blended(police,"(Z,S,D,Q)",yellow);
						pos_txt.x=880;
						pos_txt.y=650;
						SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=1150 && event.motion.x<=1268 && event.motion.y>=10 && event.motion.y<=125) //quit
					{
						d=1;
						pos_flip.x=1153;
	  					pos_flip.y=11;
	  					SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					break;	
					case SDL_KEYDOWN:
					 {
                				switch (event.key.keysym.sym)
             					   {
             						   case SDLK_ESCAPE:
								pos_flip.x=1153;
	  							pos_flip.y=11;
	  							SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
								Mix_PlayChannel(-1,son,0);
               						       c=0;
             						       break;
							   case SDLK_RIGHT:
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
						       	    case SDLK_LEFT:
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
			  					pos_flip.x=80;
	  							pos_flip.y=190;
								txt=TTF_RenderText_Blended(police,"(Up,Down,Right,Left)",yellow);
								pos_txt.x=120;
								pos_txt.y=650;
								SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
              		           	  	        	Mix_PlayChannel(-1,son,0);
								(*touche_state)=0;
								}
								if(pos_b==1)
								{
								pos_flip.x=680;
	  							pos_flip.y=190;
								txt=TTF_RenderText_Blended(police,"(Z,S,D,Q)",yellow);
								pos_txt.x=880;
								pos_txt.y=650;
								SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
			   					 Mix_PlayChannel(-1,son,0);
                           					 (*touche_state)=1;
								}		
             							break;
						    }
					  break;	
					 }	
				}//switch
		}//if(etat)
		else if((*etat)==1)
		{
			pos_bg.x=0;
			pos_bg.y=0;
			SDL_BlitSurface(back_gfs,NULL,screen_s,&pos_bg);
			if((*touche_state)==1) 
			{
				text=TTF_RenderText_Blended(police,"- HERO moves with (Z,S,D,Q).",yellow);
				pos_txt.x=30;
				pos_txt.y=30;
				SDL_BlitSurface(text,NULL,screen_s,&pos_txt);
			}
			else if (!(*touche_state))
			{
				text=TTF_RenderText_Blended(police,"- HERO moves with ( Up, Down, Right, Left ).",yellow);
				pos_txt.x=30;
				pos_txt.y=30;
				SDL_BlitSurface(text,NULL,screen_s,&pos_txt);
			}
			pos_key.x=200;
			pos_key.y=300;
			SDL_BlitSurface(keys,NULL,screen_s,&pos_key);
			pos_l.x=1000;
			pos_l.y=300;
			SDL_BlitSurface(letters,NULL,screen_s,&pos_l);
			pos_q.x=1766;
		        pos_q.y=10;
	 	        SDL_BlitSurface(quit,NULL,screen_s,&pos_q);	
		
				SDL_WaitEvent(&event);
				switch(event.type)
				{
					case SDL_QUIT:
					c=0;
					break;
					case SDL_MOUSEBUTTONUP :
					if(event.button.button == SDL_BUTTON_LEFT )
					{
					if(event.button.x>=200 && event.button.x<=700 && event.button.y>=300 && event.button.y<=677) //keys
						{
							
							pos_flip.x=180;
	  						pos_flip.y=290;
							txt=TTF_RenderText_Blended(police,"(Up,Down,Right,Left)",yellow);
							pos_txt.x=240;
							pos_txt.y=750;
							SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							(*touche_state)=0;
							
						}
					else if(event.button.x>=1000 && event.button.x<=1500 && event.button.y>=300 && event.button.y<=677) //letters
						{
							
							pos_flip.x=980;
	  						pos_flip.y=290;
							txt=TTF_RenderText_Blended(police,"(Z,S,D,Q)",yellow);
							pos_txt.x=1180;
							pos_txt.y=750;
							SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  						SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							(*touche_state)=1;
				
						}
					else if(event.button.x>=1766 && event.button.x<=1884 && event.button.y>=10 && event.button.y<=125) //quit
						{
				
							pos_flip.x=1769;
	  						pos_flip.y=11;
	  						SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
							SDL_Flip(screen_s);
							Mix_PlayChannel(-1,son,0);
							c=0;				
						}	
					}
					break;
					case SDL_MOUSEMOTION :
					if(event.motion.x>=200 && event.motion.x<=700 && event.motion.y>=300 && event.motion.y<=677) //keys
					{
						d=1;
						pos_flip.x=180;
	  					pos_flip.y=290;
						txt=TTF_RenderText_Blended(police,"(Up,Down,Right,Left)",yellow);
							pos_txt.x=240;
							pos_txt.y=750;
							SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=1000 && event.motion.x<=1500 && event.motion.y>=300 && event.motion.y<=677) //letters
					{
						d=1;
						pos_flip.x=980;
	  					pos_flip.y=290;
						txt=TTF_RenderText_Blended(police,"(Z,S,D,Q)",yellow);
							pos_txt.x=1180;
							pos_txt.y=750;
							SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  					SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					else if(event.motion.x>=1766 && event.motion.x<=1884 && event.motion.y>=10 && event.motion.y<=125) //quit
					{
						d=1;
						pos_flip.x=1769;
	  					pos_flip.y=11;
	  					SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
						SDL_Flip(screen_s);
						//Mix_PlayChannel(-1,son,0);
					}
					break;	
					case SDL_KEYDOWN:
					 {
                				switch (event.key.keysym.sym)
             					   {
             						   case SDLK_ESCAPE:
								pos_flip.x=1769;
	  							pos_flip.y=11;
	  							SDL_BlitSurface(quitf,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
								Mix_PlayChannel(-1,son,0);
               						       c=0;
             						       break;
							   case SDLK_RIGHT:
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
						       	    case SDLK_LEFT:
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
			  					pos_flip.x=180;
	  							pos_flip.y=290;
								txt=TTF_RenderText_Blended(police,"(Up,Down,Right,Left)",yellow);
							pos_txt.x=240;
							pos_txt.y=750;
							SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
              		           	  	        	Mix_PlayChannel(-1,son,0);
								(*touche_state)=0;
								}
								if(pos_b==1)
								{
								pos_flip.x=980;
	  							pos_flip.y=290;
								txt=TTF_RenderText_Blended(police,"(Z,S,D,Q)",yellow);
							pos_txt.x=1180;
							pos_txt.y=750;
							SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
	  							SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
								SDL_Flip(screen_s);
			   					 Mix_PlayChannel(-1,son,0);
                           					(*touche_state)=1;
								}		
             							break;
						    }
					  break;	
					 }	
				}//switch
		}
	if(!d && pos_b==0)
   		{
		txt=TTF_RenderText_Blended(police,"(Up,Down,Right,Left)",yellow);
		if(!(*etat)) 
		{
			pos_flip.x=80;
			pos_txt.x=120;
		}
		else 
		{
			pos_flip.x=180;
			pos_txt.x=240;
		}
	  	if(!(*etat)) 
		{
			pos_flip.y=190;
			pos_txt.y=650;
		}
		else 
		{
			pos_flip.y=290;
			pos_txt.y=750;
		}
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
		SDL_Flip(screen_s);
   		
				
				
				
   		}
   		if(!d && pos_b==1)
   		{
		txt=TTF_RenderText_Blended(police,"(Z,S,D,Q)",yellow);
		if(!(*etat)) 
		{
			pos_flip.x=680;
			pos_txt.x=880;
		}
		else 
		{
			pos_flip.x=980;
			pos_txt.x=1180;
		}
	  	if(!(*etat))
		{
			pos_flip.y=190;
			pos_txt.y=650;
		}
		else 
		{
			pos_flip.y=290;
			pos_txt.y=750;
		}
	  	SDL_BlitSurface(flip,NULL,screen_s,&pos_flip);
		SDL_BlitSurface(txt,NULL,screen_s,&pos_txt);
		SDL_Flip(screen_s);
   		}
  
	SDL_Flip(screen_s);
        Mix_VolumeMusic((*v));
	Mix_VolumeChunk(son,(*v));
	}//while(c)
	Mix_FreeChunk(son);
 	SDL_FreeSurface(back_g); 
 	SDL_FreeSurface(back_gfs);
	SDL_FreeSurface(keys);
	SDL_FreeSurface(letters);
	SDL_FreeSurface(flip);
	SDL_FreeSurface(text);
	SDL_FreeSurface(txt);
	SDL_FreeSurface(quit);
	SDL_FreeSurface(quitf);
	TTF_CloseFont(police);
	TTF_Quit();
}
//*******************************************************************************************************************************************************************************************
void option_menu(SDL_Surface *screen_op,int *v,int *etat) 
{
SDL_Surface *mute =NULL,*full_screen =NULL,*window =NULL,*plus =NULL,*moin=NULL,*flip=NULL,*back_g,*flipv=NULL,*text=NULL,*quit,*quitf=NULL,*back_g2=NULL;
SDL_Event event;
Mix_Chunk *son;
TTF_Font *police=NULL;
TTF_Init();
SDL_Color yellow ={255,191,0};
SDL_Rect pos_s,pos_fs,pos_w,pos_p,pos_m,pos_up,pos_mn,pos_t,pos_q,pos_flip,pos_clic;
int b=1,d,CursPositon=-1;
SDL_Init(SDL_INIT_VIDEO);
	if(screen_op==NULL)
	{
	  printf("Unable to Set video mode :%s \n",SDL_GetError());
	  return 1;
	}
SDL_WM_SetCaption("ADVANCE_OPTION",NULL);
police= TTF_OpenFont("text/spacerangeracad.ttf",40);


	son =Mix_LoadWAV("son/button-3.wav");
	mute = IMG_Load("pic/mute.png");
	full_screen = IMG_Load("pic/Fullscreen.png");
	window = IMG_Load("pic/window.png");
	plus = IMG_Load("pic/+.png");
	moin = IMG_Load("pic/-.png");
	flip =	IMG_Load("pic/flipop.png");
	flipv =	IMG_Load("pic/flipv.png");
	back_g=IMG_Load("pic/optionmenu.png");
	back_g2=IMG_Load("pic/optionmenu_resize.png");
	text=TTF_RenderText_Blended(police,"VOLUME",yellow);
	quit =	IMG_Load("pic/exit.png");
	quitf = IMG_Load("pic/flipq.png");
	while(b)
	{
	if(!(*etat)){
		d=0;
		pos_s.x=0;
		pos_s.y=0;
		SDL_BlitSurface(back_g,NULL,screen_op,&pos_s);
	  pos_fs.x=522;
	  pos_fs.y=150;
	  SDL_BlitSurface(full_screen,NULL,screen_op,&pos_fs);
	  pos_w.x=522;
	  pos_w.y=250;
	  SDL_BlitSurface(window,NULL,screen_op,&pos_w);
	  pos_m.x=522;
	  pos_m.y=350;
	  SDL_BlitSurface(mute,NULL,screen_op,&pos_m);
	  pos_p.x=422;
	  pos_p.y=450;
	  SDL_BlitSurface(plus,NULL,screen_op,&pos_p);
	  pos_mn.x=761;
	  pos_mn.y=450;
	  SDL_BlitSurface(moin,NULL,screen_op,&pos_mn);
	  pos_t.x=560;
	  pos_t.y=475;
	  SDL_BlitSurface(text,NULL,screen_op,&pos_t);
	  pos_q.x=1150;
	  pos_q.y=10;
	  SDL_BlitSurface(quit,NULL,screen_op,&pos_q);	

	  SDL_WaitEvent(&event);
	  switch(event.type)
	   {
		case SDL_QUIT:
		b=0;
		break;
		case SDL_MOUSEBUTTONUP :
		if(event.button.button == SDL_BUTTON_LEFT )
		{
			pos_clic.x=event.button.x;
			pos_clic.y=event.button.y;
			if(event.button.x>=522 && event.button.x<=761 && event.button.y>=150 && event.button.y<=222) //full_screen
			{
				
				pos_flip.x=522;
	  			pos_flip.y=150;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
				(*etat)=1;
			}				
			else if(event.button.x>=522 && event.button.x<=761 && event.button.y>=250 && event.button.y<=322) //window
			{

				pos_flip.x=522;
	  			pos_flip.y=250;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1283,733,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
				(*etat)=0;
			}
			else if(event.button.x>=522 && event.button.x<=761 && event.button.y>=350 && event.button.y<=422) //mute
			{
				
				pos_flip.x=522;
	  			pos_flip.y=350;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				if((*v)>=0 || (*v)<=128)
				{
				 (*v)=0;
				}
		                Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
				
			}
			else if(event.button.x>=422 && event.button.x<=522 && event.button.y>=450 && event.button.y<=530) //plus+
			{
				
				pos_flip.x=422;
	  			pos_flip.y=450;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
			     if((*v)>=0 || (*v)<=128) 
				{				
				(*v)+=32;
				}
			      Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
				
			}
			else if(event.button.x>=761 && event.button.x<=861 && event.button.y>=450 && event.button.y<=530) //moin-
			{
				
				pos_flip.x=761;
	  			pos_flip.y=450;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				if((*v)>=0 || (*v)<=128) 
				{
				(*v)-=32;
				}
                                Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
				
			}
			else if(event.button.x>=1150 && event.button.x<=1268 && event.button.y>=10 && event.button.y<=125) //quit
			{
				
				pos_flip.x=1153;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				b=0;
				
			}								
		}
		break;
		case SDL_MOUSEMOTION :
			if(event.motion.x>=522 && event.motion.x<=761 && event.motion.y>=150 && event.motion.y<=222) //fullscreen
			{
				d=1;
				pos_flip.x=522;
	  			pos_flip.y=150;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);
			}				
			else if(event.motion.x>=522 && event.motion.x<=761 && event.motion.y>=250 && event.motion.y<=322) //window
			{
				d=1;

				pos_flip.x=522;
	  			pos_flip.y=250;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=522 && event.motion.x<=761 && event.motion.y>=350 && event.motion.y<=422) //Mute
			{
				d=1;
				
				pos_flip.x=522;
	  			pos_flip.y=350;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=422 && event.motion.x<=522 && event.motion.y>=450 && event.motion.y<=530) //plus
			{
				d=1;
				pos_flip.x=422;
	  			pos_flip.y=450;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=761 && event.motion.x<=861 && event.motion.y>=450 && event.motion.y<=530) //moin
			{
				d=1;
				pos_flip.x=761;
	  			pos_flip.y=450;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=1150 && event.motion.x<=1268 && event.motion.y>=10 && event.motion.y<=125) //quit
			{
				d=1;
				pos_flip.x=1153;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);

			}
		break;
	case SDL_KEYDOWN:

            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
				pos_flip.x=1153;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				b=0;
            }

            else if (event.key.keysym.sym == SDLK_KP_MULTIPLY)

            {

				pos_flip.x=522;
	  			pos_flip.y=350;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				if((*v)>=0 || (*v)<=128)
				{
				 (*v)=0;
				}
		                Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
            }

            else if (event.key.keysym.sym == SDLK_KP_PLUS)
            {
	
				pos_flip.x=422;
	  			pos_flip.y=450;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
			     if((*v)>=0 || (*v)<=128) 
				{				
				(*v)+=32;
				}
			      Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
            }
            
	   else if(event.key.keysym.sym == SDLK_KP_MINUS)
		{
				pos_flip.x=761;
	  			pos_flip.y=450;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				if((*v)>=0 || (*v)<=128) 
				{
				(*v)-=32;
				}
                                Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
				
		}
	else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 2)

            {

				pos_flip.x=522;
	  			pos_flip.y=350;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				if((*v)>=0 || (*v)<=128)
				{
				 (*v)=0;
				}
		                Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
            }
     else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 0)

            {

				pos_flip.x=522;
	  			pos_flip.y=150;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
				(*etat)=1;
            }
	else if (event.key.keysym.sym == SDLK_f)

            {

				pos_flip.x=522;
	  			pos_flip.y=150;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
				(*etat)=1;
            }
	else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 1)

            {
				pos_flip.x=522;
	  			pos_flip.y=250;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1283,733,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);	
				(*etat)=0;
            }
	else if (event.key.keysym.sym == SDLK_w)

            {
				pos_flip.x=522;
	  			pos_flip.y=250;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1283,733,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
				(*etat)=0;
            }
            else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_UP && !d )
            {

               if(event.key.keysym.sym == SDLK_DOWN ||(event.key.keysym.sym == SDLK_UP && CursPositon == -1))
                 {
                    CursPositon++;
                    pos_up.y+=100;
                    if(CursPositon == 3)
                     {
                        CursPositon = 0;
                        pos_up.y = 150;
                     }
                }
                else
                {
                    CursPositon--;
                    pos_up.y-=100;
                    if(CursPositon == -1)
		    {
                        CursPositon = 2;
                        pos_up.y = 350;
                    }   
                }

       	 Mix_PlayChannel(-1, son, 0);
            }

            break;
	   }
	if(!CursPositon && !d)
	   {
	  pos_up.x=522;
	  pos_up.y=150;
	   }
	else if(d || (pos_up.x==522 && pos_up.y==150))
	{
		CursPositon=-1;
		pos_up.x = 2300;
	}
	 if(CursPositon>=0 && CursPositon<=3)
		{
		 SDL_BlitSurface(flip,NULL,screen_op,&pos_up);
		}	
	}
//******************************************************************************************************************************************Resize_Option
		else if((*etat)){
		d=0;
		pos_s.x=0;
		pos_s.y=0;
		SDL_BlitSurface(back_g2,NULL,screen_op,&pos_s);
	  pos_fs.x=830.5;
	  pos_fs.y=250;
	  SDL_BlitSurface(full_screen,NULL,screen_op,&pos_fs);
	  pos_w.x=830.5;
	  pos_w.y=350;
	  SDL_BlitSurface(window,NULL,screen_op,&pos_w);
	  pos_m.x=830.5;
	  pos_m.y=450;
	  SDL_BlitSurface(mute,NULL,screen_op,&pos_m);
	  pos_p.x=722;
	  pos_p.y=550;
	  SDL_BlitSurface(plus,NULL,screen_op,&pos_p);
	  pos_mn.x=1061;
	  pos_mn.y=550;
	  SDL_BlitSurface(moin,NULL,screen_op,&pos_mn);
	  pos_t.x=860;
	  pos_t.y=575;
	  SDL_BlitSurface(text,NULL,screen_op,&pos_t);
	  pos_q.x=1766;
	  pos_q.y=10;
	  SDL_BlitSurface(quit,NULL,screen_op,&pos_q);	

	  SDL_WaitEvent(&event);
	  switch(event.type)
	   {
		case SDL_QUIT:
		b=0;
		break;
		case SDL_MOUSEBUTTONUP :
		if(event.button.button == SDL_BUTTON_LEFT )
		{
			pos_clic.x=event.button.x;
			pos_clic.y=event.button.y;
			if(event.button.x>=830.5 && event.button.x<=1069.5 && event.button.y>=250 && event.button.y<=322) //full_screen
			{
				
				pos_flip.x=830.5;
	  			pos_flip.y=250;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
				(*etat)=1;
			}				
			else if(event.button.x>=830.5 && event.button.x<=1069.5 && event.button.y>=350 && event.button.y<=422) //window
			{

				pos_flip.x=830.5;
	  			pos_flip.y=350;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1283,733,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
				(*etat)=0;
			}
			else if(event.button.x>=830.5 && event.button.x<=1069.5 && event.button.y>=450 && event.button.y<=522) //mute
			{
				
				pos_flip.x=830.5;
	  			pos_flip.y=450;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				if((*v)>=0 || (*v)<=128)
				{
				 (*v)=0;
				}
		                Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
				
			}
			else if(event.button.x>=722 && event.button.x<=822 && event.button.y>=550 && event.button.y<=630) //plus+
			{
				
				pos_flip.x=722;
	  			pos_flip.y=550;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
			     if((*v)>=0 || (*v)<=128) 
				{				
				(*v)+=32;
				}
			      Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
				
			}
			else if(event.button.x>=1061 && event.button.x<=1161 && event.button.y>=550 && event.button.y<=630) //moin-
			{
				
				pos_flip.x=1061;
	  			pos_flip.y=550;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				if((*v)>=0 || (*v)<=128) 
				{
				(*v)-=32;
				}
                                Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
				
			}
			else if(event.button.x>=1766 && event.button.x<=1884 && event.button.y>=10 && event.button.y<=125) //quit
			{
				
				pos_flip.x=1769;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				b=0;
				
			}								
		}
		break;
		case SDL_MOUSEMOTION :
			if(event.motion.x>=830.5 && event.motion.x<=1069 && event.motion.y>=250 && event.motion.y<=322) //fullscreen
			{
				d=1;
				pos_flip.x=830.5;
	  			pos_flip.y=250;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);
			}				
			else if(event.motion.x>=830.5 && event.motion.x<=1069 && event.motion.y>=350 && event.motion.y<=422) //window
			{
				d=1;

				pos_flip.x=830.5;
	  			pos_flip.y=350;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=830.5 && event.motion.x<=1069 && event.motion.y>=450 && event.motion.y<=522) //Mute
			{
				d=1;
				
				pos_flip.x=830.5;
	  			pos_flip.y=450;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=722 && event.motion.x<=822 && event.motion.y>=550 && event.motion.y<=630) //plus
			{
				d=1;
				pos_flip.x=722;
	  			pos_flip.y=550;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=1061 && event.motion.x<=1161 && event.motion.y>=550 && event.motion.y<=630) //moin
			{
				d=1;
				pos_flip.x=1061;
	  			pos_flip.y=550;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=1766 && event.motion.x<=1884 && event.motion.y>=10 && event.motion.y<=125) //quit
			{
				d=1;
				pos_flip.x=1769;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				//Mix_PlayChannel(-1,son,0);

			}
		break;
	case SDL_KEYDOWN:

            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
				pos_flip.x=1769;
	  			pos_flip.y=11;
	  			SDL_BlitSurface(quitf,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				b=0;
            }

            else if (event.key.keysym.sym == SDLK_KP_MULTIPLY)

            {

				pos_flip.x=830.5;
	  			pos_flip.y=450;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				if((*v)>=0 || (*v)<=128)
				{
				 (*v)=0;
				}
		                Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
            }

            else if (event.key.keysym.sym == SDLK_KP_PLUS)
            {
	
				pos_flip.x=722;
	  			pos_flip.y=550;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
			     if((*v)>=0 || (*v)<=128) 
				{				
				(*v)+=32;
				}
			      Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
            }
            
	   else if(event.key.keysym.sym == SDLK_KP_MINUS)
		{
				pos_flip.x=1061;
	  			pos_flip.y=550;
	  			SDL_BlitSurface(flipv,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				if((*v)>=0 || (*v)<=128) 
				{
				(*v)-=32;
				}
                                Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
				
		}
	else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 2)

            {

				pos_flip.x=830.5;
	  			pos_flip.y=450;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				if((*v)>=0 || (*v)<=128)
				{
				 (*v)=0;
				}
		                Mix_VolumeMusic((*v));
				Mix_VolumeChunk(son,(*v));
	
            }
     else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 0)

            {

				pos_flip.x=830.5;
	  			pos_flip.y=250;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
				(*etat)=1;
            }
	else if (event.key.keysym.sym == SDLK_f)

            {

				pos_flip.x=830.5;
	  			pos_flip.y=250;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
				(*etat)=1;
            }
	else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 1)

            {
				pos_flip.x=830.5;
	  			pos_flip.y=350;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1283,733,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);	
				(*etat)=0;
				 pos_up.x=522;
	  			pos_up.y=250;
            }
	else if (event.key.keysym.sym == SDLK_w)

            {
				pos_flip.x=830.5;
	  			pos_flip.y=350;
	  			SDL_BlitSurface(flip,NULL,screen_op,&pos_flip);
				SDL_Flip(screen_op);
				Mix_PlayChannel(-1,son,0);
				screen_op =SDL_SetVideoMode(1283,733,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
				(*etat)=0;
				 pos_up.x=522;
	  			pos_up.y=250;
            }
            else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_UP && !d )
            {

               if(event.key.keysym.sym == SDLK_DOWN ||(event.key.keysym.sym == SDLK_UP && CursPositon == -1))
                 {
                    CursPositon++;
                    pos_up.y+=100;
                    if(CursPositon == 3)
                     {
                        CursPositon = 0;
                        pos_up.y = 250;
                     }
                }
                else
                {
                    CursPositon--;
                    pos_up.y-=100;
                    if(CursPositon == -1)
		    {
                        CursPositon = 2;
                        pos_up.y = 450;
                    }   
                }

       	 Mix_PlayChannel(-1, son, 0);
            }

            break;
	   }
	if(!CursPositon && !d)
	   {
	  pos_up.x=830.5;
	  pos_up.y=250;
	   }
	else if(d || (pos_up.x==830.5 && pos_up.y==250))
	{
		CursPositon=-1;
		pos_up.x = 2300;
	}
if(CursPositon>=0 && CursPositon<=3)
		{
		 SDL_BlitSurface(flip,NULL,screen_op,&pos_up);
		}	
	}
	SDL_Flip(screen_op);
         Mix_VolumeMusic((*v));
	Mix_VolumeChunk(son,(*v));
     }
	Mix_FreeChunk(son);
	SDL_FreeSurface(back_g);
	SDL_FreeSurface(back_g2);
	SDL_FreeSurface(full_screen);
	SDL_FreeSurface(flip);
	SDL_FreeSurface(quit);        
	SDL_FreeSurface(window);
	SDL_FreeSurface(mute);
	SDL_FreeSurface(plus);
	SDL_FreeSurface(moin);
	SDL_FreeSurface(flipv);
	SDL_FreeSurface(text);
	SDL_FreeSurface(quitf);
    }

//*******************************************************************************************************************************************************************************************************
void setrect(SDL_Rect* clip)
{
	for(int i=0;i<18;i++)
	{
	clip[i].x=0+i*100;
	clip[i].y=0;
	clip[i].w=100;
	clip[i].h=100;
	}
}
void menu(int *touche_state)
{
   SDL_Surface *screen = NULL, *image =NULL,*play =NULL,*option =NULL,*credit =NULL,*load=NULL,*text=NULL,*text2=NULL,*quit=NULL,*star=NULL,*flip=NULL,*flipq=NULL,*play2=NULL,*load2=NULL,*option2=NULL,*credit2=NULL,*image1=NULL;
   Mix_Music *music;
   SDL_Event event;
   Mix_Chunk *son;
   SDL_Rect pos,poss,pos1,pos2,pos3,pos4,pos5,posclic,pos_up,rect[18],pos_star;
   TTF_Font *police=NULL,*police2=NULL;
   SDL_Color noir = {0, 0, 0};
   SDL_Color yellow ={255,191,0};
   int c=1,d=0,vo=128,etat=0,next_level=-1;
   int CursPositon=-1;
  //******************
   Uint32 start;
  const int FPS=20;
   int frame=0;
   setrect(rect);
//*******************
   SDL_Init(SDL_INIT_EVERYTHING);	
   TTF_Init();
   police= TTF_OpenFont("text/spacerangeracad.ttf",65);
   police2 = TTF_OpenFont("text/spacerangeracad.ttf", 120);
   if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
	  printf("Unable to initialize SDL :%s \n",SDL_GetError());
	  return 1;
	}
	screen =SDL_SetVideoMode(1283,733,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	if(screen==NULL)
	{
	  printf("Unable to Set video mode :%s \n",SDL_GetError());
	  return 1;
	}
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1) 
	{
		printf("%s",Mix_GetError());
   	}
	flipq = IMG_Load("pic/flipq.png");
	music = Mix_LoadMUS("son/song.mp3");
	Mix_PlayMusic(music,-1);
	son =Mix_LoadWAV("son/button-3.wav");
	image = IMG_Load("pic/background.png");
	image1= IMG_Load("pic/background_2.png");
	play = IMG_Load("pic/play.png");
	play2 = IMG_Load("pic/play2.png");
	load = IMG_Load("pic/load.png");
	load2 = IMG_Load("pic/load2.png");
	option = IMG_Load("pic/option.png");
	option2 = IMG_Load("pic/option2.png");
	credit = IMG_Load("pic/credit.png");
	credit2 = IMG_Load("pic/credit2.png");
	quit =	IMG_Load("pic/exit.png");
	flip =	IMG_Load("pic/flip.png");
	star=IMG_Load("pic/sprite3.png");
  	text =TTF_RenderText_Blended(police,"GAME-MASTERS",yellow);
   	text2 = TTF_RenderText_Blended(police2,"The    001", noir);
	while(c)
	{
	
	SDL_EnableKeyRepeat(0,10);
	 start= SDL_GetTicks();
	if(!etat){
	  d=0;
	 SDL_WM_SetCaption("THE-001",NULL);
//*****************
	  pos.x=0;
	  pos.y=0;
	  SDL_BlitSurface(image,NULL,screen,&pos);
	  poss.x=360;
	  poss.y=15;
	  SDL_BlitSurface(text2,NULL,screen,&poss);
	  pos1.x=15;
	  pos1.y=200;
	  SDL_BlitSurface(play,NULL,screen,&pos1);
	  pos2.x=15;
	  pos2.y=310;
	  SDL_BlitSurface(load,NULL,screen,&pos2);
	  pos3.x=15;
	  pos3.y=420;
	  SDL_BlitSurface(option,NULL,screen,&pos3);
	  pos4.x=15;
	  pos4.y=530;
	  SDL_BlitSurface(credit,NULL,screen,&pos4);
	  pos.x=785;
	  pos.y=665;
	  SDL_BlitSurface(text,NULL,screen,&pos);
	  pos5.x=1150;
	  pos5.y=10;
	  SDL_BlitSurface(quit,NULL,screen,&pos5);
	   pos_star.x=593.5;
	  pos_star.y=14;
	  SDL_BlitSurface(star,&rect[frame],screen,&pos_star);
       	 frame++;
		if(frame==18)
	{
		frame=0;
	}
//***********************
	
	  while(SDL_PollEvent(&event))
	{
	switch(event.type)
	   {
		case SDL_QUIT:
		c=0;
		break;
		case SDL_MOUSEBUTTONUP :
		if(event.button.button == SDL_BUTTON_LEFT )
		{

			if(event.button.x>=15 && event.button.x<=441 && event.button.y>=200 && event.button.y<=300)
			{

				pos1.x=15;
	  			pos1.y=200;
	  			SDL_BlitSurface(play2,NULL,screen,&pos1);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				choix_jouer(screen,&vo,&etat,(*touche_state));
			}				
			else if(event.button.x>=15 && event.button.x<=441 && event.button.y>=310 && event.button.y<=410)
			{
				pos2.x=15;
	  			pos2.y=310;
	  			SDL_BlitSurface(load2,NULL,screen,&pos2);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				next_level=play_game(screen,&vo,(*touche_state),1);
				Mix_PlayMusic(music,-1);
				
	
			}
			else if(event.button.x>=15 && event.button.x<=441 && event.button.y>=420 && event.button.y<=520)
			{

				pos3.x=15;
	  			pos3.y=420;
	  			SDL_BlitSurface(option2,NULL,screen,&pos3);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				sous_option(screen,&vo,&etat,touche_state);
				
			}
			else if(event.button.x>=15 && event.button.x<=441 && event.button.y>=530 && event.button.y<=630)
			{
	
				pos4.x=15;
	  			pos4.y=530;
	  			SDL_BlitSurface(credit2,NULL,screen,&pos4);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				credit_menu(screen,etat);
			}
			else if(event.button.x>=1150 && event.button.x<=1268 && event.button.y>=10 && event.button.y<=125)
			{
	
				pos5.x=1153;
	  			pos5.y=11;
	  			SDL_BlitSurface(flipq,NULL,screen,&pos5);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				c=0;
			}								
		}
		break;
		case SDL_MOUSEMOTION :

			 if(event.motion.x>=15 && event.motion.x<=441 && event.motion.y>=200 && event.motion.y<=300)
			{
				d=1;

				pos1.x=15;
	  			pos1.y=200;
	  			SDL_BlitSurface(play2,NULL,screen,&pos1);
				SDL_Flip(screen);
				
				
				//Mix_PlayChannel(-1,son,0);
			}				
			else if(event.motion.x>=15 && event.motion.x<=441 && event.motion.y>=310 && event.motion.y<=410)
			{
				d=1;
		
				pos2.x=15;
	  			pos2.y=310;
	  			SDL_BlitSurface(load2,NULL,screen,&pos2);
				SDL_Flip(screen);
				
				
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=15 && event.motion.x<=441 && event.motion.y>=420 && event.motion.y<=520)
			{
				d=1;
		
				pos3.x=15;
	  			pos3.y=420;
	  			SDL_BlitSurface(option2,NULL,screen,&pos3);
				SDL_Flip(screen);
				
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=15 && event.motion.x<=441 && event.motion.y>=530 && event.motion.y<=630)
			{
				d=1;

				pos4.x=15;
	  			pos4.y=530;
	  			SDL_BlitSurface(credit2,NULL,screen,&pos4);
				SDL_Flip(screen);
	
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=1150 && event.motion.x<=1268 && event.motion.y>=10 && event.motion.y<=125)
			{
				d=1;
				
				pos.x=1153;
	  			pos.y=11;
	  			SDL_BlitSurface(flipq,NULL,screen,&pos);
				SDL_Flip(screen);
				
				//Mix_PlayChannel(-1,son,0);

			}
		break;	
	case SDL_KEYDOWN:
           if (event.key.keysym.sym == SDLK_p)
            {
			
				pos1.x=15;
	  			pos1.y=200;
	  			SDL_BlitSurface(play2,NULL,screen,&pos1);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				choix_jouer(screen,&vo,&etat,(*touche_state));
            }
	else if (event.key.keysym.sym == SDLK_l)
            {
			
				pos2.x=15;
	  			pos2.y=310;
	  			SDL_BlitSurface(load2,NULL,screen,&pos2);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				next_level=play_game(screen,&vo,(*touche_state),1);
				Mix_PlayMusic(music,-1);
            }


            else if (event.key.keysym.sym == SDLK_o)

            {

				pos3.x=15;
	  			pos3.y=420;
	  			SDL_BlitSurface(option2,NULL,screen,&pos3);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				sous_option(screen,&vo,&etat,touche_state);
            }

            else if (event.key.keysym.sym == SDLK_c)
            {
				pos4.x=15;
	  			pos4.y=530;
	  			SDL_BlitSurface(credit2,NULL,screen,&pos4);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				
				credit_menu(screen,etat);
            }
            
	   else if(event.key.keysym.sym == SDLK_ESCAPE)
		{
				pos5.x=1153;
	  			pos5.y=11;
	  			SDL_BlitSurface(flipq,NULL,screen,&pos5);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				c=0;

		}
	 else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 0)

            {
				pos1.x=15;
	  			pos1.y=200;
	  			SDL_BlitSurface(play2,NULL,screen,&pos1);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				choix_jouer(screen,&vo,&etat,(*touche_state));
				
            }
		 else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 1)

            {
			
				pos2.x=15;
	  			pos2.y=310;
	  			SDL_BlitSurface(load2,NULL,screen,&pos2);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				next_level=play_game(screen,&vo,(*touche_state),1);
				Mix_PlayMusic(music,-1);
            }
		 else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 2)

            {
				pos3.x=15;
	  			pos3.y=420;
	  			SDL_BlitSurface(option2,NULL,screen,&pos3);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				sous_option(screen,&vo,&etat,touche_state);
				
            }
		 else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 3)

            {

		
				pos4.x=15;
	  			pos4.y=530;
	  			SDL_BlitSurface(credit2,NULL,screen,&pos4);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				credit_menu(screen,etat);
            }
            else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_UP && !d )
            {

                if(event.key.keysym.sym == SDLK_DOWN ||(event.key.keysym.sym == SDLK_UP && CursPositon == -1))
                 {
                    CursPositon++;
                    pos_up.y+=110;
                    if(CursPositon == 4)
                     {
                        CursPositon = 0;
                        pos_up.y = 200;
                     }
                }
                else
                {
		
                    CursPositon--;
                    pos_up.y-=110;
                    if(CursPositon == -1)
		    {
                        CursPositon = 3;
                        pos_up.y = 530;
                    }   

                }

       	 Mix_PlayChannel(-1, son, 0);
            }

            break;
	   }
	}
	if(!CursPositon && !d)
	   {
	   pos_up.x = 15;
   	   pos_up.y = 200;
	   }
	else if(d || (pos_up.x==15 && pos_up.y==200))
	{
		CursPositon=-1;
		pos_up.x = 2300;
		pos_up.y=1700;
	}
	 if(CursPositon>=0 && CursPositon<=4)
	{
	SDL_BlitSurface(flip, NULL, screen, &pos_up);
	}
   	}
//**************************************************************************************************************************************RESIze Menu..........-(-(-(-(
	else if(etat){
	d=0;
	
//*****************
	  pos.x=0;
	  pos.y=0;
	  SDL_BlitSurface(image1,NULL,screen,&pos);
	  poss.x=660;
	  poss.y=20;
	  SDL_BlitSurface(text2,NULL,screen,&poss);
	  pos1.x=15;
	  pos1.y=200;
	  SDL_BlitSurface(play,NULL,screen,&pos1);
	  pos2.x=15;
	  pos2.y=310;
	  SDL_BlitSurface(load,NULL,screen,&pos2);
	  pos3.x=15;
	  pos3.y=420;
	  SDL_BlitSurface(option,NULL,screen,&pos3);
	  pos4.x=15;
	  pos4.y=530;
	  SDL_BlitSurface(credit,NULL,screen,&pos4);
	  pos.x=1350;
	  pos.y=1100;
	  SDL_BlitSurface(text,NULL,screen,&pos);
	  pos5.x=1766;
	  pos5.y=10;
	  SDL_BlitSurface(quit,NULL,screen,&pos5);
	   pos_star.x=900;
	  pos_star.y=14;
	  SDL_BlitSurface(star,&rect[frame],screen,&pos_star);
       	 frame++;
		if(frame==18)
	{
		frame=0;
	}
//***********************
	
	  while(SDL_PollEvent(&event))
	{
	switch(event.type)
	   {
		case SDL_QUIT:
		c=0;
		break;
		case SDL_MOUSEBUTTONUP :
		if(event.button.button == SDL_BUTTON_LEFT )
		{

			if(event.button.x>=15 && event.button.x<=441 && event.button.y>=200 && event.button.y<=300)
			{

	  			SDL_BlitSurface(play2,NULL,screen,&pos1);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				choix_jouer(screen,&vo,&etat,(*touche_state));
			}				
			else if(event.button.x>=15 && event.button.x<=441 && event.button.y>=310 && event.button.y<=410)
			{
				
	  			SDL_BlitSurface(load2,NULL,screen,&pos2);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				next_level=play_game(screen,&vo,(*touche_state),1);
				Mix_PlayMusic(music,-1);
				screen=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
	
			}
			else if(event.button.x>=15 && event.button.x<=441 && event.button.y>=420 && event.button.y<=520)
			{

				
	  			SDL_BlitSurface(option2,NULL,screen,&pos3);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				sous_option(screen,&vo,&etat,touche_state);
				
			}
			else if(event.button.x>=15 && event.button.x<=441 && event.button.y>=530 && event.button.y<=630)
			{
	
				
	  			SDL_BlitSurface(credit2,NULL,screen,&pos4);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				credit_menu(screen,etat);
			}
			else if(event.button.x>=1766 && event.button.x<=1884 && event.button.y>=10 && event.button.y<=125)
			{
	
				pos5.x=1769;
	  			pos5.y=11;
	  			SDL_BlitSurface(flipq,NULL,screen,&pos5);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				c=0;
			}								
		}
		break;
		case SDL_MOUSEMOTION :

			 if(event.motion.x>=15 && event.motion.x<=441 && event.motion.y>=200 && event.motion.y<=300)
			{
				d=1;

				
	  			SDL_BlitSurface(play2,NULL,screen,&pos1);
				SDL_Flip(screen);
				
				
				//Mix_PlayChannel(-1,son,0);
			}				
			else if(event.motion.x>=15 && event.motion.x<=441 && event.motion.y>=310 && event.motion.y<=410)
			{
				d=1;
		
				
	  			SDL_BlitSurface(load2,NULL,screen,&pos2);
				SDL_Flip(screen);
				
				
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=15 && event.motion.x<=441 && event.motion.y>=420 && event.motion.y<=520)
			{
				d=1;
		
				
	  			SDL_BlitSurface(option2,NULL,screen,&pos3);
				SDL_Flip(screen);
				
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=15 && event.motion.x<=441 && event.motion.y>=530 && event.motion.y<=630)
			{
				d=1;

				
	  			SDL_BlitSurface(credit2,NULL,screen,&pos4);
				SDL_Flip(screen);
	
				//Mix_PlayChannel(-1,son,0);
			}
			else if(event.motion.x>=1766 && event.motion.x<=1884 && event.motion.y>=10 && event.motion.y<=125)
			{
				d=1;
				
				pos.x=1769;
	  			pos.y=11;
	  			SDL_BlitSurface(flipq,NULL,screen,&pos);
				SDL_Flip(screen);
				
				//Mix_PlayChannel(-1,son,0);

			}
		break;	
	case SDL_KEYDOWN:
           if (event.key.keysym.sym == SDLK_p)
            {
			
				
	  			SDL_BlitSurface(play2,NULL,screen,&pos1);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				choix_jouer(screen,&vo,&etat,(*touche_state));
            }
	else if (event.key.keysym.sym == SDLK_l)
            {
			
				
	  			SDL_BlitSurface(load2,NULL,screen,&pos2);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				next_level=play_game(screen,&vo,(*touche_state),1);
				Mix_PlayMusic(music,-1);
				screen=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
            }


            else if (event.key.keysym.sym == SDLK_o)

            {

				
	  			SDL_BlitSurface(option2,NULL,screen,&pos3);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				sous_option(screen,&vo,&etat,touche_state);
            }

            else if (event.key.keysym.sym == SDLK_c)
            {
				
	  			SDL_BlitSurface(credit2,NULL,screen,&pos4);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				
				credit_menu(screen,etat);
            }
            
	   else if(event.key.keysym.sym == SDLK_ESCAPE)
		{
				pos5.x=1769;
	  			pos5.y=11;
	  			SDL_BlitSurface(flipq,NULL,screen,&pos5);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				c=0;

		}
	 else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 0)

            {
				
	  			SDL_BlitSurface(play2,NULL,screen,&pos1);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				choix_jouer(screen,&vo,&etat,(*touche_state));
				
            }
		 else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 1)

            {
			
				
	  			SDL_BlitSurface(load2,NULL,screen,&pos2);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				next_level=play_game(screen,&vo,(*touche_state),1);
				Mix_PlayMusic(music,-1);
				screen=SDL_SetVideoMode(1920,1200,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN);
            }
		 else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 2)

            {
				
	  			SDL_BlitSurface(option2,NULL,screen,&pos3);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				sous_option(screen,&vo,&etat,touche_state);
				
            }
		 else if (event.key.keysym.sym == SDLK_RETURN && CursPositon == 3)

            {

		
				
	  			SDL_BlitSurface(credit2,NULL,screen,&pos4);
				SDL_Flip(screen);
				Mix_PlayChannel(-1,son,0);
				credit_menu(screen,etat);
            }
            else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_UP && !d )
            {

                if(event.key.keysym.sym == SDLK_DOWN ||(event.key.keysym.sym == SDLK_UP && CursPositon == -1))
                 {
                    CursPositon++;
                    pos_up.y+=110;
                    if(CursPositon == 4)
                     {
                        CursPositon = 0;
                        pos_up.y = 200;
                     }
                }
                else
                {
		
                    CursPositon--;
                    pos_up.y-=110;
                    if(CursPositon == -1)
		    {
                        CursPositon = 3;
                        pos_up.y = 530;
                    }   

                }

       	 Mix_PlayChannel(-1, son, 0);
            }

            break;
	   }
	}
	if(!CursPositon && !d)
	   {
	   pos_up.x = 15;
   	   pos_up.y = 200;
	   }
	else if(d || (pos_up.x==15 && pos_up.y==200))
	{
		CursPositon=-1;
		pos_up.x = 2300;
		pos_up.y=1700;
	}
	 if(CursPositon>=0 && CursPositon<=4)
	{
	SDL_BlitSurface(flip,NULL, screen,&pos_up);
	}
    }
//***************************************************
	SDL_Flip(screen);
	Mix_VolumeMusic(vo);
	Mix_VolumeChunk(son,vo);
	if(1000/FPS > SDL_GetTicks()-start) 
	{
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }

 }
	Mix_FreeChunk(son);
	Mix_FreeMusic(music);
	SDL_FreeSurface(screen); 
	SDL_FreeSurface(image);
	SDL_FreeSurface(play);
	SDL_FreeSurface(option);
	SDL_FreeSurface(credit);
	SDL_FreeSurface(load);
	SDL_FreeSurface(text);
	SDL_FreeSurface(text2);
	SDL_FreeSurface(quit);
	SDL_FreeSurface(star);
	SDL_FreeSurface(flip);
	SDL_FreeSurface(flipq);
	SDL_FreeSurface(play2);
	SDL_FreeSurface(load2);
	SDL_FreeSurface(option2);
	SDL_FreeSurface(credit2);
	SDL_FreeSurface(image1);			
	SDL_Quit();
	TTF_CloseFont(police);
	TTF_Quit();
}

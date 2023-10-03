#include "enigme_integ.h"

int enigme_sf(int *v,SDL_Surface *ecran)
{
    enigme e;
    SDL_Event event;
    int continuer=1,pos,pos_b=-1,d;
    int answer=-1;
    Mix_Chunk *son;
    Mix_Music *music;
    if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("Unable to initialize SDL:%s\n",SDL_GetError());
        return 1;
    }
    ecran=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF );
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1) 
	{
		printf("%s",Mix_GetError());
   	}
  
    music = Mix_LoadMUS("son/music.mp3");
      son =Mix_LoadWAV("son/swipe.wav");
    Mix_PlayMusic(music,-1);
    e=init_enigme(e);
    e=generer(e);
    while(continuer)
    {
	SDL_EnableKeyRepeat(0,10);
	if(d && pos_b!=-1) pos_b=-1;
        d=0;
        afficheEnigme(e,ecran);
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
             case SDL_MOUSEMOTION :
			if(event.motion.x>=100 && event.motion.x<=339 && event.motion.y>=500 && event.motion.y<=573)
			{
			d=1;
			e.flip.pos.y=e.b[0].pos.y;
                       e.flip.pos.x=e.b[0].pos.x;

                            SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
                            SDL_Flip(ecran);
				
			}				
			else if(event.motion.x>=500 && event.motion.x<=739 && event.motion.y>=500 && event.motion.y<=573)
			{
			d=1;
			e.flip.pos.y=e.b[1].pos.y;
                       e.flip.pos.x=e.b[1].pos.x;

                            SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
                            SDL_Flip(ecran);	
			}
			else if(event.motion.x>=900 && event.motion.x<=1139 && event.motion.y>=500 && event.motion.y<=573)
			{
			d=1;
			e.flip.pos.y=e.b[2].pos.y;
                       e.flip.pos.x=e.b[2].pos.x;

                            SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
                            SDL_Flip(ecran);
				
			}
			break;
             
             case SDL_MOUSEBUTTONUP :
                    if(event.button.button == SDL_BUTTON_LEFT )
                    {

                        if(event.button.x>=100 && event.button.x<=339 && event.button.y>=500 && event.button.y<=573)
                        {
			     pos=0;
                            e.flip.pos.y=e.b[0].pos.y;
                            e.flip.pos.x=e.b[0].pos.x;

                            SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
                            SDL_Flip(ecran);
			    Mix_PlayChannel(-1,son,0);
			     answer=resoudreEnigme(&e,pos);
				if(answer==0 || answer==1) continuer=0;

                        }
                        else if(event.button.x>=500 && event.button.x<=739 && event.button.y>=500 && event.button.y<=573)
                        {
			     pos=1;
                            e.flip.pos.y=e.b[1].pos.y;
                            e.flip.pos.x=e.b[1].pos.x;

                            SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
                            SDL_Flip(ecran);
			    Mix_PlayChannel(-1,son,0);
                            answer=resoudreEnigme(&e,pos);
				if(answer==0 || answer==1) continuer=0;


                        }
                        else if(event.button.x>=900 && event.button.x<=1139 && event.button.y>=500 && event.button.y<=573)
                        {
			     pos=2;
                            e.flip.pos.y=e.b[2].pos.y;
                            e.flip.pos.x=e.b[2].pos.x;

                            SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
                            SDL_Flip(ecran);
			    Mix_PlayChannel(-1,son,0);
                            answer=resoudreEnigme(&e,pos);

				if(answer==0 || answer==1) continuer=0;

                        }
                        
                    }
                    break;
            
            case SDL_KEYDOWN:
            {
                switch (event.key.keysym.sym)
                {
                
               case SDLK_RIGHT:
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
		case SDLK_LEFT:
			if(d==0)
			{
			if(pos_b<=0)
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
			   pos=0;
                            e.flip.pos.y=e.b[0].pos.y;
                            e.flip.pos.x=e.b[0].pos.x;
                            SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
                            SDL_Flip(ecran);
			    Mix_PlayChannel(-1,son,0);
			    answer=resoudreEnigme(&e,pos);
			if(answer==0 || answer==1) continuer=0;
		}
		if(pos_b==1)
		{
			     pos=1;
                            e.flip.pos.y=e.b[1].pos.y;
                            e.flip.pos.x=e.b[1].pos.x;

                            SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
                            SDL_Flip(ecran);
			    Mix_PlayChannel(-1,son,0);
                            answer=resoudreEnigme(&e,pos);
				if(answer==0 || answer==1) continuer=0;
		}
		if(pos_b==2)
		{
			     pos=2;
                            e.flip.pos.y=e.b[2].pos.y;
                            e.flip.pos.x=e.b[2].pos.x;

                            SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
                            SDL_Flip(ecran);
			    Mix_PlayChannel(-1,son,0);
                            answer=resoudreEnigme(&e,pos);
			if(answer==0 || answer==1) continuer=0;
		}
               break;
                }
            }
            }


        }
   		if(!d && pos_b==0)
   		{e.flip.pos.y=e.b[0].pos.y;
                e.flip.pos.x=e.b[0].pos.x;
			
                        SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
   			SDL_Flip(ecran);
   		}
   		if(!d && pos_b==1)
   		{	
				e.flip.pos.y=e.b[1].pos.y;
	                	e.flip.pos.x=e.b[1].pos.x;
                               SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
   				SDL_Flip(ecran);
   		}
   		if(!d && pos_b==2)
   		{
		e.flip.pos.y=e.b[2].pos.y;
                e.flip.pos.x=e.b[2].pos.x;
                        SDL_BlitSurface(e.flip.bouton,NULL,ecran,&e.flip.pos);
			SDL_Flip(ecran);
		
   		}
	SDL_Flip(ecran);
 Mix_VolumeMusic((*v));
Mix_VolumeChunk(son,(*v));
    }
	
	Mix_FreeChunk(son);
	Mix_FreeMusic(music);
	TTF_CloseFont(e.police);
	SDL_FreeSurface(e.background);
	TTF_Quit();
	if(!answer) return 1;
	else if(answer==1) return 0;
}

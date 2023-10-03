#ifndef BACKG_DEF
#define BACKG_DEF
#include "perso.h"
	typedef struct
	       {
			
	    SDL_Surface *bg,*mask;	               
            SDL_Rect pos_bg;
            SDL_Rect camera;
            int direction; 
		}background;
	
		 void initialiser_background(background *bg);            
		void afficher_background(background bg,SDL_Surface *screen);
                void scrolling(background *bg,Personne p,int col,int col2,int col3,int col4);
#endif       


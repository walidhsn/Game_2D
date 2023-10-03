#include "collision.h"
SDL_Color GetPixel (SDL_Surface* pSurface , pos tab)
{
    int x,y;
    x = tab.x;
    y = tab.y;
    SDL_Color color;
    Uint32 col = 0 ;
    if (x >= 0 && y >= 0)
    {
        //determine position
        char* pPosition = ( char* ) pSurface->pixels ;

        //offset by y
        pPosition += ( pSurface->pitch * y ) ;

        //offset by x
        pPosition += ( pSurface->format->BytesPerPixel * x ) ;

        //copy pixel data
        memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

        //convert color
    }
    SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
    return ( color ) ;
}

int update_collision(pos poss[],SDL_Rect posperso)
{
//point up:
	poss[0].x =posperso.x + (posperso.w/2);
	poss[0].y = posperso.y;
//point down:
	poss[1].x = posperso.x + (posperso.w/2);
	poss[1].y = posperso.y + (posperso.h);
//point gauche:
	poss[2].x =posperso.x;
	poss[2].y = posperso.y;

	poss[3].x =posperso.x;
	poss[3].y = posperso.y + (posperso.h/2);

	poss[4].x =posperso.x;
	poss[4].y = posperso.y + (posperso.h);
//point droite:
	poss[5].x =posperso.x + (posperso.w);
	poss[5].y = posperso.y;
	
	poss[6].x =posperso.x + (posperso.w);
	poss[6].y = posperso.y + (posperso.h);
	
	poss[7].x =posperso.x + (posperso.w);
	poss[7].y = posperso.y + (posperso.h/2);
	
}
int collisionParfaite_up(SDL_Surface *backgmasque,pos poss[])
{
	SDL_Color  color_up  ;
	int coll= 0;
	color_up = GetPixel (backgmasque , poss[0]);
	 if(color_up.r==255 && color_up.g==255 && color_up.b==255)
	   {
	     coll= 1;
	   }
	printf("%d",coll);
	return coll;
}

int collisionParfaite_down(SDL_Surface *backgmasque,pos poss[])
{
	SDL_Color  color_down  ;
	int coll= 0;
	color_down = GetPixel (backgmasque , poss[1]);
	 if(color_down.r==255 && color_down.g==255 && color_down.b==255)
	   {
	     coll= 1;
	   }
	 if(color_down.r==255 && color_down.g==0 && color_down.b==0)
	   {
	     coll= 2;
	   }
	printf("%d",coll);
	return coll;
}
int collisionParfaite_right(SDL_Surface *backgmasque,pos poss[])
{
	SDL_Color  color_d1,color_d2,color_d3  ;
	int coll= 0;
	color_d1 = GetPixel (backgmasque , poss[5]);
	color_d2 = GetPixel (backgmasque , poss[6]);
	color_d3 = GetPixel (backgmasque , poss[7]);
	 if((color_d1.r==255 && color_d1.g==255 && color_d1.b==255)&&(color_d2.r==255 && color_d2.g==255 && color_d2.b==255)&&(color_d3.r==255 && color_d3.g==255 && color_d3.b==255))
	   {
	     coll= 1;
	   }
	printf("%d",coll);
	return coll;
}
int collisionParfaite_left(SDL_Surface *backgmasque,pos poss[])
{
	SDL_Color  color_g1,color_g2,color_g3  ;
	int coll= 0;
	color_g1 = GetPixel (backgmasque , poss[2]);
	color_g2 = GetPixel (backgmasque , poss[3]);
	color_g3 = GetPixel (backgmasque , poss[4]);
	 if((color_g1.r==255 && color_g1.g==255 && color_g1.b==255)&&(color_g2.r==255 && color_g2.g==255 && color_g2.b==255)&&(color_g3.r==255 && color_g3.g==255 && color_g3.b==255))
	   {
	     coll= 1;
	   }
	printf("%d",coll);
	return coll;
}
void initialiser_minimap(minimap* map , SDL_Rect pos)
{
    map->minimape = IMG_Load("Map/mini_map.png");
    map->posminimap.x = 500;
    map->posminimap.y = 1;
    map->miniperso = IMG_Load("Map/mini_perso.png");
    map->posminiperso.x = pos.x * 15/100;
    map->posminiperso.y = pos.y * 10/100;
}    
void afficher_minimap(minimap m, SDL_Rect pos,SDL_Surface* screen){
 (pos).x=(pos).x * 15/100 + m.posminimap.x;
 (pos).y=(pos).y * 10/100 + m.posminimap.y;
 SDL_BlitSurface(m.minimape,NULL,screen,&m.posminimap);
 SDL_BlitSurface(m.miniperso,NULL,screen,&pos);
}
void initialiser_temps(temps *t)
{
	t->texte = NULL; //surface li bech nblitiwha (forme    mm:ss)
	t->position.x=10;
	t->position.y=50;
	t->police = NULL;
	t->police = TTF_OpenFont("text/spacerangeracad.ttf", 42);
	strcpy(t->entree,"");
	(t->secondesEcoulees)=0;
	time(&(t->t1)); //temps du debut
}

void afficher_temps(temps *t,SDL_Surface *ecran)
{	
	SDL_Color couleurBlanche= {255, 255, 255};
	time(&(t->t2));// temps actuel
	t->secondesEcoulees = t->t2 - t->t1;
	t->min=((t->secondesEcoulees/60)%60);
	t->sec= ((t->secondesEcoulees)%60);
	sprintf(t->entree,"-Time : %02d:%02d",t->min,t->sec);
	t->texte = TTF_RenderUTF8_Solid(t->police, t->entree, couleurBlanche);
	SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); /* Blit du texte */
	
}
void free_temps(temps *t,SDL_Surface *ecran)
{
	SDL_FreeSurface(t->texte);
	TTF_CloseFont(t->police);
}


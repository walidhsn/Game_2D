#ifndef COLLISION_DEF
#define COLLISION_DEF
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <time.h>
typedef struct{
 int x,y;
}pos;
typedef struct{
	SDL_Surface* minimape;
	SDL_Rect posminimap;
	SDL_Surface* miniperso;
	SDL_Rect posminiperso;
}minimap;
typedef struct temps
{
	SDL_Surface *texte;//image qui contient le temps
	SDL_Rect position;// position du clock
	TTF_Font *police ;
	char entree[100]; // chaine de caractere . forme "mm:ss"
	int secondesEcoulees; // variable entier qui contient le nbre de secondes ecoulés
	SDL_Color couleurBlanche;// couleur de texte a afficher
	time_t t1,t2; //t1 temps initiale ,,, t2 temps actuel
	int min, sec;// minutes et secondes
}temps;
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *ecran);
void free_temps(temps *t,SDL_Surface *ecran);

SDL_Color GetPixel (SDL_Surface* pSurface , pos tab);
int update_collision(pos poss[],SDL_Rect posperso);
int collisionParfaite_up(SDL_Surface *backgmasque ,pos poss[]);
int collisionParfaite_down(SDL_Surface *backgmasque ,pos poss[]);
int collisionParfaite_right(SDL_Surface *backgmasque ,pos poss[]);
int collisionParfaite_left(SDL_Surface *backgmasque ,pos poss[]);
void initialiser_minimap(minimap* map , SDL_Rect pos);
void afficher_minimap(minimap m, SDL_Rect pos,SDL_Surface* screen);
void affichertemps (int time , SDL_Surface *timer , SDL_Color noir, TTF_Font *police , SDL_Surface *screen);
#endif 

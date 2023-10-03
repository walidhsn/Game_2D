#ifndef ENNEMI_DEF
#define ENNEMI_DEF
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include "perso.h"
/** 
* @struct State 
* @brief struct for State_ennemi
*/
typedef enum STATE STATE;
enum STATE {WAITING,FOLLOWING,ATTACKING,HIT,DIE};
/** 
* @struct ennemi 
* @brief struct for Ennemi
*/ 

typedef struct
{
	SDL_Surface *image_e_d;
	SDL_Surface *image_e2_d;
	SDL_Surface *image_e_g;
	SDL_Surface *image_e2_g;
	SDL_Surface *death;
	SDL_Surface *death2;
	SDL_Rect pos_eni,pos_eni2;
	int die;
	int pas_d;
	int posxmin,posxmax,posymin2,posymax2;
	int direction;
	SDL_Rect annim_e1[9];
	SDL_Rect annim_e2[10];
	int frame,frame2;
	
}ennemi;
typedef struct
{
	SDL_Surface *image_boss_d;
	SDL_Surface *image_boss_g;
	SDL_Surface *arrow;
	SDL_Rect pos_arrow;
	SDL_Rect pos_boss;
	int pas_d,nb_hit;
	int direction_boss;
	SDL_Rect annim_boss_d[5][15];
	SDL_Rect annim_boss_g[5][15];
	int frame,frame1,frame2,frame3,frame4;
	STATE state;
}boss;

void initEnnemi(ennemi *e,ennemi *e2);
void initboss(boss *alien);
void afficherEnnemi(ennemi e,ennemi e2, SDL_Surface * screen);
void afficherboss(boss alien, SDL_Surface * screen);
void animerEnnemi(ennemi *e,ennemi *e2);
void animerboss(boss *alien);
void deplacer(ennemi *e,ennemi *e2);
int collisionBB(Personne p,ennemi e);
int collisionboss(Personne p,boss alien);
int collision_arrow(Personne p,boss alien);
int collisionBB2(Personne p,ennemi e);
void deplacerIA(boss *alien,Personne p);

#endif

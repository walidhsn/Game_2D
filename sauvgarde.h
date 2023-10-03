#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include "backg.h"
#include "collision.h"
#include "ennemi.h"
typedef struct 
{
Personne perso;
ennemi ennemi1[5];
ennemi ennemi2[5];
SDL_Rect pos_cam;
int p_nb_hit;
int score_p;
}save;

void update_save (save *s,Personne perso,ennemi e1[],ennemi e2[],SDL_Rect cam,int nb_hit_p,int sco);
void enregistrer (save s);
save recuperer();

#endif


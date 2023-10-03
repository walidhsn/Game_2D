#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include "backg.h"
#include "collision.h"
#include "ennemi.h"
typedef struct save
{
SDL_Rect pos_perso;
SDL_Rect posennemi1[5];
SDL_Rect posennemi2[5];
STATE alien_state;
SDL_Rect pos_cam;
int open_enigme1;
int open_enigme2;
int t_state;
int p_nb_hit;
temps t;
int score_p;
FILE *fichier;
}save;

void init_save (save *s);
void update_save (save *s, SDL_Rect perso,ennemi e1[],ennemi e2[],STATE alien_s,SDL_Rect cam,int nb_hit_p ,temps time,int sco,int o1,int o2,int t_s);
void enregistrer (save s);
save recuperer(save s);

#endif


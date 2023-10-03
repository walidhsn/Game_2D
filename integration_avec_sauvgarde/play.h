#ifndef PLAY_DEF
#define PLAY_DEF

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include "ennemi.h"
#include "enigme_integ.h"
#include "enigme_f_integ.h"
#include "sound.h"
#include "sauvgarde.h"
#include "perso.h"
int play_game(SDL_Surface *screen,int *v,int touche_state,int load_n);
int pause_game(SDL_Surface *screen_s,Personne p,ennemi e[],ennemi e2[],boss bo,int *v);
int game_over(SDL_Surface *screen_s,int *v);
int game_win(SDL_Surface *screen_s,int *v,int score,temps t);
#endif

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
void setrect(SDL_Rect* clip);
void credit_menu(SDL_Surface *screen_c,int etat);
void sous_option(SDL_Surface *screen_s,int *v,int *etat,int *touche_state);
void choix_touche_menu(SDL_Surface *screen_s,int *v,int *etat,int *touche_state);
void option_menu(SDL_Surface *screen_op,int *v,int *etat); 
void choix_jouer(SDL_Surface *screen_s,int *v,int *etat,int touche_state); 
void menu(int *touche_state);



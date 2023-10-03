#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>

typedef struct 
{
  Mix_Music *music_g;
  Mix_Chunk *jump,*long_jump,*lvl_up,*lvl_down,*health_down,*ennemi_hit,*perso_hit,*finish,*game_over,*boss_death;
}effect;
void init_sound(effect *sono);
void play_son(int num_s,effect sono);
void libirer_son(effect sono);

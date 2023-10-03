#include "sound.h"

void init_sound(effect *sono)
{
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1) 
	{
		printf("%s",Mix_GetError());
   	}
	sono->music_g= Mix_LoadMUS("son/game_music.mp3");
	sono->jump=Mix_LoadWAV("son/jump.wav");
	sono->long_jump=Mix_LoadWAV("son/long_jump.wav");
	sono->lvl_up=Mix_LoadWAV("son/lvl_up.wav");
	sono->lvl_down=Mix_LoadWAV("son/lvl_down.wav");
	sono->health_down=Mix_LoadWAV("son/health_down.wav");
	sono->ennemi_hit=Mix_LoadWAV("son/ennemi_hit.wav");
	sono->perso_hit=Mix_LoadWAV("son/person_hit.wav");
	sono->finish=Mix_LoadWAV("son/finish.wav");
	sono->game_over=Mix_LoadWAV("son/game_over.wav");
	sono->boss_death=Mix_LoadWAV("son/boss_death.wav");
}

void play_son(int num_s,effect sono)
{
	switch(num_s)
	{
		case 0:
			Mix_PlayMusic(sono.music_g,-1);
		break;
	
		case 1:
			Mix_PlayChannel(-1,sono.jump,0);
		break;
	
		case 2:
			Mix_PlayChannel(-1,sono.long_jump,0);
		break;
	
		case 3:
			Mix_PlayChannel(-1,sono.lvl_up,0);
		break;
	
		case 4:
			Mix_PlayChannel(-1,sono.lvl_down,0);
		break;
	
		case 5:
			Mix_PlayChannel(-1,sono.health_down,0);
		break;

		case 6:
			Mix_PlayChannel(-1,sono.ennemi_hit,0);
		break;
	
		case 7:
			Mix_PlayChannel(-1,sono.perso_hit,0);
		break;
	
		case 8:
			Mix_PlayChannel(-1,sono.finish,0);
		break;
	
		case 9:
			Mix_PlayChannel(-1,sono.game_over,0);
		break;

		case 10:
			Mix_PlayChannel(-1,sono.boss_death,0);
		break;
	}
}

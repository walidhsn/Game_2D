#include "enigme_f_integ.h"

int enigme_avec_f(int *v,SDL_Surface *ecran)
{
	SDL_Event event;
	Enigme e;
	int reponse=-1;
	genererEnigme(&e,"questions.txt",(*v));
	int Game;
	SDL_Init(SDL_INIT_VIDEO);
	if(ecran==NULL)
	{
	  printf("Unable to Set video mode :%s \n",SDL_GetError());
	  return 1;
	}
	SDL_EnableKeyRepeat(0,10);
	ecran = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	reponse=Play_Enigme(&e,ecran,&Game);
	return reponse;
}

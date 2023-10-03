
#include "intro.h"

void intro (SDL_Surface *ecran)
{
	SDL_Surface *logo=NULL, *coat=NULL,*menu=NULL;
	SDL_Rect poslogo;
	poslogo.x=0;
	poslogo.y=0;
	int i=0;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Event event;
	SDL_WM_SetIcon(IMG_Load("pic/icon.png"), NULL);
	SDL_WM_SetCaption("THE-001", NULL);
	logo=IMG_Load ("pic/intro/intro_logo.png");
	coat=IMG_Load ("pic/intro/intro_coat.png");
	menu=IMG_Load ("pic/intro/menu.png");
	ecran= SDL_SetVideoMode(1283, 733, 32, SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_RESIZABLE);
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

	
	while (i!=128)
	{
		SDL_SetAlpha (logo, SDL_SRCALPHA, i);
		SDL_BlitSurface(logo, NULL, ecran, &poslogo);
		SDL_Flip(ecran);
		i++;
		while (SDL_PollEvent(&event))
		switch(event.type)
		 {
		 	case SDL_KEYDOWN:
		 	switch (event.key.keysym.sym)
		 	{
		 		case SDLK_ESCAPE:
		 		i=128;
		 		break;
		 	}
		 }
	}
	
	i=0;
		while (i!=128)
	{
		SDL_SetAlpha (coat, SDL_SRCALPHA, i);
		SDL_BlitSurface(coat, NULL,ecran, &poslogo);
		SDL_Flip(ecran);
		i++;
		while (SDL_PollEvent(&event))
		switch(event.type)
		{
		 	case SDL_KEYDOWN:
		 	switch (event.key.keysym.sym)
		 	{
		 		case SDLK_ESCAPE:
		 		i=128;
		 		break;
		 	}
		 }
	}
		for(i=0;i<32;i++)
	{
		SDL_SetAlpha (menu, SDL_SRCALPHA, i);
		SDL_BlitSurface(menu, NULL, ecran, &poslogo);
		SDL_Flip(ecran);
	}
	SDL_FreeSurface(logo);
	SDL_FreeSurface(coat);
	SDL_FreeSurface(menu);
}

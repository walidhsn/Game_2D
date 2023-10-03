#include"menu.h"

#include"intro.h"

int main (void)
{

SDL_Surface *intro_ecran;
int touche=0;
intro(intro_ecran);
 menu(&touche);

 return 0;
}

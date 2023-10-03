#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "sauvgarde.h"


void update_save (save *s,Personne p,ennemi e1[],ennemi e2[],SDL_Rect cam,int nb_hit_p,int sco)
{
s->perso.pos.pos_Perso=p.pos.pos_Perso;
for(int i=0;i<5;i++)
{
	s->ennemi1[i].pos_eni=e1[i].pos_eni;
	s->ennemi2[i].pos_eni2=e2[i].pos_eni2;
}
s->pos_cam=cam;
s->p_nb_hit=nb_hit_p;
s->score_p=sco;
}
void enregistrer (save s)
{
FILE *f=NULL;
f=fopen("Save.bin","wb");
if (f!=NULL)
{
fwrite(&s,sizeof(save),1,f);
printf("Sauvegarde reussie ! \n");
fclose (f);
}else
printf("Impossible d'ouvrir le fichier !\n");
}
save recuperer()
{
FILE *f=NULL;
save s;
f=fopen("Save.bin","rb");
if (f!=NULL)
{
while(!feof(f))
{
fread(&s,sizeof(save),1,f);
}
printf("perso.x=%d, perso.y=%d\n", s.perso.pos.pos_Perso.x,s.perso.pos.pos_Perso.y);
fclose (f);
}
else printf("Impossible d'ouvrir le fichier !\n");
return s;
}


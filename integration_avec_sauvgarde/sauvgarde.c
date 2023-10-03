#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "sauvgarde.h"

void init_save (save *s)
{
s->pos_perso.x=-1;
s->pos_perso.y=-1;
for(int i=0;i<5;i++)
{
s->posennemi1[i].x=-1;
s->posennemi1[i].y=-1;
}
for(int i=0;i<5;i++)
{
s->posennemi2[i].x=-1;
s->posennemi2[i].y=-1;
}
s->open_enigme1=0;
s->open_enigme1=0;
s->alien_state=WAITING;
s->p_nb_hit=-1;
s->score_p=-1;
s->fichier=NULL;
}

void update_save (save *s, SDL_Rect perso,ennemi e1[],ennemi e2[],STATE alien_s,SDL_Rect cam,int nb_hit_p ,temps time,int sco,int o1,int o2,int t_s)
{
s->pos_perso=perso;
for(int i=0;i<5;i++)
{
	s->posennemi1[i]=e1[i].pos_eni;
	s->posennemi2[i]=e2[i].pos_eni2;
}
s->alien_state=alien_s;
s->pos_cam=cam;
s->p_nb_hit=nb_hit_p;
s->t=time;
s->score_p=sco;
s->open_enigme1=o1;
s->open_enigme1=o2;
s->t_state=t_s;
}

void enregistrer (save s)
{
s.fichier=fopen("Save.bin","wb");
if (s.fichier!=NULL)
{
fwrite(&s,sizeof(save),1,s.fichier);
printf("Sauvegarde reussie ! \n");
fclose (s.fichier);
}else
printf("Impossible d'ouvrir le fichier !\n");
}

save recuperer (save s)
{
s.fichier=fopen("Save.bin","rb");
if (s.fichier !=NULL)
{
fread(&s,sizeof(save),1,s.fichier);
printf("perso.x=%d, perso.y=%d\n", s.pos_perso.x, s.pos_perso.y);
fclose (s.fichier);
}
else printf("Impossible d'ouvrir le fichier !\n");
return s;
}


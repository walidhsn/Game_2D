//Déclaration des structures Personnage
#ifndef PERSO_DEF
#define PERSO_DEF
#include <stdio.h>
#include <stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
/** 
* @struct Score_Perso 
* @brief struct for scoreperso
*/ 

typedef struct
{
    int score_Perso;
    SDL_Rect pos_barreScore;
    SDL_Surface *barre_score;
}Score_Perso;
/** 
* @struct vie_perso
* @brief struct for vie perso
*/

typedef struct
{
    int vie_Perso;
    int nb_vies_Perso;
    SDL_Rect pos_viePerso;
    SDL_Surface *barre_vie;
}Vie_Perso;
/** 
* @struct Position perso
* @brief struct for position perso
*/
typedef struct
{
    SDL_Rect pos_Perso;
}Position_Perso;
/** 
* @struct Image_Perso 
* @brief struct for image perso
*/
typedef struct 
{
    SDL_Surface *img_PersoActuel;
    SDL_Surface *img_Perso[6][6];
    int direction;
    int num;	
}Image_Perso;
/** 
* @struct Personne
* @brief struct for Personne
*/
typedef struct
{
    Score_Perso score;
    Vie_Perso vie;
    Position_Perso pos;
    Image_Perso img;
    double vitesse,acceleration;
    int up;

}Personne;


//Entetes des fonctions
void init (Personne * p, int numperso);
void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface * screen_p);
void deplacerPerso (Personne *p,Uint32 dt,int posinit);
void animerPerso (Personne* p);
void saut (Personne* p,int dt,int posinit,int s_jump,int col);
#endif


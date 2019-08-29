#include "save.h"

void sauvegarderlevel(/*Gestion *jeu,GameObject *player,GameObject *monster[],*/char fich[20])
{
int i;

  FILE *f;
   
    f=fopen(fich, "wb");
   
        fwrite(&jeu,sizeof(Gestion),1, f);
        fwrite(&player,sizeof(GameObject),1, f);
  for (i=0; i<MONSTRES_MAX; i++)
	{
 fwrite(&monster[i],sizeof(GameObject),1, f);
    }
    fclose(f);
}

void load_game (/*Background *back, Perso *perso,*/ char fich[20]/*, int level*/)
{
	int i;
	FILE *f=fopen(fich,"rb");

	if(f==NULL)
	{
	     printf("Erreur !");
	}

	else
	{
		fread(&jeu,1, sizeof(Gestion),f);
		fread(&player,1, sizeof(GameObject), f);
	}


	//back->img = IMG_Load ("backgrounds/map2.png");
	//back->mask = IMG_Load ("backgrounds/map2Collision.png");

	//load_images (perso, "perso/main/");

	fclose(f);
}

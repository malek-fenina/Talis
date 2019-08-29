#include "draw.h"

   void drawImage(SDL_Surface *image, int x, int y)
  {
       SDL_Rect dest;

       /* Règle le rectangle à blitter selon la taille de l'image source */

       dest.x = x;
       dest.y = y;
       dest.w = image->w;
       dest.h = image->h;

       /* Blitte l'image entière sur l'écran aux coordonnées x et y */

       SDL_BlitSurface(image, &camera.cam , jeu.screen, &dest);
   }
   
   void drawIm(SDL_Surface *image, int x, int y)
  {
       SDL_Rect dest;

       /* Règle le rectangle à blitter selon la taille de l'image source */

      dest.x = x - camera.cam.x;
      dest.y = y - camera.cam.y;
       dest.w = image->w;
       dest.h = image->h;

       /* Blitte l'image entière sur l'écran aux coordonnées x et y */

       SDL_BlitSurface(image, NULL , jeu.screen, &dest);
   }
   
  void set_camera()
{
    //Centre la camera sur le point
    camera.cam.x = ( player.x + PLAYER_WIDTH / 2 ) - SCREEN_WIDTH / 2;
    camera.cam.y = ( player.y + 80 / 2 ) - SCREEN_HEIGHT / 2;
    
    //Garde la camera sur les bords
    if( camera.cam.x < 0 )
    {
        camera.cam.x = 0;
    }
    if( camera.cam.y < 0 )
    {
        camera.cam.y = 0;
    }
    if( camera.cam.x > LEVEL_WIDTH - camera.cam.w )
    {
        camera.cam.x = LEVEL_WIDTH - camera.cam.w;
    }
    if( camera.cam.y > LEVEL_HEIGHT - camera.cam.h )
    {
        camera.cam.y = LEVEL_HEIGHT - camera.cam.h;
    }
}

  void draw()
  {
     //Met la camera en place
     set_camera();
     
     /* Affiche le fond (background) aux coordonnées (0,0) */
    drawImage(map.background, 0, 0);
    
    //drawplayer();

    /* Affiche le joueur */
    drawAnimatedEntity(&player);
    int i;
    /* Affiche les monstres */
    for(i = 0 ; i < jeu.nombreMonstres ; i++)
    {
        drawAnimatedEntity(&monster[i]);
    }
    
    //On affiche le HUD par-dessus tout le reste
    drawHud();
    
    /* Affiche l'écran */
    SDL_Flip(jeu.screen);

    /* Delai */
    SDL_Delay(1);

  }

   SDL_Surface *loadImage(char *name)
   {
       /* Charge une image temporaire avec SDL Image */

       SDL_Surface *temp = IMG_Load(name);
       SDL_Surface *image;

       /* Si elle n'est pas chargée on quitte avec une erreur */
      if (temp == NULL)
      {
           printf("Failed to load image %s\n", name);

          return NULL;
       }

       /* Ajoute la transparence à l'image temporaire en accord avec les defines TRANS_R, G, B */

       SDL_SetColorKey(temp, (SDL_SRCCOLORKEY | SDL_RLEACCEL), SDL_MapRGB(temp->format,
                                                   TRANS_R, TRANS_G,    TRANS_B));


       /* Convertit l'image au format de l'écran (screen) pour un blit plus rapide */

       image = SDL_DisplayFormat(temp);
       
       /* Libère l'image temporaire */
       SDL_FreeSurface(temp);

       if (image == NULL)
       {
           printf("Failed to convert image %s to native format\n", name);

           return NULL;
       }

       /* Retourne l'image au format de l'écran pour accélérer son blit */

       return image;


   }
   
     void drawHud(void)
{
    //On crée une varuiable qui contiendra notre texte (jusqu'à 200 caractères, y'a de la marge ;) ).
    char text[200];

	int i;
	for(i=0; i < jeu.sang; i++)
	{
		drawIm(jeu.HUD_sang, player.x + (i * 10), player.y - 10);
	}
    /* Affiche le nombre de vies en bas à droite */
    drawIm(jeu.HUD_vie, camera.cam.x + 10, camera.cam.y + 10);
      
    //Pour afficher le nombre de vies, on formate notre string pour qu'il prenne la valeur de la variable
    sprintf(text, "%d", jeu.vies);
    //Puis on utilise notre fonction créée précédemment
    drawString(text, 90, 20, font);

}



  void delay(unsigned int frameLimit)
  {

    /* Gestion des 60 fps (images/stories/seconde) */

    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
  }

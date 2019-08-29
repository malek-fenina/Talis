 #include "init.h"

   /* Fonction qui initialise le jeu */

   void init(char *title)
   {
  
    /* Initialise SDL Video. Si la valeur de retour est inférieure à zéro, la SDL n'a pas pu
     s'initialiser et on quite */

    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }


     /* On crée la fenêtre, représentée par le pointeur jeu.screen en utilisant la largeur et la
     hauteur définies dans les defines (defs.h). On utilise aussi la mémoire vidéo
     (SDL_HWPALETTE) et le double buffer pour éviter que ça scintille
     (SDL_DOUBLEBUF) */
     
    jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWPALETTE|SDL_DOUBLEBUF);

     /* Si on y arrive pas, on quitte */

    if (jeu.screen == NULL)
        {
            printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
            exit(1);
        }


    /* On entre le titre de la fenêtre */

    SDL_WM_SetCaption(title, NULL);


    /* On cache le curseur de la souris */

    SDL_ShowCursor(SDL_DISABLE);
    SDL_EnableKeyRepeat(200, 10);
    
      /* Initialise SDL_TTF */

    if (TTF_Init() < 0)
    {
        printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());

        exit(1);
    }

    /* Charge la police en 32 points (taille) */

    font = loadFont("graphics/Fonts/Trajan Pro Regular.ttf", 32);
    
    }


     void loadGame(void)
    {

        /* Charge l'image du fond */
        map.background = loadImage("graphics/background.png");
        
        /* On initialise les variables du jeu */
    if(jeu.vies !=2 && jeu.vies !=1)
    jeu.vies = 3;
    
    if(jeu.sang !=3 && jeu.sang !=2 && jeu.sang !=1)
    jeu.sang = 4;

    /* On charge le HUD */
    jeu.HUD_vie = loadImage("graphics/life.png");
    
    jeu.HUD_sang = loadImage("graphics/heart.png");
    

     }
     
     
   
   void initializeCamera(void)
   {       
       camera.cam.x = 0;
       camera.cam.y = 0;
       
       camera.cam.w = SCREEN_WIDTH;
       camera.cam.h = SCREEN_HEIGHT;
   }



   /* Fonction qui quitte le jeu proprement */

    void cleanup()
   {

     /* Libère l'image du background */

      if (map.background != NULL)
      {
            SDL_FreeSurface(map.background);
      }
      
      //Libère le HUD
    if (jeu.HUD_vie != NULL)
    {
        SDL_FreeSurface(jeu.HUD_vie);
    }
      
       /* Close the font */

    closeFont(font);


    /* Close SDL_TTF */

    TTF_Quit();


      /* Quitte la SDL */
      SDL_Quit();

    }


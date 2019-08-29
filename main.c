
    #include "main.h"

    int main( int argc, char *argv[ ] )
   {
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int go = 1;

    /* Initialisation de la SDL dans une fonction séparée (voir après) */
        init("TALIS");
        
        initializeCamera();
        
        /* On initialise le sol */
        initializeGround();

    /* On initialise le joueur */
     initializePlayer();
     
     /*On place les monstres*/
     drawMonsters();
     
     

     /* Chargement des ressources (graphismes, sons) */
          loadGame();


   /* Appelle la fonction cleanup à la fin du programme */
         atexit(cleanup);
         
         
    gamestate = IN_MENU;

    
    /* Boucle infinie, principale, du jeu */

    while (go == 1)
    {
	while(gamestate == IN_MENU)
        {
        	menuLoop();
        }
        
        while(gamestate == IN_GAME)
        {
        /* On vérifie l'état des entrées (clavier puis plus tard joystick */
        getInput();

        /* On met à jour le jeu */
        updatePlayer();
        updateMonsters();
	
	/* On affiche tout */
        draw();

        /* Gestion des 60 fps ( 60 images pas seconde : soit 1s ->1000ms/60 = 16.6 -> 16
        On doit donc attendre 16 ms entre chaque image (frame) */
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
        }
        
        while(gamestate == EXIT)
        {
		quit();
		//go = 0;
	}
    }

    /* Exit */
    exit(0);

    }

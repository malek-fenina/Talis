  #include "defs.h"

  /* Structures qui seront utilisées pour gérer le jeu */

  /* Structure pour gérer l'input (clavier puis joystick) */

   typedef struct Input
  {

    int left, right, up, down, jump, attack, enter, erase, pause;

  } Input;


  /* Structure pour gérer le niveau (à compléter plus tard) */

  typedef struct Gestion
  {

    SDL_Surface *screen;
    int fullscreen;
    //int gamestate;
    int nombreMonstres;
    
    //HUD
    SDL_Surface *HUD_vie;
    SDL_Surface *HUD_sang;
    int vies;
    int sang;

  } Gestion;


  /* Structure pour gérer la map à afficher (à compléter plus tard) */

  typedef struct Map
  {

      SDL_Surface *background;

  } Map;
  
  typedef struct Camera
   {
   	SDL_Rect cam;
    }Camera;
  
     /* Structure pour gérer notre héros */

   typedef struct GameObject
   {
       //Sprite du héros (pas d'animation pour l'instant)
       SDL_Surface *sprite;

       /* Coordonnées du héros */
       int x, y;
       
        /* Largeur, hauteur du sprite */
    int h, w;
       
       /* Variables utiles pour l'animation */
    int frameNumber, frameTimer;
    int etat, direction;
    
     /* Variables utiles pour la gestion des collisions */
    int onGround, timerMort;
    float dirX, dirY;


   } GameObject;
   
   typedef struct Ground
   {
   	SDL_Surface *sol;
        int x, y;
        int h, w;
        
   }Ground;
   
   typedef struct menuElement
   {
   	SDL_Surface* surfaceNormal;
	SDL_Surface* surfaceHover;
   }menuElement;
   
   typedef struct Menu
   {
   	//La surface de texte
   	menuElement element[10][10];
   	
   	//Les surfaces d'images
   	SDL_Surface* totem;
	SDL_Surface* background;
	
   	//Permet de savoir qu'elle lien a le focus
	int m_currentIndex;
	
	//Permet de savoir sur quelle pas on est
	int m_currentPage;
	
	int m;
 
	//Permet de savoir si un lien est sélectionné ou non
	int m_select;
 
	//Position du menu à l'image
	int m_posX;
	int m_posY;
 
	//Style du texte [taille + chemin vers la police]
	int m_fontSize;
	char *m_fontPath;
 
	//Couleur du texte
	SDL_Color m_colorHover;
	SDL_Color m_colorNormal;
   }Menu;
   

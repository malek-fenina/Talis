  #include "structs.h"

 /* Structures globales */
  extern Menu menu;
  extern menuElement Element;
  extern Input input;
  extern int gamestate;
  extern GameObject player;
  extern Camera camera;
  extern Gestion jeu;
  
  
  extern void drawImage(SDL_Surface *image, int x, int y);
  extern void drawIm(SDL_Surface *image, int x, int y);
  extern SDL_Surface* surfacePolice(char *name, int size, char *text, SDL_Color couleur);
  extern void getInput(void);
  SDL_Surface *loadImage(char *name);
  extern void drawMonsters(void);
  extern void loadGame(void);
  extern void initializePlayer(void);
  extern void sauvegarderlevel(char fich[20]);
  extern void load_game (/*Background *back, Perso *perso,*/ char fich[20]/*, int level*/);

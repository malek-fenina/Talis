
  #include "structs.h"

  /* Prototypes des fonctions utilisées */

  extern void init(char *);
  extern void cleanup(void);
  extern void getInput(void);
  extern void draw();
  extern SDL_Rect initializeCamera(void);
  extern void set_camera();
  extern void menuLoop(void);
  extern void loadGame(void);
  extern void delay(unsigned int frameLimit);
  extern void updatePlayer(void);
  extern void initializePlayer(void);
  extern void initializeGround(void);
  extern void drawMonsters(void);
  extern void updateMonsters(void);
  extern void quit(void);


  /* Déclaration des structures globales utilisées par le jeu */

  Input input;
  Gestion jeu;

  Map map;
  GameObject player;
  GameObject monster[MONSTRES_MAX];
  int gamestate;
  
  Ground wall;
  Menu menu;
  menuElement Element;
  Camera camera;
  
  /* Déclaration de notre police de caractères */
   TTF_Font *font;

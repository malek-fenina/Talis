  #include "structs.h"

 /* Prototypes des fonctions utilisées */
  extern void drawAnimatedEntity(GameObject *entity);
  extern void drawplayer();
  extern void drawHud(void);
  extern void drawString(char *text, int x, int y, TTF_Font *font);
  
 
 /* Structures globales */ 
  extern Gestion jeu;
  extern Map map;
  extern Input input;
  extern GameObject player;
  extern GameObject monster[];
  extern Camera camera;
  extern TTF_Font *font;

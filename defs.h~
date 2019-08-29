  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <math.h>
  #include <SDL/SDL.h>
  #include <SDL/SDL_image.h>
  #include <SDL/SDL_ttf.h>

 /* Taille de la fenêtre / résolution en plein écran */
  #define SCREEN_WIDTH 1200
  #define SCREEN_HEIGHT 750
  
  //Les dimensions du niveau
  #define LEVEL_WIDTH 10500
  #define LEVEL_HEIGHT 750

 /* Valeur RGB pour la transparence (canal alpha) */
 #define TRANS_R 255
 #define TRANS_G 0
 #define TRANS_B 255
 
   /* Taille du sprite de notre héros (largeur = width et hauteur = heigth) */
   #define PLAYER_WIDTH 40
   #define PLAYER_HEIGTH 80

   /* Constantes pour l'animation */
   #define TIME_BETWEEN_2_FRAMES 8
   
   //Vitesse de déplacement en pixels du sprite
   #define PLAYER_SPEED 8
  
  //Valeurs attribuées aux états/directions
   #define WALK_RIGHT 1
   #define WALK_LEFT 2
   #define IDLE 3
   #define JUMP_RIGHT 4
   #define JUMP_LEFT 5
   #define FOLLOWING 6
   #define RIGHT 1
   #define LEFT 2
   
   //Constantes définissant la gravité et la vitesse max de chute
   #define GRAVITY_SPEED 0.6
   #define MAX_FALL_SPEED 10
   #define JUMP_HEIGHT 13
   
    //Nombre max de monstres à l'écran
   #define MONSTRES_MAX 10
   #define MONSTER_SIZE 32
   
   #define IN_MENU 1
   #define IN_GAME 2
   #define EXIT 3
   
   

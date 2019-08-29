   #include "map.h" 
   
   void initializeGround(void)
   {
      wall.x = 0;
      wall.y = 700;
       
      wall.w = LEVEL_WIDTH;
      wall.h = 100;
   }
  
  
int check_collision( GameObject *A, Ground B )
{
    //Les cotes des rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
 
    //Calcul les cotes du rectangle A
    leftA = A->x;
    rightA = A->x + A->w;
    topA = A->y;
    bottomA = A->y + A->h;
 
    //Calcul les cotes du rectangle B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;
        //Tests de collision
    if( bottomA <= topB )
    {
        return 0;
    }
 
    if( topA >= bottomB )
    {
        return 0;
    }
 
    if( rightA <= leftB )
    {
        return 0;
    }
 
    if( leftA >= rightB )
    {
        return 0;
    }
 
    //Si conditions collision detectee
    return 1;
}

  void mapCollision(GameObject *entity, Ground wall)
 {

    int i=7, x1, x2, y1, y2;

    /* D'abord, on place le joueur en l'air jusqu'à temps d'être sûr qu'il touche le sol */

    entity->onGround = 0;
    
    //On lance alors une boucle for infinie car on l'interrompra le comteur i aura tester toute la hauteur du sprite

    for (;;)
    {
        //On va calculer ici les coins de notre sprite à gauche et à droite pour voir quelle tile ils
        //touchent.

        x1 = (entity->x + entity->dirX); // TILE_SIZE;
        x2 = (entity->x + entity->dirX + entity->w - 1); // TILE_SIZE;

        //Même chose avec y, sauf qu'on va monter au fur et à mesure pour tester toute la hauteur
        //de notre sprite, grâce à notre fameuse variable i.

        y1 = (entity->y); // TILE_SIZE;
        y2 = (entity->y + i - 1); // TILE_SIZE;

        //De là, on va tester les mouvements initiés dans updatePlayer grâce aux vecteurs
        //dirX et dirY, tout en testant avant qu'on se situe bien dans les limites de l'écran.

        if (x1 >= 0 && x2 < LEVEL_WIDTH && y1 >= 0 && y2 < LEVEL_HEIGHT)
        {
            //Si on a un mouvement à droite

            if (entity->dirX > 0)
            {

                //On vérifie si les tiles recouvertes sont solides

                if (check_collision( entity, wall ) == 1)
                {
                    // Si c'est le cas, on place le joueur aussi près que possible
                    // de ces tiles, en mettant à jour ses coordonnées. Enfin, on réinitialise
                    //son vecteur déplacement (dirX).

                    entity->x = x2;// * TILE_SIZE;

                    entity->x -= entity->w + 1;

                    entity->dirX = 0;

                }

            }

            //Même chose à gauche

            else if (entity->dirX < 0)
            {

                if (check_collision( entity, wall ) == 1)
                {

                    entity->x = (x1 + 1);// * TILE_SIZE;

                    entity->dirX = 0;
                }


            }

        }

        //On sort de la boucle si on a testé toutes les tiles le long de la hauteur du sprite.
        if (i == entity->h)
        {
            break;
        }

        //Sinon, on teste les tiles supérieures en se limitant à la heuteur du sprite.
        i += 1;

        if (i > entity->h)
        {
            i = entity->h;
        }
    }




    for (;;)
    {
        x1 = (entity->x);// / TILE_SIZE;
        x2 = (entity->x + i);// / TILE_SIZE;

        y1 = (entity->y + entity->dirY);// / TILE_SIZE;
        y2 = (entity->y + entity->dirY + entity->h);// / TILE_SIZE;

        if (x1 >= 0 && x2 < LEVEL_WIDTH && y1 >= 0 && y2 < LEVEL_HEIGHT)
        {
            if (entity->dirY > 0)
            {

                 //Déplacement en bas 
                if (check_collision( entity, wall ) == 1)
                {
                    //Si la tile est solide, on y colle le joueur et
                    //on le déclare sur le sol (onGround).
                    //entity->y = y1;// * TILE_SIZE;
                    entity->y -= entity->dirY;

                    //entity->dirY = 0;

                    entity->onGround = 1;
                }

            }

            else if (entity->dirY < 0)
            {

                //Déplacement vers le haut

                if (check_collision( entity, wall ) == 1)
                {

                    entity->y = (y1 + 1);// * TILE_SIZE;

                   // entity->dirY = 0;

                }

            }
        }

        //On teste la largeur du sprite (même technique que pour la hauteur précédemment)
        if (i == entity->w)
        {
            break;
        }

        i += 1;

        if (i > entity->w)
        {
            i = entity->w;
        }
    }

    /* Maintenant, on applique les vecteurs de mouvement si le sprite n'est pas bloqué */
    entity->x += entity->dirX;
    entity->y += entity->dirY;

    //Et on contraint son déplacement aux limites de l'écran, comme avant.
    if (entity->x < 0)
    {
        entity->x = 0;
    }

    else if (entity->x + entity->w >= LEVEL_WIDTH)
    {
        entity->x = LEVEL_WIDTH - entity->w - 1;
    }

    //Maintenant, s'il sort de l'écran par le bas (chute dans un trou sans fond), on lance le timer
    //qui gère sa mort et sa réinitialisation (plus tard on gèrera aussi les vies).
    if (entity->y > SCREEN_HEIGHT)
    {
        entity->timerMort = 60;
    }
}

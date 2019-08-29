#include "monster.h" //A ne pas oublier en tête de fichier

   void initializeMonster(int x, int y)
{
    //Si on n'est pas rendu au max, on rajoute un monstre dont le numéro est égal
    //à nombreMonstres : monster[0] si c'est le 1er, monster[1], si c'est le 2eme, etc...
    if (jeu.nombreMonstres < MONSTRES_MAX )
    {
        /* On charge son sprite */
        monster[jeu.nombreMonstres].sprite = loadImage("graphics/monster1.png");

        //On indique sa direction (il viendra à l'inverse du joueur, logique)
        monster[jeu.nombreMonstres].direction = LEFT;
        monster[jeu.nombreMonstres].etat = IDLE;

        //On réinitialise le timer de l'animation et la frame comme pour le joueur
        monster[jeu.nombreMonstres].frameNumber = 0;
        monster[jeu.nombreMonstres].frameTimer = TIME_BETWEEN_2_FRAMES;

        /* Ses coordonnées de démarrage seront envoyées par la fonction drawMap() en arguments */
        monster[jeu.nombreMonstres].x = x;
        monster[jeu.nombreMonstres].y = y;

        /* Hauteur et largeur de notre monstre (une tile ici, soit 32x32) */
        monster[jeu.nombreMonstres].w = MONSTER_SIZE;
        monster[jeu.nombreMonstres].h = MONSTER_SIZE;

        //Variables nécessaires au fonctionnement de la gestion des collisions comme pour le héros
        monster[jeu.nombreMonstres].timerMort = 0;
        monster[jeu.nombreMonstres].onGround = 0;
       
        jeu.nombreMonstres++;      
    }
}

void drawMonsters()
{
	int x;
	
	for(x = 0; x < LEVEL_WIDTH; x++)
	{
		if(x % 1500 == 0 && x != 0)
		{
			initializeMonster(x, 669);
		}
	}	
}

  void updateMonsters(void)
{

    int i,j;

    //On passe en boucle tous les monstres du tableau
    for ( i = 0; i < jeu.nombreMonstres; i++ )
    {
        //Même fonctionnement que pour le joueur
        if (monster[i].timerMort == 0)
        {

            monster[i].dirX = 0;
            monster[i].dirY += GRAVITY_SPEED;


            if (monster[i].dirY >= MAX_FALL_SPEED)
                monster[i].dirY = MAX_FALL_SPEED;
	    
            //Le monstre suit le joueur
            inputEnnemi(&player, &monster[i],400);
            MoveEnnemi (&monster[i]);

            //On détecte les collisions avec la map comme pour le joueur
            mapCollision(&monster[i], wall);
            
             //On détecte les collisions avec le joueur
            //Si c'est égal à 1, on tue le joueur... Sniff...
            if (collide(&player, &monster[i]) == 1)
            {
                if(player.x < monster[i].x) 
		{
			for(j=0;j<100;j++)
                	{
                		player.x -= 1;
               		}
		}
		
		else 
		{
			for(j=0;j<100;j++)
               		{
                		player.x += 1;
                	}
		}
                
                //On met le timer à 1 pour tuer le joueur intantanément
                //player.timerMort = 1;
                gameOver();
            }
            else if (collide(&player, &monster[i]) == 2)
            {
                //On met le timer à 1 pour tuer le monstre intantanément
                monster[i].timerMort = 1;
            }

          }

        //Si le monstre meurt, on active une tempo
        if (monster[i].timerMort > 0)
        {
            monster[i].timerMort--;

            /* Et on le remplace simplement par le dernier du tableau puis on
            rétrécit le tableau d'une case (on ne peut pas laisser de case vide) */
            if (monster[i].timerMort == 0)
            {
                monster[i] = monster[jeu.nombreMonstres-1];
                jeu.nombreMonstres--;
            }
        }

    }
}

   //Fonction de gestion des collisions
   int collide(GameObject *player, GameObject *monster)
 {
    //On teste pour voir s'il n'y a pas collision, si c'est le cas, on renvoie 0
    if ((player->x >= monster->x + monster->w)
    || (player->x + player->w <= monster->x)
    || (player->y >= monster->y + monster->h)
    || (player->y + player->h <= monster->y)
    )
        return 0;
    //Sinon, il y a collision. Si le joueur est au-dessus du monstre (avec une marge
    //de 10 pixels pour éviter les frustrations dues au pixel perfect), on renvoie 2.
    //On devra alors tuer le monstre et on fera rebondir le joueur.
    else if (player->y + player->h <= monster->y + 10)
    {
        player->dirY = -JUMP_HEIGHT;
        return 2;
    }
    //Sinon, on renvoie 1 et c'est le joueur qui meurt...
    else
        return 1;
}

void inputEnnemi(GameObject *player, GameObject *monster,int d1)
{
	int dist = abs(monster->x - player->x);
	
	if((monster->etat == IDLE) && (dist<d1) )
	{
		monster->etat = FOLLOWING;
	}
	else if ((monster->etat == FOLLOWING) && (dist>d1))
	{
		monster->etat = IDLE;
	}
}

void MoveEnnemi (GameObject *monster)
{
	if(monster->etat == FOLLOWING)
	{
		if(player.x < monster->x) 
		{
			monster->x -= 2;
			monster->sprite = loadImage("graphics/monster1.png");
		}
		
		else 
		{
			monster->x += 2;
			monster->sprite = loadImage("graphics/monster1right.png");
		}
	}
}

void gameOver()
{
	jeu.sang --;
	if(jeu.sang == 0)
	{
		jeu.vies --;
		player.timerMort = 1;
	}
	if(jeu.vies == 0);
	{
		SDL_Surface *gameover;
		gameover = loadImage("graphics/GameOver.png");
		drawIm(gameover, camera.cam.x, camera.cam.y);
	}
	
}

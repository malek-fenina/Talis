#include "menu.h"

void setFontStyle(char *font, const int size) 
{
	menu.m_fontSize = size;
	menu.m_fontPath = font;
}
 
void setColor(SDL_Color colorNormal, SDL_Color colorHover) 
{
	menu.m_colorNormal = colorNormal;
	menu.m_colorHover = colorHover;
}
 
void setPosition(int X, int Y) 
{
	menu.m_posX = X;
	menu.m_posY = Y;
}

int getCurrentIndex() 
{
	return menu.m_currentIndex;
}
 
int getMenuSize() 
{
	return 4;
}
 
int getIsSelect() 
{
	return menu.m_select;
}

void OnRender(int x, int y) 
{
 
	//Gère la position où les liens seront collés [un en dessous de l'autre]
	int rowY, i, j;
	 
	//Pour tous les "liens" du menu
		for(i = 0; i < x; i++) 
		{
	 
			rowY = menu.m_posY + i * (menu.element[y][i].surfaceHover->h + 10);
		 	
			//Condition pour savoir quel lien possède le focus
			if(menu.m_currentIndex == i) 
			{
 	
				//Affiche la surfaceHover
				drawIm(menu.element[y][i].surfaceHover, menu.m_posX + 20, rowY);
			}
			else 
			{
				 
				//Affiche la surfaceNormal
				drawIm(menu.element[y][i].surfaceNormal, menu.m_posX, rowY);
			}
		}
}

void addRow(char *text, int x, int y) 
{
	//Créé un nouveau lien "m_el", le nom de la variable n'est pas important
	//Element m_el;
 
	//Génére la surfaceHover
	Element.surfaceHover = surfacePolice(menu.m_fontPath, menu.m_fontSize, text, menu.m_colorHover);
 
	//Génére la surfaceNormal
	Element.surfaceNormal = surfacePolice(menu.m_fontPath, menu.m_fontSize, text, menu.m_colorNormal);
 
	//Ajout le nouveau lien dans le menu
	menu.element[y][x] = Element;
 
	//Défini le currentIndex à 0
	//menu.m_currentIndex = 0;
}

void moveUp()
{
	switch(menu.m_currentPage)
	{
	case 0:
		switch(menu.m_currentIndex)
		{
		case 0:	
			menu.m_currentIndex = 3;
			break;
		case 1:
			menu.m_currentIndex = 0;
			break;
		case 2:
			menu.m_currentIndex = 1;
			break;
		case 3:
			menu.m_currentIndex = 2;
			break;
		}
		break;
	case 1:
		switch(menu.m_currentIndex)
		{
		case 0:	
			menu.m_currentIndex = 5;
			menu.totem = loadImage("graphics/Totem/5.png");
			break;
		case 1:
			menu.m_currentIndex = 0;
			menu.totem = loadImage("graphics/Totem/0.png");
			break;
		case 2:
			menu.m_currentIndex = 1;
			menu.totem = loadImage("graphics/Totem/1.png");
			break;
		case 3:
			menu.m_currentIndex = 2;
			menu.totem = loadImage("graphics/Totem/2.png");
			break;
		case 4:
			menu.m_currentIndex = 3;
			menu.totem = loadImage("graphics/Totem/3.png");
			break;
		case 5:
			menu.m_currentIndex = 4;
			menu.totem = loadImage("graphics/Totem/4.png");
			
		}
		break;
	case 2:
		switch(menu.m_currentIndex)
		{
		case 0:	
			menu.m_currentIndex = 2;
			break;
		case 1:
			menu.m_currentIndex = 0;
			break;
		case 2:
			menu.m_currentIndex = 1;
			break;
		}
		break;
	case 3:
		switch(menu.m_currentIndex)
		{
		case 0:	
			menu.m_currentIndex = 4;
			break;
		case 1:
			menu.m_currentIndex = 0;
			break;
		case 2:
			menu.m_currentIndex = 1;
			break;
		case 3:
			menu.m_currentIndex = 2;
			break;
		case 4:
			menu.m_currentIndex = 3;
			break;
		}
		break;
	}
}

void moveDown()
{
	switch(menu.m_currentPage)
	{
	case 0:
		switch(menu.m_currentIndex)
		{
		case 0:	
			menu.m_currentIndex = 1;
			break;
		case 1:
			menu.m_currentIndex = 2;
			break;
		case 2:
			menu.m_currentIndex = 3;
			break;
		case 3:
			menu.m_currentIndex = 0;
			break;
		}
		break;
	case 1:
		switch(menu.m_currentIndex)
		{
		case 0:	
			menu.m_currentIndex = 1;
			menu.totem = loadImage("graphics/Totem/1.png");
			break;
		case 1:
			menu.m_currentIndex = 2;
			menu.totem = loadImage("graphics/Totem/2.png");
			break;
		case 2:
			menu.m_currentIndex = 3;
			menu.totem = loadImage("graphics/Totem/3.png");
			break;
		case 3:
			menu.m_currentIndex = 4;
			menu.totem = loadImage("graphics/Totem/4.png");
			break;
		case 4:
			menu.m_currentIndex = 5;
			menu.totem = loadImage("graphics/Totem/5.png");
			break;
		case 5:
			menu.m_currentIndex = 0;
			menu.totem = loadImage("graphics/Totem/0.png");
			break;
		}
		break;
	case 2:
		switch(menu.m_currentIndex)
		{
		case 0:	
			menu.m_currentIndex = 1;
			break;
		case 1:
			menu.m_currentIndex = 2;
			break;
		case 2:
			menu.m_currentIndex = 0;
			break;
		}
		break;
	case 3:
		switch(menu.m_currentIndex)
		{
		case 0:	
			menu.m_currentIndex = 1;
			break;
		case 1:
			menu.m_currentIndex = 2;
			break;
		case 2:
			menu.m_currentIndex = 3;
			break;
		case 3:
			menu.m_currentIndex = 4;
			break;
		case 4:
			menu.m_currentIndex = 0;
			break;
		}
		break;
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
void newGame()
{
	
	menu.m_currentPage = 1;
	
	menu.totem = loadImage("graphics/Totem/0.png");
	
	
	
	while (menu.m_currentPage == 1 && gamestate == IN_MENU)
	{
	//Défini la position du menu à l'image
	setPosition(camera.cam.x + 800,camera.cam.y + 650);
	
	//Gestion d'événement
	 
	 SDL_Event event;
	
	

    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

            case SDL_QUIT:
                gamestate = EXIT;
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        gamestate = EXIT;
                    break;

                    case SDLK_DOWN:
                        moveDown();
                    break;

                    case SDLK_UP:
                        moveUp();
                    break;

                    case SDLK_RETURN:                        
                        switch(getCurrentIndex()) 
			{
			case 0:
				menu.m_currentPage = 0;
				break;
			case 1:
				initializePlayer();
    			        drawMonsters();
        		        loadGame();
				gamestate = IN_GAME;
				break;
			case 2:
				//LEVEL 2
				break;
			case 3:
				//LEVEL 3
				break;
			case 4:
				//LEVEL 4
				break;
			case 5:
				//LEVEL 5
				break;
			}
                    	break;

                    default:
                    break;
                }
            break;

        }

    }
	
	//......
	//Rendu
	//Efface l'écran
	drawIm(menu.background, camera.cam.x, camera.cam.y);
	drawIm(menu.totem, camera.cam.x, camera.cam.y);
	OnRender(1,1);
 
	//Mise à jour de l'écran
	SDL_Flip(SDL_GetVideoSurface());
	
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
void quit()
{
	
	menu.m_currentPage = 2;
	menu.m_currentIndex = 0;
	
	while (menu.m_currentPage == 2 && gamestate == EXIT)
	{
	//Défini la position du menu à l'image
	setPosition(camera.cam.x + 400, camera.cam.y + 300);
	
	//Gestion d'événement
	 
	 SDL_Event event;
	
	

    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

            case SDL_QUIT:
                gamestate = EXIT;
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        gamestate = EXIT;
                    break;

                    case SDLK_DOWN:
                        moveDown();
                    break;

                    case SDLK_UP:
                        moveUp();
                    break;

                    case SDLK_RETURN:                        
                        switch(getCurrentIndex()) 
			{
			case 0:
				gamestate = IN_GAME;
				break;
			case 1:
				sauvegarderlevel("save.txt");
				exit(0);
				break;
			case 2:
				exit(0);
				break;
			}
                    	break;

                    default:
                    break;
                }
            break;

        }

    }
	
	//......
	//Rendu
	//Efface l'écran
	drawIm(menu.background, camera.cam.x, camera.cam.y);
	OnRender(3,2);
 
	//Mise à jour de l'écran
	SDL_Flip(SDL_GetVideoSurface());
	
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
void option()
{
	
	menu.m_currentPage = 3;
	menu.m_currentIndex = 0;
	
	while (menu.m_currentPage == 3 && gamestate == IN_MENU)
	{
	//Défini la position du menu à l'image
	setPosition(camera.cam.x + 400, camera.cam.y + 300);
	
	//Gestion d'événement
	 
	 SDL_Event event;
	
	

    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

            case SDL_QUIT:
                gamestate = EXIT;
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        gamestate = EXIT;
                    break;

                    case SDLK_DOWN:
                        moveDown();
                    break;

                    case SDLK_UP:
                        moveUp();
                    break;

                    case SDLK_RETURN:                        
                        switch(getCurrentIndex()) 
			{
			case 0:
				jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWPALETTE|SDL_DOUBLEBUF | SDL_FULLSCREEN);
				break;
			case 1:
				jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWPALETTE|SDL_DOUBLEBUF);
				break;
			case 2:
				//SOUNDS ON
				break;
			case 3:
				//SOUNDS OFF
				break;
			case 4:
				menu.m_currentPage = 0;
				break;
			}
                    	break;

                    default:
                    break;
                }
            break;

        }

    }
	
	//......
	//Rendu
	//Efface l'écran
	drawIm(menu.background, camera.cam.x, camera.cam.y);
	OnRender(5,3);
 
	//Mise à jour de l'écran
	SDL_Flip(SDL_GetVideoSurface());
	
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
void menuLoop()
{
	
	//Créé une énumération qui vas lister les différents choix
	enum MENU_LINK {
	MENU_GAME,
	MENU_LOAD,
	MENU_OPTION,
	MENU_QUIT
	};
	//Initialisation

 
	//On doit Initialiser SDL_ttf dans la partie Init de notre structure basique
	TTF_Init();
	
	menu.background = loadImage("graphics/bgmenu.png");
 
	//Défini la police et la taille à utiliser dans tout le menu
	setFontStyle("graphics/Fonts/Trajan Pro Regular.ttf", 66);
 
	
 
	//Défini les couleurs
	SDL_Color hoverColor = {26, 62, 137};
	SDL_Color normalColor = {150, 150, 150};
	setColor(normalColor, hoverColor);
	 
	//Ajoute les liens de notre menu
	addRow("New Game",MENU_GAME,0);
	addRow("Load Game",MENU_LOAD,0);
	addRow("Options",MENU_OPTION,0);
	addRow("Quit",MENU_QUIT,0);
	addRow("Back",0,1);
	addRow("Continue",0,2);
	addRow("Save",1,2);
	addRow("Quit",2,2);
	addRow("Fullscreen: ON",0,3);
	addRow("Fullscreen: OFF",1,3);
	addRow("Sounds: ON",2,3);
	addRow("Sounds: OFF",3,3);
	addRow("Back",4,3);
	/*......*/
	
	/*......*/
	menu.m_currentIndex = 0;
	menu.m_currentPage = 0;
	
	int game = 0;
	
	while (menu.m_currentPage == 0 && gamestate == IN_MENU)
	{
	//Défini la position du menu à l'image
	setPosition(camera.cam.x + 400, camera.cam.y + 300);
	
	
	
	//Gestion d'événement
	 
	 SDL_Event event;
	menu.m_currentPage = 0;

    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

            case SDL_QUIT:
                gamestate = EXIT;
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        gamestate = EXIT;
                    break;

                    case SDLK_DOWN:
                        moveDown();
                    break;

                    case SDLK_UP:
                        moveUp();
                    break;

                    case SDLK_RETURN:                        
                        switch(getCurrentIndex()) 
			{
			case MENU_GAME:
				newGame();
				menu.m_currentIndex = 0;
				break;
			case MENU_LOAD:
				//load_game ("save.txt");
				break;
			case MENU_OPTION:
				option();
				menu.m_currentIndex = 0;
				break;
			case MENU_QUIT:
				gamestate = EXIT;
				break;
			}
                    	break;

                    default:
                    break;
                }
            break;

        }

    }
	
	/*......*/
	//Rendu
	//Efface l'écran
	drawIm(menu.background, camera.cam.x, camera.cam.y);
	 
	//Affiche le menu
	OnRender(4,0);
 
	//Mise à jour de l'écran
	SDL_Flip(SDL_GetVideoSurface());
	
	}

}
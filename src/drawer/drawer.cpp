#include "drawer.h"
#include <iostream>
#include <stdio.h>
#include "SDL2/SDL_image.h"
//Screen dimension constants
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000 //8 * 125

Drawer::Drawer() :
    gWindow(NULL),
    gRenderer(NULL),
    gTexture(NULL),
    textures()
{
    if (!initialize()) {
        std::cout << "[DRAWER] Error initializing SDL\n";
    }
    
    textures[1] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_bishop.png");
    textures[2] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_king.png");
    textures[3] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_knight.png");
    textures[4] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_pawn.png");
    textures[5] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_queen.png");
    textures[6] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_rook.png");

    textures[0] = loadTexture("/home/mauricio/Documents/Chess/sprites/board.png");

    textures[-1] = loadTexture("/home/mauricio/Documents/Chess/sprites/black_bishop.png");
    textures[-2] = loadTexture("/home/mauricio/Documents/Chess/sprites/black_king.png");
    textures[-3] = loadTexture("/home/mauricio/Documents/Chess/sprites/black_knight.png");
    textures[-4] = loadTexture("/home/mauricio/Documents/Chess/sprites/black_pawn.png");
    textures[-5] = loadTexture("/home/mauricio/Documents/Chess/sprites/black_queen.png");
    textures[-6] = loadTexture("/home/mauricio/Documents/Chess/sprites/black_rook.png");
}

bool Drawer::initialize(){
	bool success = true;

	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO ) < 0) {
		printf("[DRAWER] SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("[DRAWER] Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if (gWindow == NULL) {
			printf("[DRAWER] Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		} else {
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if (gRenderer == NULL) {
				printf("[DRAWER] Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init( imgFlags ) & imgFlags)) {
					printf("[DRAWER] SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}
    return success;
}

void Drawer::draw(){
    //Clear screen
    SDL_RenderClear( gRenderer );

	gTexture = textures[0];

    //Render texture to screen
    SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

    //Update screen
    SDL_RenderPresent( gRenderer );
}

void Drawer::destroy(){
    //Free loaded image
	SDL_DestroyTexture( gTexture );
	gTexture = NULL;

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Drawer::loadTexture( std::string path ){
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "[DRAWER] Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "[DRAWER] Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

Drawer::~Drawer(){
    destroy();
}

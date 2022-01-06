#include "drawer.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include "SDL2/SDL_image.h"
#include "../chess/piece.h"
//Screen dimension constants
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000 
#define SQUARE_DIM 125 //8 * 125

Drawer::Drawer(Chess& chess) :
    gWindow(NULL),
    gRenderer(NULL),
    textures(),
	chess(chess)
{
    if (!initialize()) {
        std::cout << "[DRAWER] Error initializing SDL\n";
    }
    
    textures[WHITE_BISHOP] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_bishop.png");
    textures[WHITE_KING] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_king.png");
    textures[WHITE_KNIGHT] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_knight.png");
    textures[WHITE_PAWN] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_pawn.png");
    textures[WHITE_QUEEN] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_queen.png");
    textures[WHITE_ROOK] = loadTexture("/home/mauricio/Documents/Chess/sprites/white_rook.png");

    textures[0] = loadTexture("/home/mauricio/Documents/Chess/sprites/board.png");

    textures[BLACK_BISHOP] = loadTexture("/home/mauricio/Documents/Chess/sprites/black_bishop.png");
    textures[BLACK_KING] = loadTexture("/home/mauricio/Documents/Chess/sprites/black_king.png");
    textures[BLACK_KNIGHT] = loadTexture("/home/mauricio/Documents/Chess/sprites/black_knight.png");
    textures[BLACK_PAWN] = loadTexture("/home/mauricio/Documents/Chess/sprites/black_pawn.png");
    textures[BLACK_QUEEN] =loadTexture("/home/mauricio/Documents/Chess/sprites/black_queen.png");
    textures[BLACK_ROOK] = loadTexture("/home/mauricio/Documents/Chess/sprites/black_rook.png");
}

//Convertion of YCoordinate from "chess-scale" to "sdl-scale"
//y = -x + 7
int YCoordinateConvertor(int i){  
	return (-i + 7);
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

    //Render textures to screen
	render(0, 0, SCREEN_WIDTH, SCREEN_WIDTH,textures[0]);
	
	std::vector<Piece>& pieces = chess.getPieces();

	for(int i = 0; i < pieces.size(); i++){
		switch(pieces[i].getType()){
			case WHITE_BISHOP:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[WHITE_BISHOP]);
				break;
			case WHITE_KING:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[WHITE_KING]);
				break;
			case WHITE_KNIGHT:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[WHITE_KNIGHT]);
				break;
			case WHITE_PAWN:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[WHITE_PAWN]);
				break;
			case WHITE_QUEEN:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[WHITE_QUEEN]);
				break;
			case WHITE_ROOK:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[WHITE_ROOK]);
				break;
			
			case BLACK_BISHOP:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[BLACK_BISHOP]);
				break;
			case BLACK_KING:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[BLACK_KING]);
				break;
			case BLACK_KNIGHT:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[BLACK_KNIGHT]);
				break;
			case BLACK_PAWN:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[BLACK_PAWN]);
				break;
			case BLACK_QUEEN:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[BLACK_QUEEN]);
				break;
			case BLACK_ROOK:
				render(pieces[i].getCoordinateX() * SQUARE_DIM, YCoordinateConvertor(pieces[i].getCoordinateY()) * SQUARE_DIM,
					SQUARE_DIM, SQUARE_DIM, textures[BLACK_ROOK]);
				break;
		}
	}

    //Update screen
    SDL_RenderPresent( gRenderer );
}

void Drawer::destroy(){
    //Free loaded image
	for(int i = -6; i < 7; i++){
		SDL_DestroyTexture(textures[i]);
	}		

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

void Drawer::render(int x, int y, int width, int height, SDL_Texture* texture){
	SDL_Rect renderQuad = {x, y, width, height};

	SDL_RenderCopy( gRenderer, texture, NULL, &renderQuad);
}

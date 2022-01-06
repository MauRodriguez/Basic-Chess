#include "game.h"

Game::Game() : chess() ,drawer() {}

Game::~Game(){}

void Game::run(){
    bool keepRunning = true;

    //Event handler
    SDL_Event e;

    //While application is running
    while(keepRunning){
        //Handle events on queue
        while(SDL_PollEvent(&e) != 0){
            //User requests quit
            if(e.type == SDL_QUIT)
            {
                keepRunning = false;
            }
        }

        drawer.draw();
    }

}
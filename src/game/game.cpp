#include "game.h"
#include <chrono>
#include <thread>

Game::Game() : chess(1) ,drawer(chess) {}

Game::~Game(){}

void Game::run(){
    bool keepRunning = true;

    //Event handler
    SDL_Event e;
    std::chrono::milliseconds frameTime(30);

    //While application is running
    while(keepRunning){
        std::chrono::steady_clock::time_point initialTime = std::chrono::steady_clock::now();
        std::chrono::steady_clock::time_point timeSpan = initialTime + frameTime;
        //Handle events on queue
        while(SDL_PollEvent(&e) != 0){
            //User requests quit
            if(e.type == SDL_QUIT)
            {
                keepRunning = false;
            }

            if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || 
                e.type == SDL_MOUSEBUTTONUP ) {
                    
                    drawer.handleMouseEvent(&e);
            }
        }

        drawer.draw();
        std::this_thread::sleep_until(timeSpan);
    }

}
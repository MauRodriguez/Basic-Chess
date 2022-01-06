#ifndef MBUTTON_H
#define MBUTTON_H 
#include "SDL2/SDL.h"

class MButton{
private:
    //Top left position
    int mXPosition;
    int mYPosition;

    //Currently used global sprite
    int currentSprite;
public:
    //Initializes internal variables
    MButton(int currentSprite, int mXPosition, int mYPosition);

    ~MButton();

    //Handles mouse event
    void handleEvent(SDL_Event* e);

    //Shows button sprite
    void render();
};

#endif
#ifndef MBUTTON_H
#define MBUTTON_H 
#include "SDL2/SDL.h"

class MButton{
private:
    //Top left position
    int XPosition;
    int YPosition;

    //Currently used global sprite
    int currentTexture;
    bool empty;
public:
    //Initializes internal variables
    MButton(int currentTexture, int XPosition, int YPosition, int empty);

    ~MButton();

    int getXPosition();

    int getYPosition();

    int getTextureType();    
};

#endif
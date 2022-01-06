#ifndef DRAWER_H
#define DRAWER_H
#include <SDL2/SDL.h>
#include <map>
#include <vector>
#include "../chess/chess.h"
#include "mbutton.h"

class Drawer {
private:
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    std::map<char, SDL_Texture*> textures;
    Chess& chess;
    std::vector<MButton> buttons;
    int selectedPiece;
    int selectedPieceX;
    int selectedPieceY;
    bool mousePressed;
    SDL_Point mousePos;
public:
    Drawer(Chess& chess);

    ~Drawer();

    bool initialize();

    void draw();

    void render(int x, int y, int width, int height, SDL_Texture* texture);

    void destroy();

    void handleMouseEvent( SDL_Event* e);

    SDL_Texture* loadTexture(std::string path);

    void initializeButtons();
};

#endif

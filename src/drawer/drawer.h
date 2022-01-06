#ifndef DRAWER_H
#define DRAWER_H
#include <SDL2/SDL.h>
#include <map>
#include "../chess/chess.h"

class Drawer {
private:
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    std::map<char, SDL_Texture*> textures;
    Chess& chess;
public:
    Drawer(Chess& chess);

    ~Drawer();

    bool initialize();

    void draw();

    void render(int x, int y, int width, int height, SDL_Texture* texture);

    void destroy();

    SDL_Texture* loadTexture(std::string path);
};

#endif

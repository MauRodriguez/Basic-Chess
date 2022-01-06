#ifndef DRAWER_H
#define DRAWER_H
#include <SDL2/SDL.h>
#include <map>
#include "../chess/chess.h"

class Drawer {
private:
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Texture* gTexture;
    std::map<char, SDL_Texture*> textures;
public:
    Drawer();

    ~Drawer();

    bool initialize();

    void draw();

    void destroy();

    SDL_Texture* loadTexture(std::string path);
};

#endif

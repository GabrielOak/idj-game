#ifndef SPRITE_H
#define SPRITE_H

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include <iostream>

using namespace std;

class Sprite {
private:
    SDL_Texture * texture;
    int width;
    int height;
    SDL_Rect clipRect;

public:
    Sprite();
    Sprite(string file);
    ~Sprite();
    void Open(string file);
    void SetClip(int x, int y, int width, int height);
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
};

#endif
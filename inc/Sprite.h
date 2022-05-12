#ifndef SPRITE_H
#define SPRITE_H

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#define SPRITE_TYPE "Sprite"

#include <iostream>
#include "SDL_include.h"
#include "Component.h"
#include "GameObject.h"

using namespace std;

class Sprite : public Component {
private:
    SDL_Texture *texture;
    int width;
    int height;
    SDL_Rect clipRect;

public:
    Sprite(GameObject &gameObject);
    Sprite(GameObject &gameObject, string file);
    ~Sprite() override;
    void Open(string file);
    void SetClip(int x, int y, int width, int height);
    void Render() override;
    int GetWidth();
    int GetHeight();
    bool IsOpen();
    void Update(float dt) override;
    bool Is(string type) override;
};

#endif
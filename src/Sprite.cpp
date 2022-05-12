#include "Sprite.h"
#include "Game.h"
#include "GameObject.h"

Sprite::Sprite(GameObject &gameObject) : Component(gameObject){
  texture = nullptr;
}

Sprite::Sprite(GameObject &gameObject, string file) : Component(gameObject){
  texture = nullptr;
  Open(file);
}

Sprite::~Sprite(){
  if (texture != nullptr)
    SDL_DestroyTexture(texture);
}

void Sprite::Open(string file){
  if (IsOpen())
    SDL_DestroyTexture(texture);

  if (!(texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str())))
    cout << SDL_GetError() << endl;

  if (!IsOpen())
    cout << SDL_GetError() << endl;

  if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height))
    cout << SDL_GetError() << endl;

  associated.box.h = height;
  associated.box.w = width;

  SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int width, int height){
  clipRect = {x, y, width, height};
}

void Sprite::Render(){
  SDL_Rect dstRect = {(int)associated.box.x, (int)associated.box.y, (int)associated.box.w, (int)associated.box.h};

  if (SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstRect))
    cout << SDL_GetError() << endl;
}

int Sprite::GetWidth(){
  return width;
}

int Sprite::GetHeight(){
  return height;
}

bool Sprite::IsOpen(){
  return texture != nullptr;
}

void Sprite::Update(float dt) {}

bool Sprite::Is(string type){
  return type == SPRITE_TYPE;
}

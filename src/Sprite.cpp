#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(){
  texture = nullptr;
}

Sprite::Sprite(string file){
  texture = nullptr;
  Open(file);
}

Sprite::~Sprite(){
  if (texture != nullptr){
    SDL_DestroyTexture(texture);
  }
}

void Sprite::Open(string file){
  if (IsOpen()){
    SDL_DestroyTexture(texture);
  }

  if (!(texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str()))){
    cout << SDL_GetError() << endl;
  }

  if (!IsOpen()){
    cout << SDL_GetError() << endl;
  }

  if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height)){
    cout << SDL_GetError() << endl;
  }

  SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int width, int height){
  clipRect = {x, y, width, height};
}

void Sprite::Render(int x, int y){
  SDL_Rect dstRect = {x, y, clipRect.w, clipRect.h};

  if (SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstRect))
  {
    cout << SDL_GetError() << endl;
  }
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
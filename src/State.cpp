#define INCLUDE_SDL

#include "State.h"
#include "SDL_include.h"

State::State(){
  quitRequested = false;

  bg = *new Sprite();
  music = *new Music();

  LoadAssets();

  music.Play(-1);
}

void State::LoadAssets(){
  bg.Open("./img/ocean.jpg");
  music.Open("./audio/stageState.ogg");
}

void State::Update(float dt){
  if (SDL_QuitRequested()){
    quitRequested = true;
  }
}

void State::Render(){
  bg.Render(0, 0);
}

bool State::QuitRequested(){
  return quitRequested;
}
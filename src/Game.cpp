#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1024
#define TITLE "Gabriel Carvalho - 16/0120918"

#define TD 33

#include "Game.h"
#include <iostream>

Game::Game(string title, int width, int heigth){
  if (instance != nullptr){
    throw("The game has already been instantiated");
  }

  instance = this;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){
    cout << SDL_GetError() << endl;
  }

  if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) != (IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)){
    cout << SDL_GetError() << endl;
  }

  if (Mix_Init(MIX_INIT_OGG) != MIX_INIT_OGG){
    cout << SDL_GetError() << endl;
  }

  if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)){
    cout << SDL_GetError() << endl;
  }

  if (Mix_AllocateChannels(32) != 32){
    cout << SDL_GetError() << endl;
  }

  if (!(window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, heigth, 0))){
    cout << SDL_GetError() << endl;
  }

  if (!(renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED))){
    cout << SDL_GetError() << endl;
  }

  state = new State();
}

Game::~Game(){
  delete (state);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  Mix_CloseAudio();
  Mix_Quit();
  IMG_Quit();
  SDL_Quit();
}

Game *Game::instance = nullptr;

Game &Game::GetInstance(){
  if (instance != nullptr){
    return *instance;
  }

  return *new Game(TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
}

State &Game::GetState(){
  return *state;
}

SDL_Renderer *Game::GetRenderer(){
  return renderer;
}

void Game::Run(){
  while (!state->QuitRequested()){
    state->Update(0);
    state->Render();

    SDL_RenderPresent(renderer);
    SDL_Delay(TD);
  }
}
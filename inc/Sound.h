#ifndef SOUND_CLASS
#define SOUND_CLASS

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER

#define SOUND_TYPE "Sound"

#include "SDL_include.h"
#include "Component.h"

class Sound : public Component{

private:
  Mix_Chunk *chunk;
  int channel;

public:
  Sound(GameObject &associated);
  Sound(GameObject &associated, string file);
  ~Sound() override;
  void Play(int times = 1);
  void Stop();
  void Open(string file);
  bool IsOpen();
  void Update(float dt) override;
  void Render() override;
  bool Is(string type) override;
};

#endif
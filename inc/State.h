#ifndef STATE_H
#define STATE_H

#include "Sprite.h"
#include "Music.h"

class State{
private:
    Music music;
    bool quitRequested;
    vector<unique_ptr<GameObject>> objectArray;
    void Input();
    void AddObject(int mouseX, int mouseY);

public:
    State();
    ~State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
};

#endif 
#include <algorithm>
#include "GameObject.h"

GameObject::GameObject() : isDead(false) {}
GameObject::~GameObject() {
  for (auto i = components.rbegin(); i != components.rend(); ++i)
    (*i).reset();
}
void GameObject::Update(float dt){
  for (auto i = components.begin(); i != components.end(); ++i)
    (*i)->Update(dt);
}
void GameObject::Render(){
  for (auto i = components.begin(); i != components.end(); ++i)
    (*i)->Render();
}
bool GameObject::IsDead(){
  return isDead;
}
void GameObject::RequestDelete(){
  isDead = true;
}
void GameObject::AddComponent(Component *cpt){
  components.emplace_back(cpt);
}
void GameObject::RemoveComponent(Component *cpt){
  components.erase(std::remove(components.begin(), components.end(), *new unique_ptr<Component>(cpt)));
}
Component *GameObject::GetComponent(string type){
  for (auto i = components.begin(); i != components.end(); ++i){
    if ((*i)->Is(type))
      return (*i).get();
  }
  return nullptr;
}
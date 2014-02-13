#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H
#include <kos.h>
#include "GameState.h"

class IGameObject{
public:
    virtual ~IGameObject() {};
    virtual void Draw() = 0;
    virtual void Update(GAME_STATE* gs = NULL) = 0;
    virtual void Input(GAME_STATE* gs = NULL) = 0;
};

#endif
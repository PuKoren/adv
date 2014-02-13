#ifndef _APPLICATION_H
#define _APPLICATION_H
#include <kos.h>
#include <png/png.h>
#include <zlib/zlib.h>

#include "Vector3.h"
#include "GameObject.h"
#include "Texture.h"

class Application: public IGameObject{
public:
    Application();
    virtual ~Application();
    virtual void Update();
    virtual void Draw();
private:
    Texture background;
    void Input();
};
#endif